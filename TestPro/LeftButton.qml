import QtQuick 2.0

Rectangle {
    id: btnleft;
    width: 200
    height: 62
    color: "#739097"
    border.width: 1;
    property string btnText: "";
    signal btnClicked();

    Text {
        anchors.centerIn: parent;
        text: btnText;
    }

    MouseArea {
        id: mouseArea;
        anchors.fill: parent;
        hoverEnabled: true;

        onClicked: {
            btnClicked();
        }

        onEntered: {
            //console.log("enter button");
        }

        onExited: {
            //console.log("leave button");
        }
    }

    states: [
        State {
            name: "normalState";
            when: mouseArea.pressed;
            PropertyChanges {
                target: btnleft;
                color: "#0099CC";
            }
        }
    ]

    transitions: [
        Transition {
            ColorAnimation {
                to: "#0099CC"
                duration: 1000;
            }
        }
    ]
}

