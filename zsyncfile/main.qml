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

    Rectangle {
        id: rectRoot;
        width: mainWidnow.width - 5;
        height: mainWidnow.height - 5;

        BorderImage {
            id: shadowImage;
            source: "qrc:Res/window_shadow.png";
            width: mainWidnow.width;
            height: mainWidnow.height;
            border.left: 0;
            border.top: 0;
            border.right: 5;
            border.bottom: 5;
        }

        Rectangle {
        id: rectTitleBar;
        width: rectRoot.width;
        height: 30;
        color: "#4466aa"

        MouseArea {
            anchors.fill: parent;
            acceptedButtons: Qt.LeftButton;
            property int pointX;
            property int pointY;
            property variant pre;

            onDoubleClicked: {
                if (mainWidnow.modality == Qt.WindowMaximized)
                    mainWidnow.showNormal()
                else
                    mainWidnow.showMaximized();
            }

            onPressed: {
                pre = Qt.point(mouseX, mouseY);
            }

            onPositionChanged: {
                var endX = mouseX - pre.x;
                var endY = mouseY - pre.y;
                console.log(endX + ":" + endY);
                mainWidnow.x += endX;
                mainWidnow.y += endY;
            }
        }
        }

        Image {
            id: titleIcon;
            x: 10;
            y: 2;
            source: "qrc:Res/title.png";
        }

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
                }

                Rectangle {
                    width: 40;
                    height: 40;
                }
            }
        }
    }
}
