#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QDebug>
#include "DataFetcher.h"

// Function to retrieve the API key using QSettings.
QString getApiKey()
{
    // Retrieve the API key
    QString apiKey = "Z3LX94WG4A72PVHC";
    
    return apiKey;
}

int main(int argc, char *argv[])
{
    // Initialize Qt.
    QGuiApplication app(argc, argv);
    // Create QML engine to load and run the QML interface.
    QQmlApplicationEngine engine;

    engine.addImportPath("qrc:/qml");
    
    // Add the import path to the QML engine.
    QStringList importPaths = engine.importPathList();
    importPaths << "C:/Qt/6.8.2/mingw_64/qml";
    engine.setImportPathList(importPaths);
    
    // Create an instance of the DataFetcher class which contains the logic for fetching data from the API.
    DataFetcher dataFetcher;

    // Retrieve the API key from settings.
    QString apiKey = getApiKey();

    // Expose the DataFetcher instance and the default API key to QML.
    // These lines make C++ objects and data available to QML as global properties.
    engine.rootContext()->setContextProperty("dataFetcher", &dataFetcher);
    engine.rootContext()->setContextProperty("defaultApiKey", apiKey);

    // Load the QML interface from the resource system.
    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));
    if (engine.rootObjects().isEmpty()) {
        qCritical() << "Failed to load QML";
        return -1;
    }

    // Retain a reference to the root object
    // Without this reference, sometimes the engine might let go of the 
    //root object if there are no explicit references, causing the window to close immediately.
    QObject *rootObject = engine.rootObjects().first();
    qDebug() << "Root object retained:" << rootObject;

    return app.exec();
}