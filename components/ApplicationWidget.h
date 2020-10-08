#ifndef GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
#define GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H

#include <QtWidgets/QStackedWidget>
#include <functional>

#include "BodyWidget.h"
#include "ConfigurationWindow.h"
#include "ContextMenu.h"
#include "SystemTrayIcon.h"
#include "library/Frame.h"

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
    void showContents();

    std::function<void()> showApplication;

    QStackedWidget * stackedWidget = nullptr;
    BodyWidget * bodyWidget = nullptr;

    ContextMenu * contextMenu = nullptr;
    SystemTrayIcon * systemTrayIcon = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
