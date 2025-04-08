// main.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "qrc:/qml"

ApplicationWindow {
    visible: true
    width: 1200
    height: 800
    title: "Trading Simulator"

    header: ToolBar {
        contentHeight: 40
        RowLayout {
            anchors.fill: parent
            spacing: 10
            // Left group
            RowLayout {
                spacing: 20
                Label { text: "File" }
                Label { text: "Edit" }
                Label { text: "View" }
                Label { text: "Tools" }
                Label { text: "Help" }
            }
            Item { Layout.fillWidth: true }  // spacer
            // Middle (Search)
            TextField {
                placeholderText: "Search"
                Layout.preferredWidth: 200
            }
            // Right group (Trade button)
            Button {
                text: "Trade"
            }
        }
    }

    // Use a RowLayout to contain Sidebar and Dashboard
    RowLayout {
        anchors {
            top: header.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
        spacing: 0

        // Sidebar on the left
        Sidebar {
            Layout.preferredWidth: 200
            Layout.fillHeight: true
        }

        // Dashboard container now uses Layout margins to get padding
        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            // set the specific margins for each side
            Layout.leftMargin: 20
            Layout.rightMargin: 20
            Layout.topMargin: 10
            Layout.bottomMargin: 10

            // Let Dashboard fill this container
            Dashboard {
                anchors.fill: parent
            }
        }
    }
}
