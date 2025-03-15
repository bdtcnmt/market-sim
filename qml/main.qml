import QtQuick
import QtQuick.Window
import qml

Window {
    id: window
    visible: true
    title: "UntitledProject5"

    Component.onCompleted: window.showMaximized()

    MainWindow {
        id: mainScreen
        anchors.fill: parent
    }

}