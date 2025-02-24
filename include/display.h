#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

// displayStockPrice:
//   This function is declared to parse and display stock data.
//   It takes JSON data as a string, extracts key pieces of information,
//   such as the latest stock price and its timestamp, and then prints them out.
// Parameters:
//   - jsonData: A constant reference to a std::string containing the JSON data.
void displayStockPrice(const std::string& jsonData);

#endif // DISPLAY_H