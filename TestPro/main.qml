import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import zhou.app.cn 1.0

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    SystemManager {
        id: sysManager;
    }

    TextArea {
        id: textArea;
        anchors.left: parent.left;
        anchors.top: parent.top;
        width: parent.width;
        height: 400;
    }

    Button {
        id: btnOk;
        anchors.left: parent.left;
        anchors.bottom: parent.bottom;
        text: "ok";
        onClicked: {
            console.log("clicked ok button");
            var info = sysManager.getInfo();
            console.log(info);
            textArea.append(info);
        }
    }
}

