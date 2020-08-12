#ifndef GITLAB_DESKTOP_MONITOR_LOADINGWIDGET_H
#define GITLAB_DESKTOP_MONITOR_LOADINGWIDGET_H


#include <QtWidgets/QWidget>

class LoadingWidget : public QWidget {
public:
    explicit LoadingWidget(QWidget * parent = nullptr);

protected:
    void paintEvent(QPaintEvent * event) override;

    int arcPosition = 0;
};


#endif //GITLAB_DESKTOP_MONITOR_LOADINGWIDGET_H
