#ifndef APPINSTANCE_H
#define APPINSTANCE_H

#include <QApplication>
#include <QProxyStyle>

class SystemTray;
class MainWindow;

class AppInstance: public QApplication
{
    Q_OBJECT
private:
    MainWindow *_widgetMain{nullptr};
    SystemTray *_widgetSysTray{nullptr};

public:
    AppInstance(int &argc, char **argv);
    ~AppInstance();

    void initApp();

    void startApp();

public slots:
    void slotCloseApp(int code);
};

class StyleNoFocusRect : public QProxyStyle
{
public:
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget) const
    {
        if (element == QStyle::PE_FrameFocusRect) return;

        QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
};

#endif // APPINSTANCE_H
