#include "display.h"    // Corresponds to our declaration in display.h
#include <iostream>     // For std::cout and std::cerr
#include "json.hpp"     // The header for nlohmann/json

// Create an alias for the nlohmann::json type for convenience.
using json = nlohmann::json;

// displayStockPrice:
//   This function takes a JSON string, parses it using nlohmann/json, and then extracts and prints
//   the latest time and price from the stock data.
void displayStockPrice(const std::string& jsonData) {
    try {
        // Parse the JSON data.
        json j = json::parse(jsonData);
        
        // Assume that the API returns data under the key "Time Series (1min)".
        std::string timeSeriesKey = "Time Series (1min)";
        if (j.contains(timeSeriesKey)) {
            auto timeSeries = j[timeSeriesKey];
            if (!timeSeries.empty()) {
                // Get the first element of the time series (the most recent data point).
                auto it = timeSeries.begin();
                std::string time = it.key();
                // Extract the "1. open" value which represents the opening price.
                std::string price = it.value()["1. open"];
                std::cout << "Latest data point:\n";
                std::cout << "Time: " << time << "\n";
                std::cout << "Price: " << price << "\n";
            } else {
                std::cout << "Time series data is empty.\n";
            }
        } else {
            std::cout << "Time series key not found in JSON.\n";
        }
    } catch (json::parse_error& e) {
        // If parsing fails, display an error message.
        std::cerr << "JSON parse error: " << e.what() << "\n";
    }
}