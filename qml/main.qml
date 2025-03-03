import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    id: window
    visible: true
    x: 100; y: 100
    width: 400
    height: 500
    title: "Test Window"

    Component.onCompleted: {
        console.log("Test Window loaded successfully")
    }
    Component.onDestruction: {
        console.log("Test Window is being destroyed")
    }

    Timer {
        interval: 1000000  // Keep the window open for debugging
        running: true
    }

    Text {
        anchors.centerIn: parent
        text: "Hello, World!"
    }
}
