// ChartView.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "qrc:/qml"

// Use an Item as the outer container (it won’t have its own background)
Item {
    width: 800
    height: 400

    ColumnLayout {
        anchors.fill: parent
        spacing: 10   // This 10-pixel gap separates the controls from the chart area

        // Control container: holds the search bar and refresh button.
        Rectangle {
            id: controlContainer
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            // No background color needed here unless you want one.
            color: "transparent"

            RowLayout {
                anchors.fill: parent
                spacing: 10

                SearchField {
                    id: searchBar
                }
                
                Button {
                    id: refreshButton
                    text: "Refresh"
                    anchors {
                        left: searchBar.right  // anchor left edge to search bar's right edge
                        verticalCenter: parent.verticalCenter
                    }
                    // Reduce left margin to move it closer
                    anchors.leftMargin: 4

                    onClicked: {
                        // Example refresh logic: force the image to reload.
                        chartImage.source = "qrc:/path/to/your/chart.png?" + Math.random()
                    }
                }
            }
        }

        // Chart container: the actual chart area with a blank white background and rounded corners.
        Rectangle {
            id: chartContainer
            Layout.fillWidth: true
            Layout.fillHeight: true
            radius: 10         // Rounded corners
            color: "white"     // White background for the chart area
            clip: true         // Clip the chart image to the rounded borders

            Image {
                id: chartImage
                anchors.fill: parent
                source: "qrc:/path/to/your/chart.png"   // This will be your generated chart image.
                fillMode: Image.PreserveAspectCrop
            }
        }
    }
}
