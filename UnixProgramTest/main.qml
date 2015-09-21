import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: mainWidnow;
    visible: true;
    title: "Unix Show"
    width: 800;
    height: 500;
    color: "#CCCCCC";

    FormConfig {
        id: formConfig;
    }

    FormFile {
        id: formFile;
    }

    function setButton() {
    }

    //Left Bar
    Rectangle {
        id: leftBar;
        anchors.top: parent.top;
        anchors.left: parent.left;
        width: 200;
        height: mainWidnow.height;
        color: "#3d6fa0"

        focus: true;
        Keys.enabled: true;
        Keys.onEscapePressed: {
            Qt.quit();
        }

        Column {
            anchors.fill: parent;
            spacing: 1;

            LeftBarButton {
                id: btnOption;
                btnText: "Options";
                iconPath: "qrc:res/configure.png";
                onBtnClicked: {
                    stackView.clear();
                    stackView.push(formConfig);
                }
            }

            LeftBarButton {
                id: btnStart;
                iconPath: "qrc:res/files.png";
                btnText: "Start";
                onBtnClicked: {
                    stackView.clear();
                    stackView.push(formFile);
                }
            }

            LeftBarButton {
                id: btnStop;
                iconPath: "qrc:res/computer.png";
                btnText: "Stop";
            }
        }
    }

    // Main Window
    StackView {
        id: stackView;
        anchors.top: parent.top;
        anchors.left: leftBar.right;
        width: mainWidnow.width - leftBar.width;
        height: mainWidnow.height;
        initialItem: formConfig;

    }
}
