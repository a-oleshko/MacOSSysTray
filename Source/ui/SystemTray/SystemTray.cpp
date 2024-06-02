#include "SystemTray.h"

#include <QAction>
#include <QMenu>

SystemTray::SystemTray(QObject *parent) :
    QObject{parent}
{

}

SystemTray::~SystemTray()
{
    delete _menuMain;
    delete _systemTray;
}

void SystemTray::init()
{
    _systemTray = new QSystemTrayIcon(QIcon(":/img/SysTray/iconSysTray"), this);
    connect(_systemTray, &QSystemTrayIcon::activated, this, &SystemTray::slotShowMenu);
    _systemTray->setToolTip(tr("TT_NO_CONNECTION"));

    _menuMain = new QMenu();

    _actCloseApp = new QAction(tr("MENU_CLOSE_APP"));
    connect(_actCloseApp, &QAction::triggered, this, &SystemTray::slotProcessCloseAppRequest);
    _menuMain->addAction(_actCloseApp);
    _menuMain->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint |
                                        Qt::NoDropShadowWindowHint);
    _menuMain->window()->setAttribute(Qt::WA_TranslucentBackground);
}

void SystemTray::start()
{
    _systemTray->show();
}

void SystemTray::slotProcessCloseAppRequest()
{
    emit signalCloseApp(0);
}

void SystemTray::slotShowMenu(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Context:
        _menuMain->exec(QCursor::pos());
        break;
    case QSystemTrayIcon::Trigger:
        //show main widget
        break;
    default:
        break;
    }
}
