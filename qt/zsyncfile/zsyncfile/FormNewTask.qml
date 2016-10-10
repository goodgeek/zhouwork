import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
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

    Image {
        id: clock;
        x: 0;
        y: 0;
        source: "qrc:Res/pp.png";

        Image {
            id: array;
            x: 250;
            y: 10;
            source: "qrc:Res/array.png";
            transform: Rotation {
                id: arrayRotation;
                origin.x: 47;
                origin.y: 277;
                Behavior on angle {
                    SpringAnimation {
                        spring: 3.0;
                        damping: 0.3;
                    }
                }
            }
        }
    }

    Button {
        id: btn
        x: 100;
        y: 700
        text: "start";
        onClicked: {
            timer.start();
        }
    }

    Button {
        id: btn2;
        x: 210;
        y: 700;
        text: "end";
        onClicked: {
            rot.angle = 10;
        }
    }


    Timer {
        id: timer;
        repeat: true;
        interval: 200;
        onTriggered: {
            var d = new Date();
            var v2 = Qt.formatTime(d, "ss") * 5;
                arrayRotation.angle = v2;
            console.log(Qt.formatTime(d, "ss").toString());
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

