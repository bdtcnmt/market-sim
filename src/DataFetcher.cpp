#include "DataFetcher.h"

#include <QNetworkRequest>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QSettings>
#include <algorithm>
#include <QCoreApplication>

DataFetcher::DataFetcher(QObject *parent)
    : QObject(parent)
{
    // Load API key from config.ini
    QSettings settings(QCoreApplication::applicationDirPath() + "/../config.ini", QSettings::IniFormat);
    m_apiKey = settings.value("API/AlphaVantageKey", "").toString();

    if(m_apiKey.isEmpty()) {
        qWarning() << "API key not found in config.ini!";
    } else {
        qDebug() << "Loaded API key from config.ini";
    }

    // Connect the finished signal to our slot.
    connect(&m_manager, &QNetworkAccessManager::finished,
            this, &DataFetcher::onNetworkReplyFinished);
}

void DataFetcher::fetchHistoricalData(const QString &stockSymbol, int duration, TimeUnit unit) {
    // Determine which API function and data set to use based on the requested time range.
    // For short durations (minutes/hours), use intraday data; for longer, use daily data.
    QString function;
    QString interval;   // Only used for intraday data.
    QString dataKey;    // The key in the JSON where the time series resides.
    QString dateFormat; // Format used to parse timestamps.

    if (unit == TimeUnit::Minutes || unit == TimeUnit::Hours) {
        function = "TIME_SERIES_INTRADAY";
        interval = "1min"; // Adjust as needed (e.g., "5min")
        dataKey = "Time Series (" + interval + ")";
        dateFormat = "yyyy-MM-dd HH:mm:ss";
    } else {
        function = "TIME_SERIES_DAILY";
        dataKey = "Time Series (Daily)";
        dateFormat = "yyyy-MM-dd";
    }

    // Build the API URL.
    QUrl url("https://www.alphavantage.co/query");
    QUrlQuery query;
    query.addQueryItem("function", function);
    query.addQueryItem("symbol", stockSymbol);
    query.addQueryItem("apikey", m_apiKey);
    if (function == "TIME_SERIES_DAILY") {
        // Optionally, use "compact" for the latest 100 data points or "full" for full-length history.
        query.addQueryItem("outputsize", "compact");
    }
    if (!interval.isEmpty())
        query.addQueryItem("interval", interval);
    url.setQuery(query);

    QNetworkRequest request(url);
    QNetworkReply *reply = m_manager.get(request);

    // Store additional request data using properties for use in the reply handler.
    reply->setProperty("stockSymbol", stockSymbol);
    reply->setProperty("duration", duration);
    reply->setProperty("unit", static_cast<int>(unit));
    reply->setProperty("dateFormat", dateFormat);
    reply->setProperty("dataKey", dataKey);
}

void DataFetcher::onNetworkReplyFinished(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        emit fetchError("Network error: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray responseData = reply->readAll();
    qDebug() << "Raw API Response:" << responseData;

    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        emit fetchError("JSON parse error: " + jsonError.errorString());
        reply->deleteLater();
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    // Check for common Alpha Vantage error messages or rate limit notes.
    if (jsonObj.contains("Error Message")) {
        emit fetchError("Alpha Vantage error: " + jsonObj["Error Message"].toString());
        reply->deleteLater();
        return;
    }
    if (jsonObj.contains("Note")) {
        emit fetchError("Alpha Vantage note: " + jsonObj["Note"].toString());
        reply->deleteLater();
        return;
    }

    // Use the "Last Refreshed" timestamp from the Meta Data as the reference time.
    QDateTime now;
    if (jsonObj.contains("Meta Data")) {
        QJsonObject metaData = jsonObj.value("Meta Data").toObject();
        QString lastRefreshedStr = metaData.value("3. Last Refreshed").toString();
        now = QDateTime::fromString(lastRefreshedStr, "yyyy-MM-dd HH:mm:ss");
    }
    if (!now.isValid()) {
        now = QDateTime::currentDateTime();
    }

    // Determine the starting time based on the requested duration.
    int totalSeconds = 0;
    TimeUnit unit = static_cast<TimeUnit>(reply->property("unit").toInt());
    int duration = reply->property("duration").toInt();
    switch (unit) {
        case TimeUnit::Minutes: totalSeconds = duration * 60; break;
        case TimeUnit::Hours:   totalSeconds = duration * 3600; break;
        case TimeUnit::Days:    totalSeconds = duration * 86400; break;
        case TimeUnit::Weeks:   totalSeconds = duration * 7 * 86400; break;
        case TimeUnit::Months:  totalSeconds = duration * 30 * 86400; break;
        case TimeUnit::Years:   totalSeconds = duration * 365 * 86400; break;
        default:                totalSeconds = duration * 60; break;
    }
    QDateTime startTime = now.addSecs(-totalSeconds);

    // Retrieve stored properties for dataKey and dateFormat.
    QString dataKey = reply->property("dataKey").toString();
    QString dateFormat = reply->property("dateFormat").toString();

    if (!jsonObj.contains(dataKey)) {
        emit fetchError("Data not found in API response. Check symbol validity or API usage limits.");
        reply->deleteLater();
        return;
    }

    QJsonObject timeSeriesObj = jsonObj.value(dataKey).toObject();
    std::vector<StockDataPoint> dataPoints;

    // Iterate through the time series and collect data points.
    for (auto it = timeSeriesObj.begin(); it != timeSeriesObj.end(); ++it) {
        QString timestampStr = it.key();
        QDateTime timestamp = QDateTime::fromString(timestampStr, dateFormat);
        // If parsing with the expected format fails, try ISODate.
        if (!timestamp.isValid())
            timestamp = QDateTime::fromString(timestampStr, Qt::ISODate);
        if (!timestamp.isValid())
            continue;

        // Skip data points that are older than the requested period.
        if (timestamp < startTime)
            continue;

        QJsonObject dataObj = it.value().toObject();
        // Use the "4. close" value as the price.
        double price = dataObj.value("4. close").toString().toDouble();
        dataPoints.push_back({ timestamp, price });
    }

    // Sort the data points in chronological order.
    std::sort(dataPoints.begin(), dataPoints.end(), [](const StockDataPoint &a, const StockDataPoint &b) {
        return a.timestamp < b.timestamp;
    });

    emit dataFetched(reply->property("stockSymbol").toString(), dataPoints);
    reply->deleteLater();
}
