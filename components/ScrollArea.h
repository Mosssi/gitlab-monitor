#ifndef GITLAB_DESKTOP_MONITOR_SCROLLAREA_H
#define GITLAB_DESKTOP_MONITOR_SCROLLAREA_H


#include <QtWidgets/QScrollArea>
#include <QtGui/QScrollEvent>
#include <QTimer>
#include <QtWidgets/QBoxLayout>

#include "ScrollBar.h"

class ScrollArea : public QScrollArea {
public:
    explicit ScrollArea(QBoxLayout * layout);

private:
    void wheelEvent(QWheelEvent * event) override;

    ScrollBar * scrollBar = nullptr;
    QTimer * hideTimer = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_SCROLLAREA_H