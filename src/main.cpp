#include <QApplication>
#include <QDebug>
#include "DataFetcher.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create our DataFetcher instance.
    DataFetcher fetcher;

    // Connect the dataFetched signal to a lambda to process and print the data.
    QObject::connect(&fetcher, &DataFetcher::dataFetched,
                     [](const QString &stockSymbol, const std::vector<StockDataPoint>& data) {
        qDebug() << "Data fetched for:" << stockSymbol;
        qDebug() << "Number of data points:" << static_cast<int>(data.size());
        for (const auto &point : data) {
            qDebug() << point.timestamp.toString("yyyy-MM-dd HH:mm:ss")
                     << "->" << point.price;
        }
    });

    // Connect the fetchError signal to a lambda to print error messages.
    QObject::connect(&fetcher, &DataFetcher::fetchError,
                     [](const QString &error) {
        qWarning() << "Error fetching data:" << error;
    });

    // For demonstration, fetch data for "AAPL" for the last 1 hour.
    // Note: Replace "AAPL" with any valid stock symbol and ensure your API key is set properly in DataFetcher.
    fetcher.fetchHistoricalData("AAPL", 1, TimeUnit::Hours);

    return app.exec();
}
