#ifndef GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
#define GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H

#include <QWidget>
#include <functional>

#include "ContextMenu.h"
#include "SystemTrayIcon.h"
#include "ConfigurationWindow.h"

class ApplicationWidget : public QWidget {
public:
    explicit ApplicationWidget(QWidget * parent = nullptr);
    void showConfiguration();
    void hideConfiguration();

private:
    void setupTrayIcon();
    void setupUi();

    std::function<void()> showApplication;

    ContextMenu * contextMenu = nullptr;
    SystemTrayIcon * systemTrayIcon = nullptr;
    ConfigurationWindow * configurationWindow = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
