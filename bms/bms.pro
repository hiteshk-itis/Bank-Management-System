QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH += lib/headers/
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lib/source/forgotpasswd.cpp \
    lib/source/createclient.cpp \
    lib/source/main.cpp \
    lib/source/mainwindow.cpp \
    lib/source/loanproposal.cpp

HEADERS += \
    lib/headers/forgotpasswd.h \
    lib/headers/createclient.h \
    lib/headers/mainwindow.h \
    lib/headers/loanproposal.h

FORMS += \
    ui/loanproposal.ui \
    ui/forgotpasswd.ui \
    ui/createclient.ui \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
