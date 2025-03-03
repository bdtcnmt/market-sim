import QtQuick

Window {
    id: root

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {

        property color baseColor: "red"

        anchors {
            bottom: parent.verticalCenter
            horizontalCenter: parent.horizontalCenter
            bottomMargin: 20
        }

        width: 150
        height: 50

        color: if (buttonMouseArea1.containsPress) {
                   return Qt.darker(baseColor)
               } else if (buttonMouseArea1.containsMouse) {
                       return Qt.lighter(baseColor)
               } else {
                   return baseColor
               }

        Text {
            id: buttonText1

            anchors.centerIn: parent

            text: "CLICK ME!!"
        }

        MouseArea {
            id: buttonMouseArea1

            anchors.fill: parent

            hoverEnabled: true

            onClicked: {
                console.log("I AM CLICKED")
            }
        }
    }
}