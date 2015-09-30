import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.2
import zhou.unix.data 1.0
import zhou.unix.shadow 1.0
import zhou.unix.thread 1.0

Rectangle {
    id: mainRect;

    property Component formShadowCompont: null;

    UnixDataManager {
        id: unixDataManager;
    }

    UnixShadowDataListModel {
        id: unixShadowModel;
    }

    PthreadHandler {
        id: pthreadHandler;
    }

    Loader {
        id: formLoader;
        onLoaded: {
            item.unxShadowListModel = unixShadowModel;
            item.testName = "testzhu";
        }
    }

    Loader {
        id: formProgress;
    }

    TableView {
        id: tableView;
        anchors.left: parent.left;
        anchors.top: parent.top;
        width: mainRect.width - rightBar.width;
        height: mainRect.height;
        model: unixDataManager;

        onClicked: {
            console.log(row);
        }

        TableViewColumn {
            title: "UserName";
            role: "pwName";
        }

        TableViewColumn {
            title: "Passwd";
            role: "pwPasswd";
            width: 80;
        }

        TableViewColumn {
            title: "uid";
            role: "pwUid"
            width: 80;
        }

        TableViewColumn {
            title: "gid";
            role: "pwGid";
            width: 80;
        }

        TableViewColumn {
            title: "geco";
            role: "pwGeco";
            width: 80;
        }

        TableViewColumn {
            title: "dir";
            role: "pwDir";
        }

        TableViewColumn {
            title: "shell";
            role: "pwShell";
        }
    }

    Rectangle {
        id: rightBar;
        anchors.left: tableView.right;
        anchors.top: parent.top;
        width: 200;
        height: mainRect.height;

        Column {
            anchors.top: parent.top;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.margins: 20;
            spacing: 5;

            Button {
                id: btnPasswd;
                text: "Passwd";
                style: btnStyle;
                onClicked: {
                    unixDataManager.getDataList();
                }
            }

            Button {
                id: btnShadow;
                text: "Shadow";
                style: btnStyle;
                onClicked: {
                    unixShadowModel.getShadowData();
                    formLoader.source = "";
                    formLoader.source = "FormShadowData.qml";
                    /*
                    formShadowCompont = Qt.createComponent("FormShadowData.qml");
                    formShadowCompont.createObject(null, {unxShadowListModel: unixShadowModel,
                                                   testName: "zhoujinlu"});
                                                   */
                }
            }

            Button {
                id: btnGroup;
                text: "Progress";
                style: btnStyle;
                onClicked: {
                    formProgress.source = "";
                    formProgress.source = "FormProgress.qml";
                }
            }

            Button {
                id: btnThread;
                text: "Thread";
                style: btnStyle;
                onClicked: {
                    pthreadHandler.startThread();
                }
            }
        }
    }

    Component {
        id: btnStyle;
        ButtonStyle {
            background: Rectangle {
                implicitWidth: 190;
                implicitHeight: 80;
                color: control.pressed ? "#666600" : control.hovered ? "#009966" : "#336666"
                radius: 3;
            }
            label: Text {
                text: control.text;
                verticalAlignment: Text.AlignVCenter;
                horizontalAlignment: Text.AlignHCenter;
                color: "#FFFFFF";
                font.pointSize: 18;
            }
        }
    }
}

