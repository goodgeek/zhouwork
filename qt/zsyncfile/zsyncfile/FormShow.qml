import QtQuick 2.0

Rectangle {
    id: rootRect;
    width: 800;
    height: 700;
    color: "gray";

    Rectangle {
        width: rootRect.width;
        height: 80;
        color: "green";
    }
}

