import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    id: mainRect;

    TableView {
        id: tableView;
        anchors.left: parent.left;
        anchors.top: parent.top;
        width: mainRect.width - rightBar.width;
        height: mainRect.height;
    }

    Rectangle {
        id: rightBar;
        anchors.left: tableView.right;
        anchors.top: parent.top;
        width: 200;
        height: mainRect.height;
    }
}

