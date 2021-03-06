#ifndef GITLAB_DESKTOP_MONITOR_SCROLLBAR_H
#define GITLAB_DESKTOP_MONITOR_SCROLLBAR_H

#include <QTimer>
#include <QtWidgets/QWidget>

class ScrollBar : public QWidget {
Q_OBJECT
signals:
    void dragged(int diff);

private:
    friend class ScrollArea;

    enum class Orientation {
        Horizontal,
        Vertical,
    };

    ScrollBar(Orientation orientation, int thickness, QWidget * parent);
    void setShown();
    void setHidden();
    void paintEvent(QPaintEvent * event) override;
    void updateOpacity();
    void enterEvent(QEvent * event) override;
    void leaveEvent(QEvent * event) override;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;

    bool shown = true;
    int currentOpacity = 0;
    int preDragValue = -1;
    int thickness = 0;
    Orientation orientation;

    QTimer * showHideTimer = nullptr;
    QTimer * hideDelayTimer = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_SCROLLBAR_H
