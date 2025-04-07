import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import "qrc:/qml"

ApplicationWindow {
    visible: true
    width: 1200
    height: 800
    title: "Trading Simulator"

    // 1) Add a top toolbar
    header: ToolBar {
        contentHeight: 40
        RowLayout {
            anchors.fill: parent
            spacing: 10

            // Left side (File, Edit, View, Tools, Help)
            RowLayout {
                spacing: 20
                Label { text: "File" }
                Label { text: "Edit" }
                Label { text: "View" }
                Label { text: "Tools" }
                Label { text: "Help" }
            }
            // Stretch between left group and right group
            Item { Layout.fillWidth: true }

            // Middle (Search)
            TextField {
                placeholderText: "Search"
                Layout.preferredWidth: 200
            }

            // Right side (Trade button)
            Button {
                text: "Trade"
            }
        }
    }

    // 2) The main content below the header
    Dashboard { anchors.fill: parent; anchors.topMargin: header.contentHeight }
}
