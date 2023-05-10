import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QPasswordApp

Rectangle {
    id: root
    width: 952
    height: 128
    color: "#434343"
    radius: 20
    Layout.fillHeight: true
    Layout.fillWidth: true

    property alias optionLabelText: optionLabel.text
    property alias checked: optionSwitch.checked

    RowLayout {
        id: controlsLayout
        anchors.fill: parent
        Label {
            id: optionLabel
            text: "This is a switch"
            font.pixelSize: 64
            Layout.maximumWidth: root.width / 2
            Layout.fillWidth: true
        }
        Switch {
            id: optionSwitch
            Layout.fillWidth: true
            Layout.maximumWidth: root.width / 2
        }
    }
}
