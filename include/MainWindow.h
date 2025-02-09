#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "MarketSimulator.h"

class QTableWidget;
class QTimer;

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        // slot called by the timer to update the market simulation and GUI
        void updateMarketDisplay();

    private: 
        MarketSimulator market; // our market simulator engine
        QTableWidget *tableWidget; // widget to display stock prices
        QTimer *timer; // timer to trigger updates
};

#endif // MAIN_WINDOW_H