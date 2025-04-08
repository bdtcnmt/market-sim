// Sidebar.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: sidebar
    // Layout.fillHeight: true  // Let the RowLayout manage the height
    width: 200
    color: "#2c2f36"

    Column {
        anchors {
            left: parent.left; right: parent.right; top: parent.top; bottom: parent.bottom
            // Remove or reduce anchors.margins if you want the content to be closer to the edges
            margins: 20
        }
        spacing: 20

        Label { text: "Trading Simulator"; color: "white"; font.bold: true }
        Button { text: "Portfolio" }
        Button { text: "Trading Modules" }

        Rectangle {
            color: "#3b3f48"
            radius: 10
            width: parent.width
            height: 100

            Column {
                anchors.centerIn: parent
                spacing: 5
                Label { text: "Account"; color: "white" }
                Label { text: "$120.000"; color: "white"; font.bold: true }
            }
        }
    }
}