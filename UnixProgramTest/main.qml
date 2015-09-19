import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true;
    width: 600;
    height: 500;
    color: "#CCCCCC";

    Rectangle {
        id: leftBar;
        width: 100;
        height: parent.height;
        color: "#99CCCC";

        Column {
            anchors.fill: parent;
            anchors.margins: 10;
            spacing: 10;
            LeftBarButton {
                id: btnOption;
                btnText: "Options";
                iconPath: "file:image/1.png";
                onBtnClicked: {
                    console.log("Pressed");
                }
            }

            LeftBarButton {
                id: btnStart;
                btnText: "Start";
            }

            LeftBarButton {
                id: btnStop;
                btnText: "Stop";
            }
        }
    }
}
