#ifndef GITLAB_DESKTOP_MONITOR_SCROLLBAR_H
#define GITLAB_DESKTOP_MONITOR_SCROLLBAR_H


#include <QTimer>
#include <QtWidgets/QWidget>

const int maxOpacity = 150;

class ScrollBar : public QWidget {
public:
    ScrollBar(int height, QWidget * parent);
    void setHeight(int height);
    void setShown();
    void setHidden();

private:
    void paintEvent(QPaintEvent * event) override;
    void updateOpacity();

    int height = 0;
    bool shown = true;
    int currentOpacity = maxOpacity;

    QTimer * showHideTimer = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_SCROLLBAR_H
