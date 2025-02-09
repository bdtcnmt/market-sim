#include "MainWindow.h"
#include <QTableWidget>
#include <QVBoxLayout>
#include <QTimer>
#include <QHeaderView>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), tableWidget(nullptr), timer(nullptr) {
    // create a central widget and layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // create a table widget with 3 rows and 2 columns
    tableWidget = new QTableWidget(3, 2, this);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Stock" << "Price");
    tableWidget->verticalHeader()->setVisible(false);

    // set stock names
    tableWidget->setItem(0, 0, new QTableWidgetItem("Stock A"));
    tableWidget->setItem(1, 0, new QTableWidgetItem("Stock B"));
    tableWidget->setItem(2, 0, new QTableWidgetItem("Stock C"));

    // initialize prices in the table (the second column)
    for (int i = 0; i < 3; ++i) {
        tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(market.getPrice(i), 'f', 2)));
    }

    layout->addWidget(tableWidget);
    setCentralWidget(centralWidget);
    setWindowTitle("Market Simulator");

    // create a QTimer to update the simulation every second (1000 ms)
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateMarketDisplay);
    timer->start(1000);
}

MainWindow::~MainWindow() {
    // Qt cleans up child widgets automatically
}

void MainWindow::updateMarketDisplay() {
    // update our market simulation
    market.updateMarket();

    // refresh the table with new prices
    for (int i = 0; i < 3; ++i) {
        double price = market.getPrice(i);
        tableWidget->item(i, 1)->setText(QString::number(price, 'f', 2));
    }
}