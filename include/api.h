#ifndef API_H
#define API_H

#include <string>

// fetchStockData:
//   This function is declared here so that other parts of your program can call it.
//   It is responsible for fetching stock data from an external API.
// Parameters:
//   - symbol: A constant reference to a std::string containing the stock symbol (e.g., "AAPL").
//   - interval: A constant reference to a std::string indicating the time interval (e.g., "1min").
//   - apiKey: A constant reference to a std::string for the API key used for authentication.
// Returns:
//   A std::string containing the JSON data fetched from the API.
std::string fetchStockData(const std::string& symbol, const std::string& interval, const std::string& apiKey);

#endif // API_H