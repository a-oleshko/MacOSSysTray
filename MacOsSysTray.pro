QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Source/core/AppInstance.cpp \
    Source/ui/SystemTray/SystemTray.cpp \
    Source/core/main.cpp \
    Source/ui/mainwindow.cpp

HEADERS += \
    Source/core/AppInstance.h \
    Source/ui/SystemTray/SystemTray.h \
    Source/ui/mainwindow.h

FORMS += \
    Source/ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource/img/images.qrc

macx{
    CONFIG += sdk_no_version_check
    CONFIG += app_bundle
}
