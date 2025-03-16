import QtQuick
import QtQuick.Controls
import qml

ApplicationWindow {
    id: window
    visible: true
    title: qsTr("Market Simulator")

    Component.onCompleted: window.showMaximized()

    menuBar: CustomMenuBar {}

    MainWindow {
        id: mainScreen
        anchors.fill: parent
    }

}