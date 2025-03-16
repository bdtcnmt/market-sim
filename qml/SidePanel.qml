import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: sidePanel
    // Default appearance for the side panel.
    color: "white"
    implicitWidth: 400
    // These layout properties serve as defaults.
    Layout.preferredWidth: implicitWidth
    Layout.minimumWidth: 200
    Layout.fillHeight: true

    // You can add additional content for your side panel here:
    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10
        Label { text: "Side Panel" }
        Button { text: "Portfolio" }
        Button { text: "Trading Modules" }
        // etc.
    }
}