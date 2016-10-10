import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Window 2.0

Window {
    id: mainWindow;
    title: "Unix Shadow Data";
    visible: true;
    width: 800;
    height: 600;

    property var unxShadowListModel:null;
    property string testName: "";

    Component.onCompleted: {
        console.log(testName);
    }

    Component.onDestruction: {
        console.log("destroy");
    }

    TableView {
        id: tableView;
        anchors.fill: parent;
        model: unxShadowListModel;

        TableViewColumn {
            title: "spName";
            role: "spName";
        }

        TableViewColumn {
            title: "spPwdp";
            role: "spPwdp"
        }

        TableViewColumn {
            title: "spLstchg";
            role: "spLstchg"
        }

        TableViewColumn {
            title: "spMin";
            role: "spMin"
        }
    }
}

