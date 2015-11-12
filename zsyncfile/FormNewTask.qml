import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Window 2.0

Window {
    id: mainWindow;
    title: "Add New Task";
    width: 800;
    height: 500;
    visible: true;
    property variant dataModel: null;

    Component.onCompleted: {
        dataModel.getFiles("./");
    }

    ListView {
        anchors.fill: parent;

        /*
        model: ListModel {
            ListElement {
                name: "Jack barwarll";
                size: "10";
            }
            ListElement {
                name: "wangweiqing";
                size: "20";
            }
        }
        */
        model: dataModel;

        delegate: Rectangle {
            width: mainWindow.width;
            height: 80;
            border.width: 1;
            color: "green";

            Row {
                spacing: 100;
                anchors.fill: parent;

                Text {
                    id: textName;
                    anchors.verticalCenter: parent.verticalCenter;
                    text: fileName;
                }
                Text {
                    anchors.verticalCenter: parent.verticalCenter;
                    text: fileSize;
                }
            }
        }
    }
}

