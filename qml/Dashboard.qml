// Dashboard.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    anchors.fill: parent

    // parent container provide the padding
    ColumnLayout {
        anchors.fill: parent
        spacing: 10 // controls gap between ChartView and InfoPanel

        // ChartView: The chart takes up all available space.
        ChartView {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        InfoPanel {
            Layout.fillWidth: true
            Layout.preferredHeight: 100
        }
    }
}
