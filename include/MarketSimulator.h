#ifndef MARKET_SIMULATOR_H
#define MARKET_SIMULATOR_H

#include <vector>

class MarketSimulator {
    private:
        std::vector<double> stockPrices;

    public:
        MarketSimulator();

        // update market: simulate price change for each stock
        void updateMarket();

        // get stock price by index (use by GUI)
        double getPrice(int index) const;
};

#endif // MARKET_SIMULATOR_H