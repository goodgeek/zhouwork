#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <filemanager.h>
#include <dirlistmodel.h>
#include "unixdatamanager.h"
#include "unixshadowdatalistmodel.h"
#include "processmanager.h"
#include "pthreadhandler.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<FileManager>("zhou.unix.files", 1, 0, "UnixFileManager");
    qmlRegisterType<DirListModel>("zhou.unix.dirs", 1, 0, "DirListModel");
    qmlRegisterType<UnixDataManager>("zhou.unix.data", 1, 0, "UnixDataManager");
    qmlRegisterType<UnixShadowDataListModel>("zhou.unix.shadow", 1, 0, "UnixShadowDataListModel");
    qmlRegisterType<ProcessManager>("zhou.unix.process", 1, 0, "ProcessManager");
    qmlRegisterType<PthreadHandler>("zhou.unix.thread", 1, 0, "PthreadHandler");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
