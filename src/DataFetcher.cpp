#include "DataFetcher.h"
#include "api.h"        // Your existing function: fetchStockData
#include "json.hpp"     // nlohmann/json for parsing
#include <string>

using json = nlohmann::json;

DataFetcher::DataFetcher(QObject *parent) : QObject(parent)
{
}

QString DataFetcher::fetchData(const QString &symbol, const QString &timeframe, const QString &apiKey)
{
    // Convert QML/QString types to std::string
    std::string stdSymbol = symbol.toStdString();
    std::string stdTimeframe = timeframe.toStdString();
    std::string stdApiKey = apiKey.toStdString();

    // Call your existing API function to get JSON data as a string.
    std::string jsonData = fetchStockData(stdSymbol, stdTimeframe, stdApiKey);

    try {
        json j = json::parse(jsonData);
        // Build the key dynamically based on the timeframe.
        std::string timeSeriesKey = "Time Series (" + stdTimeframe + ")";
        if(j.contains(timeSeriesKey)) {
            auto timeSeries = j[timeSeriesKey];
            if(!timeSeries.empty()) {
                auto it = timeSeries.begin();
                std::string time = it.key();
                std::string price = it.value()["1. open"];
                std::string result = "Latest data point:\nTime: " + time + "\nPrice: " + price;
                return QString::fromStdString(result);
            } else {
                return QString("Time series data is empty.");
            }
        } else {
            return QString("Time series key '%1' not found in JSON.")
                   .arg(QString::fromStdString(timeSeriesKey));
        }
    } catch (const std::exception &e) {
        return QString("JSON parse error: %1").arg(e.what());
    }
}