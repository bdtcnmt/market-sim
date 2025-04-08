// InfoPanel.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    color: "white"
    height: 100
    radius: 10 // this makes the corners rounded

    Row {
        anchors.centerIn: parent
        spacing: 50

        Column {
            Label { text: "Open"; font.bold: true }
            Label { text: "299.15" }
        }
        Column {
            Label { text: "Close"; font.bold: true }
            Label { text: "301.98" }
        }
        Column {
            Label { text: "High"; font.bold: true }
            Label { text: "305.32" }
        }
        Column {
            Label { text: "Dividend Yield"; font.bold: true }
            Label { text: "1.42%" }
        }
        Column {
            Label { text: "P/E Ratio"; font.bold: true }
            Label { text: "30.98" }
        }
    }
}