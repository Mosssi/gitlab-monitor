#ifndef GITLAB_DESKTOP_MONITOR_BODYWIDGET_H
#define GITLAB_DESKTOP_MONITOR_BODYWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QVBoxLayout>

class BodyWidget : public QFrame {
public:
    explicit BodyWidget(QWidget * parent = nullptr);

private:
    void setupUi();
    void updateUi();

    QVBoxLayout * mainLayout = nullptr;
    QVBoxLayout * scrollLayout = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_BODYWIDGET_H
