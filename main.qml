import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: baseBackground
        color: "#F2F7FD"
        anchors.fill: parent
    }

    Label {
        id: name
        anchors.centerIn: parent
        text: qsTr("text")
        scale: 3;
    }

    ComboBox {
        width: 200
        id: comboBoxLanguage
        model: [
            "en",
            "cn"
        ]
        onCurrentTextChanged: {
            i18n.reTrans(currentText);
        }
    }
    Text {
        anchors.centerIn: parent
        text: qsTr("HaHa")
    }

}
