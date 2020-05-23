#include "ScrollArea.h"

#include <QDebug>
#include <QScrollBar>

const int scrollBarMargin = 3;

ScrollArea::ScrollArea(QBoxLayout * layout) : QScrollArea() {

    auto * widget = new QWidget();
    widget->setLayout(layout);
    setWidget(widget);
    setWidgetResizable(true);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setContentsMargins(0, 0, 0, 0);
    setStyleSheet("");

    scrollBar = new ScrollBar(0, this);

    hideTimer = new QTimer(this);
    hideTimer->setSingleShot(true);
    hideTimer->setInterval(1000);
    connect(hideTimer, &QTimer::timeout, scrollBar, &ScrollBar::setHidden);
}

void ScrollArea::wheelEvent(QWheelEvent * event) {

    scrollBar->setShown();

    QScrollArea::wheelEvent(event);

    const int vh = viewport()->height();
    const int wh = widget()->height();
    const int sh = vh * (vh - 2 * scrollBarMargin) / wh;
    const int yp = scrollBarMargin + verticalScrollBar()->value() * (vh - sh - 2 * scrollBarMargin) / (wh - vh);

    scrollBar->setHeight(sh);
    scrollBar->move(width() - scrollBar->width() - scrollBarMargin, yp);

    hideTimer->start();
}
