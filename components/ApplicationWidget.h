#ifndef GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
#define GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H

#include <functional>
#include <QtWidgets/QStackedWidget>

#include "library/Frame.h"
#include "ContextMenu.h"
#include "SystemTrayIcon.h"
#include "ConfigurationWindow.h"

class ApplicationWidget : public Frame {
public:
    explicit ApplicationWidget(QWidget * parent = nullptr);
    void logout();

private:
    void setupTrayIcon();
    void setupUi();
    void updateStyleSheet() override;
    void closeEvent(QCloseEvent * event) override;
    void keyPressEvent(QKeyEvent * event) override;

    std::function<void()> showApplication;

    QStackedWidget * stackedWidget = nullptr;

    ContextMenu * contextMenu = nullptr;
    SystemTrayIcon * systemTrayIcon = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
