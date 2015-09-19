import QtQuick 2.0

Rectangle {
    id: leftBenRect;
    width: 70;
    height: 70;
    color: "#CCCC33";
    radius: 5;
    property string btnText: "";
    property string iconPath: "";
    signal btnClick();

    MouseArea {
        id: mouseArea;
        anchors.fill: parent;
        hoverEnabled: true;
        onEntered: {
            leftBenRect.state = "horverState";
        }

        onClicked: {
            btnClick();
            console.log("Pressed");
        }

        onExited: {
            leftBenRect.state = "normalState";
        }
    }

    Column {
        anchors.fill: parent;
        spacing: 5;
        Image {
            id: icon
            source: iconPath;
        }

        Text {
            text: btnText;
        }
    }

    states: [
        State {
            name: "normalState"
            PropertyChanges {
                target: leftBenRect;
                color: "#CCCC33";
            }
        },
        State {
            name: "horverState"
            PropertyChanges {
                target: leftBenRect;
                color: "#FF9933";
            }
        },
        State {
            name: "clickedState"
            when: mouseArea.pressed;
            PropertyChanges {
                target: leftBenRect
                color: "#FFCC00";
            }
        }
    ]
}

