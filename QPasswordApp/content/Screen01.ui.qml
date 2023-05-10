

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QPasswordApp
import passwordModule

Item {
    id: root
    width: Constants.width
    height: Constants.height

    PasswordComponent{
        id: passwordComponent
        passwordLength: passwordLengthSlider.value
        useUpperCase: uppercaseSwitch.checked
        useLowerCase: lowercaseSwitch.checked
        useNumbers: numbersSwitch.checked
        useSpecialCharacters: symbolsSwitch.checked
    }


    ColumnLayout {
        id: appLayout
        anchors.fill: parent
        anchors.rightMargin: 64
        anchors.leftMargin: 64

        RowLayout {
            id: titleLayout
            Layout.maximumHeight: 512
            Layout.maximumWidth: appLayout.width
            Layout.minimumHeight: 256
            Layout.fillHeight: true
            Layout.fillWidth: true
            Image {
                id: appLogo
                source: "images/qtLogo.png"
                Layout.fillHeight: true
                Layout.rightMargin: 64
                Layout.leftMargin: 64
                Layout.fillWidth: true
                fillMode: Image.PreserveAspectFit
            }
            Label {
                id: appTitle
                text: "QPassword"
                font.pixelSize: 64
                horizontalAlignment: Text.AlignHCenter
                Layout.leftMargin: 32
                Layout.rightMargin: 32
                Layout.fillWidth: false
            }
        }

        SwitchComponent {
            id: uppercaseSwitch
            Layout.maximumWidth: appLayout.width
            Layout.maximumHeight: 128
            Layout.minimumHeight: 128
            Layout.fillHeight: true
            Layout.fillWidth: true
            optionLabelText: "Include Uppercase"
        }
        SwitchComponent {
            id: lowercaseSwitch
            Layout.maximumWidth: appLayout.width
            Layout.maximumHeight: 128
            Layout.minimumHeight: 128
            Layout.fillHeight: true
            Layout.fillWidth: true
            optionLabelText: "Include Lowercase"
        }
        SwitchComponent {
            id: numbersSwitch
            Layout.maximumWidth: appLayout.width
            Layout.maximumHeight: 128
            Layout.minimumHeight: 128
            Layout.fillHeight: true
            Layout.fillWidth: true
            optionLabelText: "Include Numbers"
        }
        SwitchComponent {
            id: symbolsSwitch
            Layout.maximumWidth: appLayout.width
            Layout.maximumHeight: 128
            Layout.minimumHeight: 128
            Layout.fillHeight: true
            Layout.fillWidth: true
            optionLabelText: "Include Symbols"
        }
        ColumnLayout {
            id: passwordLengthLayout
            Layout.maximumWidth: appLayout.width
            Layout.maximumHeight: 128
            Layout.minimumHeight: 128
            Layout.fillHeight: true
            Layout.fillWidth: true
            Label {
                id: passwordLengthLabel
                text: qsTr("Password length: " + passwordLengthSlider.value)
                font.pixelSize: 32
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
            Slider {
                id: passwordLengthSlider
                Layout.fillHeight: true
                Layout.fillWidth: true

                stepSize: 1
                from: 5
                to: 20
                value: 5
            }
        }

        Button {
            id: generatePasswordButton
            text: qsTr("Generate Password")
            font.pixelSize: 48
            Layout.rightMargin: 128
            Layout.leftMargin: 128
            Layout.minimumHeight: 128
            Layout.maximumHeight: 128
            Layout.fillWidth: true

            Connections{
                function onClicked(){
                    passwordComponent.printPassword()
                    passwordText.text = passwordComponent.generatedPassword
                }
            }
        }

        Rectangle {
            id: generatedPasswordTextbox
            color: "#999999"
            radius: 20
            Layout.maximumWidth: appLayout.width
            Layout.maximumHeight: 128
            Layout.minimumHeight: 128
            Layout.fillHeight: true
            Layout.fillWidth: true
            Label {
                id: passwordText
                text: qsTr("Press Generate Password!")
                anchors.fill: parent
                font.pixelSize: 64
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
