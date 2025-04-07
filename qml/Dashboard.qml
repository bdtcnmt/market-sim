// Dashboard.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "qrc:/qml"

Rectangle {
    color: "#f0f2f5"

    RowLayout {
        anchors.fill: parent

        // Sidebar on the left (dark)
        Sidebar {
            Layout.preferredWidth: 250
            // Remove anchors.fill: parent from Sidebar.qml if present
        }

        // Main area on the right (light)
        ColumnLayout {
            spacing: 10
            Layout.fillWidth: true
            Layout.fillHeight: true

            ChartView { Layout.fillWidth: true }
            InfoPanel { Layout.fillWidth: true }
        }
    }
}