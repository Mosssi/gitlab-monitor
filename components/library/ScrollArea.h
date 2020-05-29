#ifndef GITLAB_DESKTOP_MONITOR_SCROLLAREA_H
#define GITLAB_DESKTOP_MONITOR_SCROLLAREA_H


#include <QtWidgets/QScrollArea>
#include <QtGui/QScrollEvent>
#include <QTimer>
#include <QtWidgets/QLayout>

#include "ScrollBar.h"

class ScrollArea : public QScrollArea {
public:
    explicit ScrollArea(QLayout * layout);

private:
    void wheelEvent(QWheelEvent * event) override;
    void leaveEvent(QEvent * event) override;
    void enterEvent(QEvent * event) override;
    void resizeEvent(QResizeEvent * event) override;

    ScrollBar * scrollBar = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_SCROLLAREA_H
