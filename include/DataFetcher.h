#ifndef DATAFETCHER_H
#define DATAFETCHER_H

#include <QObject>
#include <QString>

class DataFetcher : public QObject {
    Q_OBJECT
public:
    explicit DataFetcher(QObject *parent = nullptr);

    // Expose a function to QML that fetches data given a symbol, timeframe, and API key.
    Q_INVOKABLE QString fetchData(const QString &symbol, const QString &timeframe, const QString &apiKey);
};

#endif // DATAFETCHER_H
