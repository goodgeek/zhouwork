import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import zhou.app.unixfiles 1.0
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0

ApplicationWindow {
    id: mainWidnow;
    title: qsTr("ZSyncFile")
    width: 970;
    height: 600;
    visible: true;
    flags: Qt.FramelessWindowHint;
    color: "transparent"

    BorderImage {
        id: shadowImage;
        anchors.centerIn: parent;
        anchors.fill: parent;
        source: "qrc:Res/bk.png";
        border.left: 1;
        border.top: 1;
        border.right: 1;
        border.bottom: 1;
    }


    Rectangle {
        id: rectRoot;
        anchors.centerIn: shadowImage;
        width: shadowImage.width-2;
        height: shadowImage.height-2;
        border.width: 1;

        //TitleBar
        Rectangle {
        id: rectTitleBar;
        width: rectRoot.width;
        height: 30;
        color: "#4466aa"

        //Mouse move
        MouseArea {
            anchors.fill: parent;
            acceptedButtons: Qt.LeftButton;
            property int startMoveX;
            property int startMoveY;

            onDoubleClicked: {
                if (mainWidnow.visibility == Window.Maximized)
                    mainWidnow.showNormal();
                else
                    mainWidnow.showMaximized();

                console.log(mainWidnow.visibility);
            }

            onPressed: {
                startMoveX = mouseX;
                startMoveY = mouseY;
            }

            onPositionChanged: {
                var endMoveX = mouseX - startMoveX;
                var endMoveY = mouseY - startMoveY;
                mainWidnow.x += endMoveX;
                mainWidnow.y += endMoveY;
            }
        }
        }

        //Icon
        Image {
            id: titleIcon;
            x: 10;
            y: 2;
            source: "qrc:Res/title.png";
        }

        Text {
            x: rectRoot.width / 2;
            y: 5;
            text: "zFile";
        }

        //Close Icon
        Image {
            id: titleClose;
            scale: 0.6;
            anchors.right: parent.right;
            anchors.top: parent.top;
            source: "qrc:Res/close.png";
            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    Qt.quit();
                }
            }
        }

        //LeftBar
        Rectangle {
            id: rectLeftBar;
            anchors.top: rectTitleBar.bottom;
            width: 50;
            height: rectRoot.height - rectTitleBar.height;
            color: "#63728f"

            Column{
                anchors.top: parent.top;
                anchors.topMargin: 10;
                anchors.horizontalCenter: parent.horizontalCenter;
                spacing: 1;
                Rectangle {
                    width: 40;
                    height: 40;
                    MouseArea {
                        anchors.fill: parent;
                        onClicked: {
                            console.log("button1 clicked");
                            stackView.clear();
                            stackView.push(view1);
                        }
                    }
                }

                Rectangle {
                    width: 40;
                    height: 40;
                    MouseArea {
                        anchors.fill: parent;
                        onClicked: {
                            stackView.clear();
                            stackView.push(view2);
                        }
                    }
                }
            }
        }

        StackView {
            id: stackView;
            anchors.top: rectTitleBar.bottom;
            anchors.left: rectLeftBar.right;
            width: rectRoot.width - rectLeftBar.width;
            height: rectRoot.height - rectTitleBar.height;
            delegate: StackViewDelegate {
                pushTransition: StackViewTransition {
                    PropertyAnimation {
                        target: view1;
                        property: "opacity";
                        from: 0;
                        to: 1;
                    }
                }
            }
        }

        Component {
            id: view1;
            Rectangle {
                width: stackView.width;
                height: stackView.height;
                color: "#8888a6"
            }
        }

        Component {
            id: view2;
            Rectangle {
                width: stackView.width;
                height: stackView.height;
                color: "#94cbec"

            }
        }
    }
}
