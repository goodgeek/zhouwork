import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

ApplicationWindow {
    id: mainWidnow;
    title: qsTr("ZSyncFile")
    width: 970;
    height: 600;
    visible: true;

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
            }
        }

        TableView {
            width: mainWidnow.width;
            height: mainWidnow.height - topRect.height;

            TableViewColumn {
                title: "Backup Type";
                role: "Local Sync";
            }

            TableViewColumn {
                title: "Source Folder";
                role: "/home/zhou"
            }

            TableViewColumn {
                title: "Size";
                role: "100g"
            }

            TableViewColumn {
                title: "Backup Folder";
                role: "/home/backup/zhou"
            }

            TableViewColumn {
                title: "Size";
                role: "100g";
            }

            TableViewColumn {
                title: "Final Sync Time";
                role: "2015-10-14";
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
