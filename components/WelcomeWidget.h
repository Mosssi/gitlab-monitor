#ifndef GITLAB_DESKTOP_MONITOR_WELCOMEWIDGET_H
#define GITLAB_DESKTOP_MONITOR_WELCOMEWIDGET_H


#include "library/Frame.h"

class WelcomeWidget : public Frame {
Q_OBJECT
public:
    explicit WelcomeWidget(QWidget * parent = nullptr);

signals:
    void serverAndTokenValidated();

private:
    void setupUi();
};


#endif //GITLAB_DESKTOP_MONITOR_WELCOMEWIDGET_H
