#include <iostream>         // Allows you to use std::cout and std::endl for output.
#include <string>           // Provides the std::string type.
#include "api.h"            // Declares the functions for fetching data from the stock API.
#include "display.h"        // Declares the functions for parsing and displaying the stock data.

int main() {
    // Define the stock symbol, interval, and your API key.
    // std::string symbol = "AAPL";
    // std::string interval = "1min";
    std::string symbol;
    std::string interval;
    std::string apiKey = "Z3LX94WG4A72PVHC";

    // Prompt the user to enter a stock symbol
    std::cout << "Enter a stock symbol: ";
    std::cin >> symbol;

    // Prompt the user to enter an interval
    std::cout << "Enter a timeframe (e.g., 1min, 5min, 15min, 30min, 60min): ";
    std::cin >> interval;

    // Fetch stock data from the API
    std::string data = fetchStockData(symbol, interval, apiKey);

    // Display the stock data
    displayStockPrice(data);

    // Return 0 to indicate the program ended successfully.
    return 0;
}