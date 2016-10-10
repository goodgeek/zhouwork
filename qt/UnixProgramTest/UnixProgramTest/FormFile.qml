import QtQuick 2.0
import QtQuick.Controls 1.4
import zhou.unix.dirs 1.0

Rectangle {
    id: formFile;
    color: "#999999";

    property string fileName: "";
    property var rectMain: null;


    Component.onCompleted: {
        console.log("Start Form");
    }

    Component.onDestruction: {
        console.log("Destory Form");
    }



    DirListModel {
        id: dirListModel;
    }

    TableView {
        id: tableView;
        anchors.top: parent.top;
        anchors.left: parent.left;

        width: formFile.width;
        height: formFile.height - 50;

        model: dirListModel;

        TableViewColumn {
            title: "FileName";
            role: "fileName";
        }

        TableViewColumn {
            title: "FileSize";
            role: "fileSize";
        }

        TableViewColumn {
            title: "FileSort";
            role: "fileSort";
        }

        TableViewColumn {
            title: "FileMode";
            role: "fileMode";
        }

        TableViewColumn {
            title: "FileUID";
            role: "fileUid";
        }

        TableViewColumn {
            title: "FileAccess";
            role: "fileAccess";
        }
    }

    Rectangle {
        id: bottomBar;
        anchors.left: formFile.left;
        anchors.bottom: formFile.bottom;
        width: formFile.width;
        height: 50;
        color: "#999999";

        Keys.enabled: true;
        Keys.onReturnPressed: {
            dirListModel.getDirList(textPathName.text.trim());
        }

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
                id: btnGetFileList;
                text: "GetFileList";
                onClicked: {
                    dirListModel.getDirList(textPathName.text.trim());
                }
            }

            TextField {
                id: textPathName;
                text: "/root";
                width: 200;
            }

            Button {
                id: btnFucnk;
                text: "funck";
                onClicked: {
                    dirListModel.getFunck();
                }
            }
        }
    }
}

