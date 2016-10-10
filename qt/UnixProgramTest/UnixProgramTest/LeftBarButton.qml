import QtQuick 2.0
import QtQuick.Layouts 1.1

Rectangle {
    id: btnRect;
    width: 200;
    height: 50;
    state: "normalState";

    property string iconPath: "";
    property string btnText: "";
    signal btnClicked();

    Image {
        x: 30;
        y: 10;
        source: iconPath;
    }

    Text {
        id: btnName;
        x: 80;
        y: 15;
        text: btnText;
    }

    Text {
        id: btnSelect;
        x: 190;
        y: 15;
        text: "<";
    }

    MouseArea {
        id: mouseArea;
        anchors.fill: parent;
        hoverEnabled: true;

        onEntered: {
            btnRect.state = "horverStated";
        }

        onClicked: {
            btnClicked();
            btnAnimation.start();
        }

        onExited: {
            btnRect.state = "normalState";
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
            when: mouseArea.pressed;
            PropertyChanges {
                target: btnRect;
                color: "#999966";
            }
        }
    ]

    SpringAnimation {
        id: btnAnimation;
        properties: "y";
        to: btnName.y + 50;
        duration: 1000;
        spring: 2;
        damping: 0.2;
    }
}

