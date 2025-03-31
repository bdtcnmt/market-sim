#ifndef CHARTGENERATOR_H
#define CHARTGENERATOR_H

#include <QObject>
#include <QString>

class ChartGenerator : public QObject
{
    Q_OBJECT
    
public:
    explicit ChartGenerator(QObject *parent = nullptr);

    // generates the chart using the provided data file
    Q_INVOKABLE bool generateChart(const QString &dataFile, const QString &outputFile);

signals:
    void chartGenerationSucceeded(const QString &dataFile, const QString &outputFile);
    void chartGenerationFailed(const QString &error);
};

#endif // CHARTGENERATOR_H