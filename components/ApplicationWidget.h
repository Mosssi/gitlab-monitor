#ifndef GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
#define GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>

#include "SystemTrayIcon.h"

class ApplicationWidget : public QWidget {
public:
    explicit ApplicationWidget(QWidget * parent = nullptr);

private:
    void setupTrayIcon();

    SystemTrayIcon * systemTrayIcon;
};


#endif //GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
