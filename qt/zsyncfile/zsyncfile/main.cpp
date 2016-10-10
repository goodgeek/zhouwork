#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <filemanager.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<FileManager>("zhou.app.unixfiles", 1, 0, "FileManager");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
