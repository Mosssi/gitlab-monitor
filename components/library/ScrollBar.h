#ifndef GITLAB_DESKTOP_MONITOR_SCROLLBAR_H
#define GITLAB_DESKTOP_MONITOR_SCROLLBAR_H


#include <QTimer>
#include <QtWidgets/QWidget>

class ScrollBar : public QWidget {
public:
    ScrollBar(int height, QWidget * parent);
    void setShown();
    void setHidden();

private:
    void paintEvent(QPaintEvent * event) override;
    void updateOpacity();
    void enterEvent(QEvent * event) override;
    void leaveEvent(QEvent * event) override;

    bool shown = true;
    int currentOpacity = 0;

    QTimer * showHideTimer = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_SCROLLBAR_H
