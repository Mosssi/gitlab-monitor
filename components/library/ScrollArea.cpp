#include "ScrollArea.h"

#include <QScrollBar>

const int scrollBarMargin = 3;

ScrollArea::ScrollArea(QLayout * layout) : QScrollArea() {

    auto * widget = new QWidget();
    widget->setLayout(layout);
    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(Shape::NoFrame);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scrollBar = new ScrollBar(0, this);
    connect(scrollBar, &ScrollBar::dragged, this, &ScrollArea::scrollBarDrag);
}

void ScrollArea::wheelEvent(QWheelEvent * event) {

    QScrollArea::wheelEvent(event);
    updateScrollBarPosition();
}

void ScrollArea::enterEvent(QEvent * event) {

    QWidget::enterEvent(event);
    scrollBar->setShown();
}

void ScrollArea::leaveEvent(QEvent * event) {

    QWidget::leaveEvent(event);
    scrollBar->setHidden();
}

void ScrollArea::resizeEvent(QResizeEvent * event) {

    QScrollArea::resizeEvent(event);
    updateScrollBarPosition();
}

void ScrollArea::scrollBarDrag(int diff) {

    const int vh = viewport()->height();
    const int wh = widget()->height();

    verticalScrollBar()->setValue(
            verticalScrollBar()->value() + diff * wh / vh
    );
    updateScrollBarPosition();
}

void ScrollArea::updateScrollBarPosition() {

    const int vh = viewport()->height();
    const int wh = widget()->height();

    if (vh >= wh) {
        scrollBar->setFixedHeight(0);
        return;
    }

    const int sh = vh * (vh - 2 * scrollBarMargin) / wh;
    const int yp = scrollBarMargin + verticalScrollBar()->value() * (vh - sh - 2 * scrollBarMargin) / (wh - vh);

    scrollBar->setFixedHeight(sh);
    scrollBar->move(width() - scrollBar->width() - scrollBarMargin, yp);
}
