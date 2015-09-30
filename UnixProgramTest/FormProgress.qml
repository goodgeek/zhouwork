import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Window 2.0
import zhou.unix.process 1.0

Window {
    id: mainRect;
    title: "Progress Window";
    visible: true;
    width: 800;
    height: 500;
    color: "#CCCCCC";

    ProcessManager {
        id: processManager;
        onSetMessage: {
            textArea.append(mesg);
        }
    }

    TextArea {
        id: textArea;
        anchors.left: parent.left;
        anchors.top: parent.top;
        width: mainRect.width;
        height: mainRect.height - 100;
    }

    Button {
        id: btnStart;
        anchors.left: mainRect.left;
        anchors.top: textArea.bottom;
        text: "Start";
        onClicked: {
            processManager.getIdInfos();
        }
    }
}

