#ifndef GITLAB_DESKTOP_MONITOR_HEADERWIDGET_H
#define GITLAB_DESKTOP_MONITOR_HEADERWIDGET_H


#include "library/Label.h"
#include "library/Frame.h"

class HeaderWidget : public Frame {
public:
    explicit HeaderWidget(QWidget * parent = nullptr);

private:
    void setupUi();
    void updateStyleSheet() override;

    Label * userWelcomeLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_HEADERWIDGET_H
