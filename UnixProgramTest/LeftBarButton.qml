import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: btnRect;
    width: 70;
    height: 70;

    property string iconPath: "";
    property string btnText: "";
    signal btnClicked();

    Column {
        anchors.fill: parent;
        spacing: 10;
        Image {
            id: iconImage;
            scale: 0.1;
            //source: iconPath;
        }

        Text {
            anchors.centerIn: parent;
            text: btnText;
        }
    }

    MouseArea {
        id: mouseArea;
        hoverEnabled: true;

        onEntered: {
            state = "horverStated";
        }

        onClicked: {
            btnClicked();
            state = "clickedState";
        }

        onExited: {
            state = "normalState";
        }
    }

    states: [
        State {
            name: "normalState"
            PropertyChanges {
                target:btnRect;
                color: "#0099CC";
            }
        },
        State {
            name: "horverState"
            PropertyChanges {
                target: btnRect;
                color: "#99CC99";
            }
        },
        State {
            name: "clickedState"
            PropertyChanges {
                target: btnRect;
                color: "#999966";
            }
        }
    ]
}

