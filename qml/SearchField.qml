// SearchField.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: searchBar
    height: 30
    width: 300
    clip: true
    
    // using height/2 gives a pill-shaped rounded appearance
    radius: 10
    color: "white"
    // border.color: "#a0a0a0"
    // border.width: 1

    TextField {
        id: searchInput
        anchors.fill: parent
        placeholderText: "Search"
        // remove the default background so the custom background shows through
        background: null
        font.pixelSize: 14

        onAccepted: {
            console.log("Search triggered: ", text)
        }
    }

    Button {
        id: searchButton
        text: "🔎︎"
        hoverEnabled: false

        background: Rectangle {
            anchors.fill: parent
            color: "transparent"
            border.width: 0
            // clear any inherited states (hover, pressed, etc)
            states: []
        }
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            margins: 4
        }
        onClicked: {
            console.log("Search triggered: ", text)
        }
    }
}