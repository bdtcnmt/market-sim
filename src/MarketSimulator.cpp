#include "MarketSimulator.h"
#include "MathUtils.h"
#include <cstdlib>
#include <ctime>

MarketSimulator::MarketSimulator() {
    // seed random number generator (for demo purposes)
    srand(static_cast<unsigned>(time(0)));

    // initialize with some default prices for 3 stocks
    stockPrices = {100.0,150.0,80.0};
}

void MarketSimulator::updateMarket() {
    // update each stocks price with a random change
    for (double &price : stockPrices) {
        double change = MathUtils::randomNormal(0,1);
        price += change;
    }
}

double MarketSimulator::getPrice(int index) const {
    if (index >= 0 && index < static_cast<int>(stockPrices.size()))
        return stockPrices[index];
    return 0;
}