#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <filemanager.h>
#include <dirlistmodel.h>
#include "unixdatamanager.h"
#include "unixshadowdatalistmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<FileManager>("zhou.unix.files", 1, 0, "UnixFileManager");
    qmlRegisterType<DirListModel>("zhou.unix.dirs", 1, 0, "DirListModel");
    qmlRegisterType<UnixDataManager>("zhou.unix.data", 1, 0, "UnixDataManager");
    qmlRegisterType<UnixShadowDataListModel>("zhou.unix.shadow", 1, 0, "UnixShadowDataListModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
