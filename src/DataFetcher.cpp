#include "DataFetcher.h"

#include <QNetworkRequest>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <algorithm>

DataFetcher::DataFetcher(QObject *parent)
    : QObject(parent)
{
    // Set your API key here. Replace "demo" with your actual API key.
    m_apiKey = "demo";

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
        interval = "1min"; // You can adjust this (e.g., "5min") as needed.
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
    if (!interval.isEmpty())
        query.addQueryItem("interval", interval);
    url.setQuery(query);

    QNetworkRequest request(url);
    QNetworkReply *reply = m_manager.get(request);

    // Store additional request data using properties so we can use them in the reply handler.
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
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        emit fetchError("JSON parse error: " + jsonError.errorString());
        reply->deleteLater();
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    // Retrieve stored properties.
    QString stockSymbol = reply->property("stockSymbol").toString();
    int duration = reply->property("duration").toInt();
    TimeUnit unit = static_cast<TimeUnit>(reply->property("unit").toInt());
    QString dateFormat = reply->property("dateFormat").toString();
    QString dataKey = reply->property("dataKey").toString();

    if (!jsonObj.contains(dataKey)) {
        emit fetchError("Data not found in API response. Check symbol validity or API usage limits.");
        reply->deleteLater();
        return;
    }

    QJsonObject timeSeriesObj = jsonObj.value(dataKey).toObject();
    std::vector<StockDataPoint> dataPoints;

    // Determine the starting time based on the requested duration.
    QDateTime now = QDateTime::currentDateTime();
    int totalSeconds = 0;
    switch (unit) {
        case TimeUnit::Minutes:
            totalSeconds = duration * 60;
            break;
        case TimeUnit::Hours:
            totalSeconds = duration * 3600;
            break;
        case TimeUnit::Days:
            totalSeconds = duration * 86400;
            break;
        case TimeUnit::Weeks:
            totalSeconds = duration * 7 * 86400;
            break;
        case TimeUnit::Months:
            totalSeconds = duration * 30 * 86400; // Approximation
            break;
        case TimeUnit::Years:
            totalSeconds = duration * 365 * 86400; // Approximation
            break;
        default:
            totalSeconds = duration * 60;
            break;
    }
    QDateTime startTime = now.addSecs(-totalSeconds);

    // Iterate through the returned time series and collect data points.
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
        // For our purposes, we use the "4. close" value as the price.
        double price = dataObj.value("4. close").toString().toDouble();
        dataPoints.push_back({ timestamp, price });
    }

    // Sort data points in chronological order.
    std::sort(dataPoints.begin(), dataPoints.end(), [](const StockDataPoint &a, const StockDataPoint &b) {
        return a.timestamp < b.timestamp;
    });

    emit dataFetched(stockSymbol, dataPoints);
    reply->deleteLater();
}
