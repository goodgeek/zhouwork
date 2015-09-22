import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    id: formFile;
    color: "#999999";

    TableView {
        id: tableView;
        anchors.top: parent.top;
        anchors.left: parent.left;

        width: formFile.width;
        height: formFile.height - 50;

        TableViewColumn {
            role: "FileName";
            title: "FileName";
        }

        TableViewColumn {
            role: "FlieSize";
            title: "FileSize";
        }

        TableViewColumn {
            role: "FileSort";
            title: "FileSort";
        }
    }

    Rectangle {
        id: bottomBar;
        anchors.left: formFile.left;
        anchors.bottom: formFile.bottom;
        width: formFile.width;
        height: 50;
        color: "#999999";

        Row {
            anchors.verticalCenter: parent.verticalCenter;
            spacing: 10;

            Button {
                id: btnSelectPath;
                text: "Select Path";
                onClicked: {

                }
            }
            Button {
                id: btn
                text: "test";
            }
        }
    }
}

