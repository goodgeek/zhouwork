import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import zhou.app.unixfiles 1.0

ApplicationWindow {
    id: mainWidnow;
    title: qsTr("ZSyncFile")
    width: 970;
    height: 600;
    visible: true;
    property Component formComponet;

    FileManager {
        id: fileManager;
    }

    Column {
        Rectangle {
            id: topRect;
            width: mainWidnow.width;
            height: 100;
            color: "#CCCCCC";
            Row {
                anchors.left: parent.left;
                anchors.leftMargin: 10;
                anchors.verticalCenter: parent.verticalCenter;
                spacing: 10;
                Button {
                    id: btnAddTask;
                    text: "Add Task";
                    style: topBtnStyle;
                    onClicked: {
                        formComponet = Qt.createComponent("FormNewTask.qml");
                        formComponet.createObject();
                    }
                }

                Button {
                    id: btnsyncAll;
                    text: "Sync All";
                    style: topBtnStyle;
                }

                Button {
                    id: btnSync;
                    text: "Sync";
                    style: topBtnStyle;
                }

                Button {
                    id: btnDelTask;
                    text: "Delete Task";
                    style: topBtnStyle;
                }
                TextField {
                    id: fileText;
                    text: "./";
                }
                Button {
                    id: btnFindFilie;
                    text: "Find File";
                    style: topBtnStyle;
                    onClicked: {
                        fileManager.getFiles(fileText.text.trim());
                    }
                }
            }
        }

        TableView {
            width: mainWidnow.width;
            height: mainWidnow.height - topRect.height;
            model: fileManager;

            TableViewColumn {
                title: "File Name";
                role: "fileName";
                width: 200;
            }

            TableViewColumn {
                title: "File Size";
                role: "fileSize"
                width: 100;
            }

            TableViewColumn {
                title: "File Sort";
                role: "fileSort";
                width: 100;
            }

            TableViewColumn {
                title: "BlockSize";
                role: "blockSize";
                width: 100;
            }

            TableViewColumn {
                title: "Block Count";
                role: "blockCount";
                width: 100;
            }

            TableViewColumn {
                title: "Modif time";
                role: "mTime";
                width: 200;
            }

            onClicked: {
                console.log(row);
            }
        }
    }

    Component {
        id: topBtnStyle;
        ButtonStyle {
            background: Rectangle {
                implicitWidth: 130;
                implicitHeight: 50;
                radius: 5;
                color: control.pressed ? "#663300" : control.hovered ? "#993333" : "#CC9966";

            }
        }
    }
}
