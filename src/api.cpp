#include "api.h"        // Corresponds to our declaration in api.h
#include <curl/curl.h>  // For libcurl functions
#include <iostream>     // For error output via std::cerr

// WriteCallback:
//   This function is used by libcurl to write received data into our std::string.
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    std::string* buffer = static_cast<std::string*>(userp);
    buffer->append(static_cast<char*>(contents), realsize);
    return realsize;
}

// fetchStockData:
//   This function constructs the API URL using the provided parameters,
//   performs an HTTP GET request using libcurl, and returns the result as a string.
std::string fetchStockData(const std::string& symbol, const std::string& interval, const std::string& apiKey) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;  // This will hold the API response

    curl = curl_easy_init();
    if (curl) {
        // Construct the API URL. Adjust the URL if your API provider differs.
        std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=" 
                          + symbol + "&interval=" + interval + "&apikey=" + apiKey;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        // Perform the request and check for errors.
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        // Cleanup to free resources.
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}