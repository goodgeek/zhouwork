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

    Component {
        id: contentDelegate;
        Item {
            id: wrapper;
            width: grid.cellWidth;
            height: grid.cellHeight;
            BorderImage {
                id: name
                source: "file"
                width: 100; height: 100
                border.left: 5; border.top: 5
                border.right: 5; border.bottom: 5
            }
            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    console.log("clicked:" + index);
                    wrapper.GridView.view.currentIndex = index;
                }
           }

           Text {
                text: fileName;
           }
        }
    }

    GridView {
        id: grid;
        anchors.fill: parent;
        cellWidth: 200;
        cellHeight: 80;

        model: dataModel;
        delegate: contentDelegate;

        focus: true;
        highlight: Rectangle {
            color: "lightsteelblue";
        }
        highlightMoveDuration: 5;
    }

    Component {
        id: dataModels;
        ListModel {
            ListElement {
                name: "Apple";
                cost: "2.45";
            }

            ListElement {
                name: "Orange";
                cost: "1.95";
            }
            ListElement {
                name: "jack";
                cost: "2.00";
            }
            ListElement {
                name: "uptime";
                cost: "3.00";
            }
        }
    }

    /*
    ListView {
        id: listView;
        anchors.fill: parent;

        focus: true;
        highlight: Rectangle {
            color: "#cccc99";
        }

        model: dataModel;
        delegate: Item {
            id: dataRow;
            width: mainWindow.width;
            height: 30;
            //border.width: 1;
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
                    id: sss;
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
    */
}

