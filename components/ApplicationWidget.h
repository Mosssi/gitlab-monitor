#ifndef GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
#define GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QtWidgets/QLabel>

#include "SystemTrayIcon.h"

class ApplicationWidget : public QWidget {
public:
    explicit ApplicationWidget(QWidget * parent = nullptr);

private:
    void setupTrayIcon();
    void setupUi();

    SystemTrayIcon * systemTrayIcon = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
