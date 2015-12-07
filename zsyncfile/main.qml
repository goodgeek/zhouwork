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
        source: "qrc:Res/window_shadow.png";
        width: mainWidnow.width;
        height: mainWidnow.height;
        border.left: 0;
        border.top: 0;
        border.right: 2;
        border.bottom: 2;
    }


    Rectangle {
        id: rectRoot;
        width: mainWidnow.width - 5;
        height: mainWidnow.height - 5;
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
            anchors.left: parent.left;
            anchors.horizontalCenter: parent.horizontalCenter;
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
                            if (mainWidnow.modality == Qt.WindowMaximized) {
                                console.log("max");
                            } else {
                                console.log("min");
                            }
                        }
                    }
                }
            }
        }

        StackView {
            id: stackView;
            width: rectRoot.width;
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
                width: rectRoot.width - rectLeftBar.width;
                height: rectRoot.height - rectTitleBar.height;
                color: "blue";
            }
        }
    }
}
