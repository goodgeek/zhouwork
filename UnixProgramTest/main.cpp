#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <filemanager.h>
#include <dirlistmodel.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<FileManager>("zhou.unix.files", 1, 0, "UnixFileManager");
    qmlRegisterType<DirListModel>("zhou.unix.dirs", 1, 0, "DirListModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
