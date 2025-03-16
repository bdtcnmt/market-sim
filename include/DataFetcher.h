#ifndef DATAFETCHER_H
#define DATAFETCHER_H

#include <QObject>

class DataFetcher : public QObject {
    Q_OBJECT
public:
    explicit DataFetcher(QObject *parent = nullptr);

    // This method can be called from QML
    Q_INVOKABLE void searchStock(const QString &symbol);

signals:
    // Emitted when data is successfully fetched.
    void stockInfoReady(const QString &summary);
    // Emitted when an error occurs.
    void errorOccurred(const QString &error);
};

#endif // DATAFETCHER_H
