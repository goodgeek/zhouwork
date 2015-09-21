import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import zhou.unix.files 1.0

Rectangle {
    id: formRect
    color: "#999999";

    UnixFileManager {
        id: unixFileManager;
        onSetMessage: {
            textArea.append(msg)
        }
    }

    TextArea {
        id: textArea;
        width: formRect.width;
        height: formRect.height - bottomBar.height - 30;
    }

    Row {
        id: bottomBar;
        anchors.left: parent.left;
        anchors.bottom: parent.bottom;
        anchors.margins: 10;

        Button {
            id: btnMsg;
            text: "GetInfo";
            onClicked: {
                msgDialog.text = "This Program pid: " + unixFileManager.getPid();
                msgDialog.open();
            }
        }

        Button {
            id: btnOpenFile;
            text: "Open File";
            onClicked: {
                unixFileManager.openFile();
            }
        }

        Button {
            id: btnReadFile;
            text: "Read File";
            onClicked: {
                unixFileManager.readFile();
            }
        }

        Button {
            id: btnCloseFile;
            text: "Close File";
            onClicked: {

            }
        }
    }

    MessageDialog {
        id: msgDialog;
        title: "Info";
        width: 200;
        height: 80;
    }
}

