import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import zhou.app.cn 1.0

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640;
    height: 500;
    visible: true;

    SystemManager {
        id: sysManager;
        onNewInfo: {
            textArea.append(info);
        }
    }

    TextArea {
        id: textArea;
        anchors.left: parent.left;
        anchors.top: parent.top;
        width: parent.width;
        height: 400;
    }

    Row {
        anchors.left: parent.left;
        anchors.bottom: parent.bottom;
        width: parent.width;
        height: 100;
        spacing: 5;

        Button {
            id: btnOpenFile;
            text: "OpenFile";
            onClicked: {
                sysManager.openFile();
            }
        }

        Button {
            id: btnWriteFile;
            text: "WriteFile";
            onClicked: {
                sysManager.writeFile("hello world!");
            }
        }

        Button {
            id: btnReadFile;
            text: "ReadFile";
            onClicked: {
                textArea.append(sysManager.readFile());
            }
        }
        Button {
            id: btnGetFileInfo;
            text: "GetFileInfo";
            onClicked: {
                sysManager.getInfo("test.txt");
            }
        }
    }
}

