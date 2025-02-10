import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("My QML Project")

    Rectangle {
        anchors.centerIn: parent
        width: 200
        height: 50
        color: "lightblue"

        Text {
            anchors.centerIn: parent
            text: "Hello, QML!"
            font.pixelSize: 20
        }
    }
}
