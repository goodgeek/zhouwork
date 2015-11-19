import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Window 2.0

Window {
    id: mainWindow;
    title: "Add New Task";
    width: 800;
    height:800;
    visible: true;
    property variant dataModel: null;

    Component.onCompleted: {
        dataModel.getFiles("./");
    }

    Component {
        id: contentDelegate;
        Rectangle {
            id: wrapper;
            width: grid.cellWidth;
            height: grid.cellHeight;
            color: wrapper.GridView.isCurrentItem ? "#e8fff5" : "gray";

            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    console.log("clicked:" + index);
                    dataModel.onButtonClicked(index);
                    wrapper.GridView.view.currentIndex = index;
                }
           }

           Column {
               anchors.centerIn: parent;
               spacing: 5;
               Image {
                   id: icon
                   source: iconName;
                   horizontalAlignment: Image.AlignHCenter;
               }

                Text {
                    text: fileName;
                    font.pointSize: 15;
                    horizontalAlignment: Text.AlignHCenter;
                }
           }
        }
    }

    /*

    GridView {
        id: grid;
        anchors.fill: parent;
        cellWidth: 200;
        cellHeight: 200;

        model: dataModel;
        delegate: contentDelegate;

        focus: true;
        highlight: Rectangle {
            color: "lightsteelblue";
        }
        highlightMoveDuration: 5;
    }
    */

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

    ListView {
        id: listView;
        anchors.fill: parent;

        focus: true;
        highlight: Rectangle {
            color: "#cccc99";
        }
        highlightMoveDuration: 5;

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


            //Column {
                Row {
                    spacing: 200;
                    anchors.fill: parent;

                    CheckBox {
                        id: checkBox;
                        text: "select";
                        checked: dataRow.ListView.isCurrentItem ? true : false;
                    }

                    Image {
                        source: iconName;
                        scale: 0.3;
                        width: 80;
                    }

                    Text {
                        id: sss;
                        text: fileName;
                        width: 80;
                        color: dataRow.ListView.isCurrentItem ? "red" : "black";
                    }

                    Text {
                        text: fileSize;
                        width: 80;
                        horizontalAlignment: Text.AlignRight;
                        color: dataRow.ListView.isCurrentItem ? "red" : "black";
                    }
                }
            //}
        }
    }

    Button {
        id: btnAdd;
        text: "Add";
    }
}

