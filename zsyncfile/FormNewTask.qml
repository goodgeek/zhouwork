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

        focus: true;
        highlight: Rectangle {
            color: "blue";
        }

        model: dataModel;
        delegate: Rectangle {
            id: dataRow;
            width: mainWindow.width;
            height: 80;
            border.width: 1;
            //color:

            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    console.log(index);
                    dataRow.ListView.view.currentIndex = index;
                }
            }

            Row {
                spacing: 200;
                anchors.fill: parent;


                Text {
                    id: textName;
                    anchors.verticalCenter: parent.verticalCenter;
                    text: fileName;
                    color: dataRow.ListView.isCurrentItem ? "red" : "black";
                }
                Text {
                    anchors.verticalCenter: parent.verticalCenter;
                    text: fileSize;
                    color: dataRow.ListView.isCurrentItem ? "red" : "black";
                }
            }
        }
    }
}

