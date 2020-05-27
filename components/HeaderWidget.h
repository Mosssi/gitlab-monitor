#ifndef GITLAB_DESKTOP_MONITOR_HEADERWIDGET_H
#define GITLAB_DESKTOP_MONITOR_HEADERWIDGET_H


#include <QtWidgets/QFrame>

#include "library/Label.h"

class HeaderWidget : public QFrame {
public:
    explicit HeaderWidget(QWidget * parent = nullptr);

private:
    void setupUi();

    Label * userWelcomeLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_HEADERWIDGET_H
