#include "AppInstance.h"

#include "Source/ui/mainwindow.h"
#include "Source/ui/SystemTray/SystemTray.h"


AppInstance::AppInstance(int &argc, char **argv) :
    QApplication(argc, argv)
{

}

AppInstance::~AppInstance()
{

}

void AppInstance::initApp()
{
    _widgetSysTray = new SystemTray(nullptr);
    _widgetSysTray->init();


    _widgetMain = new MainWindow(nullptr);
    _widgetMain->init();
    connect(_widgetSysTray, &SystemTray::signalCloseApp,
            _widgetMain, &MainWindow::slotProcessCloseAppRequest);

    connect(_widgetMain, &MainWindow::signalCloseAppConfirmed,
            this, &AppInstance::slotCloseApp);

    this->setQuitOnLastWindowClosed(false);
}

void AppInstance::startApp()
{
    this->setStyle(new StyleNoFocusRect());

     _widgetMain->show();
    _widgetSysTray->start();

}

void AppInstance::slotCloseApp(int code)
{
    this->closeAllWindows();
    this->setQuitOnLastWindowClosed(true);
    this->exit(code);
}
