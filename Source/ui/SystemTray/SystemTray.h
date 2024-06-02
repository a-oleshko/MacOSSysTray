#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QObject>
#include <QSystemTrayIcon>

class QMenu;
class QAction;

class SystemTray : public QObject
{
    Q_OBJECT
private:
    QMenu *_menuMain{nullptr};
    QAction *_actCloseApp{};
    QSystemTrayIcon *_systemTray{nullptr};

public:
    SystemTray(QObject *parent = nullptr);
    ~SystemTray();

    void init();
    void start();

signals:
    void signalCloseApp(int code);

protected slots:
    void slotProcessCloseAppRequest();
    void slotShowMenu(QSystemTrayIcon::ActivationReason reason);
};

#endif // SYSTEMTRAY_H
