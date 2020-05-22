#ifndef GITLAB_DESKTOP_MONITOR_HEADERWIDGET_H
#define GITLAB_DESKTOP_MONITOR_HEADERWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>

class HeaderWidget : public QFrame {
public:
    explicit HeaderWidget(QWidget * parent = nullptr);

private:
    void setupUi();

    QLabel * userWelcomeLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_HEADERWIDGET_H
