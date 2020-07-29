#ifndef GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
#define GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H

#include <QWidget>
#include <functional>
#include <QtWidgets/QStackedWidget>

#include "ContextMenu.h"
#include "SystemTrayIcon.h"
#include "ConfigurationWindow.h"

class ApplicationWidget : public Frame {
public:
    explicit ApplicationWidget(QWidget * parent = nullptr);
    void showConfiguration();
    void hideConfiguration();
    void logout();
protected:
    void keyPressEvent(QKeyEvent * event) override;
protected:
    void closeEvent(QCloseEvent * event) override;
private:
    void setupTrayIcon();
    void setupUi();
    void updateStyleSheet() override;

    std::function<void()> showApplication;

    QStackedWidget * stackedWidget = nullptr;

    ContextMenu * contextMenu = nullptr;
    SystemTrayIcon * systemTrayIcon = nullptr;
    ConfigurationWindow * configurationWindow = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
