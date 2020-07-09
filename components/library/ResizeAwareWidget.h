#ifndef GITLAB_DESKTOP_MONITOR_RESIZEAWAREWIDGET_H
#define GITLAB_DESKTOP_MONITOR_RESIZEAWAREWIDGET_H


#include <QtWidgets/QWidget>

class ResizeAwareWidget : public QWidget {
Q_OBJECT
public:
    explicit ResizeAwareWidget(QWidget * parent = nullptr);

protected:
    void resizeEvent(QResizeEvent * event) override;

signals:
    void resized();
};


#endif //GITLAB_DESKTOP_MONITOR_RESIZEAWAREWIDGET_H
