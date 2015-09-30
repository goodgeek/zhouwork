TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    filemanager.cpp \
    threadfileread.cpp \
    dirlistmodel.cpp \
    unixfile.cpp \
    unixdatamanager.cpp \
    pwdobject.cpp \
    shadowdata.cpp \
    unixshadowdatalistmodel.cpp \
    processmanager.cpp \
    pthreadhandler.cpp

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
    unixfile.h \
    unixdatamanager.h \
    pwdobject.h \
    shadowdata.h \
    unixshadowdatalistmodel.h \
    processmanager.h \
    pthreadhandler.h
