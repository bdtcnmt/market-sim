#include "DataFetcher.h"
#include "api.h"  // This gives access to fetchStockData()
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QDir>

DataFetcher::DataFetcher(QObject *parent)
    : QObject(parent)
{
}

void DataFetcher::searchStock(const QString &symbol)
{
    // Choose an interval – for example "5min". In a real app, you might allow the user to set this.
    QString interval = "5min";
    
    // For simplicity, assume you have a default API key. You could also store it as a member variable.
    QString apiKey = "Z3LX94WG4A72PVHC";  // or retrieve from settings

    // Call your fetch function (which is blocking here, so consider making it asynchronous later).
    std::string result = fetchStockData(symbol.toStdString(), interval.toStdString(), apiKey.toStdString());
    QString jsonStr = QString::fromStdString(result);

    // Parse the JSON data
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &parseError);
    QString summary;

    if (parseError.error != QJsonParseError::NoError) {
        summary = "JSON parse error: " + parseError.errorString();
        emit errorOccurred(summary);
        return;
    }

    QJsonObject rootObj = doc.object();
    QJsonObject metaData = rootObj.value("Meta Data").toObject();
    QJsonObject timeSeries = rootObj.value("Time Series (" + interval + ")").toObject();

    // Get the most recent time stamp (using keys() order may not be sorted, so in production you'd sort them)
    QStringList keys = timeSeries.keys();
    if (keys.isEmpty()) {
        summary = "No time series data returned.";
        emit errorOccurred(summary);
        return;
    }

    // Assume the first key is the most recent (or sort keys to get the most recent)
    QString latestTime = keys.first();
    QJsonObject latestData = timeSeries.value(latestTime).toObject();
    QString closePrice = latestData.value("4. close").toString();

    // Build a summary string to display to the user
    summary = "Symbol: " + symbol.toUpper() + "\n"
            + "Last Updated: " + metaData.value("3. Last Refreshed").toString() + "\n"
            + "Last Close: " + closePrice + "\n";

    // Optionally, you could save the raw JSON data to a temporary file for the Python script,
    // or pass the relevant data via command-line arguments.
    // Here, we'll assume the Python script is set up to read from a file called "data.json".
    QFile file("data.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonStr.toUtf8());
        file.close();
    } else {
        qWarning() << "Failed to write data.json file";
    }

    QString currentPath = QDir::currentPath();
    QString scriptPath = QDir(currentPath).filePath("../python/generate_chart.py");
    qDebug() << "Python script path: " << scriptPath;

    // Call a Python script to generate a graph. The script should read "data.json" and output "chart.png".
    QProcess process;
    // set the working directory to the directory containing the Python script
    process.setWorkingDirectory(QDir::currentPath());
    // adjust the path to your python interpreter and script location
    QString pythonInterpreter = "C:\\Users\\Landorus\\AppData\\Local\\Programs\\Python\\Python312\\python.exe";
    process.start(pythonInterpreter, QStringList() << scriptPath);
    process.waitForFinished(); // consider running this asynchronously in production
    
    QString stdOut = process.readAllStandardOutput();
    QString stdErr = process.readAllStandardError();

    qDebug() << "Python process output:" << stdOut;
    qDebug() << "Python process error:" << stdErr;


    // emit the stock info (summary) signal
    emit stockInfoReady(summary);
}
