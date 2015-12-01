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

    Canvas {
        id: canvas;
        width: mainWindow.width;
        height: mainWindow.height;

        onPaint: {
            var ctx = getContext("2d");

            ctx.lineWidth = 1;
            ctx.strokeStyle = "blue";
            ctx.font = "20px serif";

            ctx.text("Hello World", 20, 20);
            ctx.stroke();

            ctx.save();
            ctx.translate(300, 300);
            ctx.rotate(0.3);
            ctx.text("What", 0, 0);
            ctx.stroke();
            ctx.restore();

            ctx.text("jack", 30, 30);
            ctx.stroke();

            ctx.beginPath();
            ctx.arc(300, 300, 100, 0, 10);
            ctx.stroke();
        }
    }


    /*
    Component {
        id: contentDelegate;
        Item {
            id: wrapper;
            //width: grid.cellWidth;
            //height: grid.cellHeight;
            //color: wrapper.PathView.isCurrentItem ? "#e8fff5" : "gray";
            z: PathView.zOrder;
            opacity: PathView.itemAlpha;
            scale: PathView.itemScale;

            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    console.log("clicked:" + index);
                    dataModel.onButtonClicked(index);
                    wrapper.PathView.view.currentIndex = index;
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

    PathView {
        id: pathview;
        interactive: true;
        preferredHighlightBegin: 0.5;
        preferredHighlightEnd: 0.5;
        pathItemCount: 5;

        model: dataModel;
        delegate: contentDelegate;
        path: Path {
            startX: 0;
            startY: 200;

            PathAttribute {name: "zOrder"; value: 0;}
            PathAttribute {name: "itemAlpha"; value: 0.1;}
            PathAttribute {name: "itemScale"; value: 0.6;}
            PathLine {
                x: mainWindow.width / 2;
                y: 200;
            }
            PathAttribute {name: "zOrder"; value: 1;}
            PathAttribute {name: "itemAlpha"; value: 0.8;}
            PathAttribute {name: "itemScale"; value: 3.0;}
            PathLine {
                relativeX: mainWindow.width;
                relativeY: 0;
            }
        }

        focus: true;
        Keys.onLeftPressed: decrementCurrentIndex();
        Keys.onRightPressed: incrementCurrentIndex();
    }
    */

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
    /*
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
    */
}

