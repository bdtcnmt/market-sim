#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json.hpp>

using json = nlohmann::json;

// Helper function to capture curl response
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string fetchStockData(const std::string& symbol, const std::string& interval, const std::string& apiKey) {
    std::string readBuffer;
    std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=" + symbol +
                      "&interval=" + interval + "&apikey=" + apiKey;
    
    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        CURLcode res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

void displayStockPrice(const std::string& jsonData) {
    // Parse JSON data
    auto j = json::parse(jsonData);
    // Navigate the JSON structure based on the API's response format
    // For Alpha Vantage, you might look into "Time Series (1min)" or the chosen interval key
    std::string timeSeriesKey = "Time Series (1min)";
    if (j.contains(timeSeriesKey)) {
        auto timeSeries = j[timeSeriesKey];
        // Display the most recent data point
        if (!timeSeries.empty()) {
            auto latest = timeSeries.begin();
            std::cout << "Latest data point:" << std::endl;
            std::cout << "Time: " << latest.key() << std::endl;
            std::cout << "Price: " << latest.value()["1. open"] << std::endl;
        }
    } else {
        std::cerr << "Error: Time series data not found!" << std::endl;
    }
}

int main() {
    std::string symbol = "AAPL";  // Example symbol
    std::string interval = "1min"; // Example interval
    std::string apiKey = "AlphaVantageKey=Z3LX94WG4A72PVHC";

    std::string data = fetchStockData(symbol, interval, apiKey);
    displayStockPrice(data);
    return 0;
}