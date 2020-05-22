#ifndef GITLAB_DESKTOP_MONITOR_BODYWIDGET_H
#define GITLAB_DESKTOP_MONITOR_BODYWIDGET_H


#include <QtWidgets/QFrame>

class BodyWidget : public QFrame {
public:
    explicit BodyWidget(QWidget * parent = nullptr);

private:
    void setupUi();
};


#endif //GITLAB_DESKTOP_MONITOR_BODYWIDGET_H
