#ifndef GITLAB_DESKTOP_MONITOR_WELCOMEWIDGET_H
#define GITLAB_DESKTOP_MONITOR_WELCOMEWIDGET_H

#include "library/Frame.h"
#include "library/LineEdit.h"
#include "library/PushButton.h"

class WelcomeWidget : public Frame {
Q_OBJECT
public:
    explicit WelcomeWidget(QWidget * parent = nullptr);

signals:
    void serverAndTokenValidated();

private:
    void setupUi();
    void validateServerAndToken();
    void keyReleaseEvent(QKeyEvent * event) override;

    LineEdit * serverAddressInput;
    LineEdit * tokenInput;
    PushButton * saveServerConfigsButton;
};


#endif //GITLAB_DESKTOP_MONITOR_WELCOMEWIDGET_H
