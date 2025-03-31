#include "ChartGenerator.h"
#include <QProcess>
#include <QDir>
#include <QFile>
#include <QDebug>

ChartGenerator::ChartGenerator(QObject *parent) : QObject(parent)
{    
}

bool ChartGenerator::generateChart(const QString &dataFile, const QString &outputFile)
{
    QProcess process;
    QString workingDir = QDir::currentPath();
    process.setWorkingDirectory(workingDir);

    // construct script path relative to the working directory
    QString scriptPath = QDir(workingDir).filePath("../python/generate_chart.py");
    qDebug() << "Script path: " << scriptPath;

    QString pythonInterpreter = "python";
    process.start(pythonInterpreter, QStringList() << scriptPath << dataFile << outputFile);

    if (!process.waitForFinished(10000)) { // wait for 10 seconds
        QString errorMsg = process.errorString();
        qDebug() << "Pythong script did not finish" << errorMsg;
        return false;
    }

    QString stdOut = process.readAllStandardOutput();
    QString stdErr = process.readAllStandardError();
    qDebug() << "Python process output:" << stdOut;
    qDebug() << "Python process error:" << stdErr;

    // check if the output file exists
    QFile chartFile(outputFile);
    if (chartFile.exists()) {
        qDebug() << "Chart generated at " << outputFile;
        emit chartGenerationSucceeded(dataFile, outputFile);
        return true;
    } else {
        QString err = "Chart.png was not created!";
        qDebug() << err;
        emit chartGenerationFailed(err);
        return false;
    }
}