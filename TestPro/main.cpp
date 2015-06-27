#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "systemmanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<SystemManager>("zhou.app.cn", 1, 0, "SystemManager");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
