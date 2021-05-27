QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Dijkstra.cpp \
    admin.cpp \
    date.cpp \
    designtrip.cpp \
    dreamvacation.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    modifysouvenirs.cpp \
    modifystadium.cpp \
    souvenir.cpp \
    souvenircontainer.cpp \
    stadium.cpp \
    stadiumlists.cpp \
    trips.cpp

HEADERS += \
    Dijkstra.h \
    admin.h \
    binaryTree.h \
    date.h \
    designtrip.h \
    dreamvacation.h \
    global.h \
    heap.h \
    list.h \
    mainwindow.h \
    map.h \
    modifysouvenirs.h \
    modifystadium.h \
    souvenir.h \
    souvenircontainer.h \
    stadium.h \
    stadiumlists.h \
    trips.h

FORMS += \
    admin.ui \
    dreamvacation.ui \
    mainwindow.ui \
    map.ui \
    modifysouvenirs.ui \
    modifystadium.ui \
    stadiumlists.ui \
    trips.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
