#include "ScrollArea.h"

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
}

void ScrollArea::wheelEvent(QWheelEvent * event) {

    QScrollArea::wheelEvent(event);

    const int vh = viewport()->height();
    const int wh = widget()->height();

    if (vh >= wh) {
        return;
    }

    const int sh = vh * (vh - 2 * scrollBarMargin) / wh;
    const int yp = scrollBarMargin + verticalScrollBar()->value() * (vh - sh - 2 * scrollBarMargin) / (wh - vh);

    scrollBar->setFixedHeight(sh);
    scrollBar->move(width() - scrollBar->width() - scrollBarMargin, yp);
}

void ScrollArea::enterEvent(QEvent * event) {

    QWidget::enterEvent(event);
    scrollBar->setShown();
}

void ScrollArea::leaveEvent(QEvent * event) {

    QWidget::leaveEvent(event);
    scrollBar->setHidden();
}
