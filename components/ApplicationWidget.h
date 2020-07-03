#ifndef GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
#define GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H

#include <QWidget>

class ApplicationWidget : public QWidget {
public:
    explicit ApplicationWidget(QWidget * parent = nullptr);

private:
    void setupTrayIcon();
    void setupUi();
};


#endif //GITLAB_DESKTOP_MONITOR_APPLICATIONWIDGET_H
