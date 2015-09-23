TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    filemanager.cpp \
    threadfileread.cpp \
    dirlistmodel.cpp \
    unixfile.cpp

RESOURCES += qml.qrc \
    res.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    filemanager.h \
    threadfileread.h \
    dirlistmodel.h \
    unixfile.h
