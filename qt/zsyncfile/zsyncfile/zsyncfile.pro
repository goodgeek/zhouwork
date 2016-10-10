TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    filemanager.cpp \
    filemodel.cpp

RESOURCES += qml.qrc \
    image.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    filemanager.h \
    filemodel.h
