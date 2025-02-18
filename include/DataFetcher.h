#ifndef DATAFETCHER_H
#define DATAFETCHER_H

#include <QObject>
#include <vector>
#include <QString>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>

// Structure representing a single data point.
struct StockDataPoint {
    QDateTime timestamp;
    double price;
};

// Enum to specify the time unit for the duration.
enum class TimeUnit {
    Minutes,
    Hours,
    Days,
    Weeks,
    Months,
    Years
};

class DataFetcher : public QObject {
    Q_OBJECT
public:
    explicit DataFetcher(QObject* parent = nullptr);

    // Asynchronously fetch historical data for the given stock symbol.
    // 'duration' and 'unit' specify the period (e.g. last 1 hour, last 24 hours, etc.).
    // The data will be delivered via the dataFetched() signal.
    void fetchHistoricalData(const QString &stockSymbol, int duration, TimeUnit unit);

signals:
    // Emitted when data is fetched successfully.
    void dataFetched(const QString &stockSymbol, const std::vector<StockDataPoint>& data);
    // Emitted when an error occurs during fetching.
    void fetchError(const QString &errorString);

private slots:
    // Slot called when any network reply finishes.
    void onNetworkReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager m_manager;
    QString m_apiKey; // Your Alpha Vantage API key.
};

#endif // DATAFETCHER_H
