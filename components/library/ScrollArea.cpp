#include "ScrollArea.h"
#include "ResizeAwareWidget.h"

#include <QScrollBar>

const int scrollBarMargin = 3;
const int scrollBarWidth = 5;

ScrollArea::ScrollArea(QLayout * layout) : QScrollArea() {

    auto * widget = new ResizeAwareWidget();
    widget->setLayout(layout);
    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(Shape::NoFrame);

    connect(widget, &ResizeAwareWidget::resized, [this]() {
        updateVScrollBarPosition();
        updateHScrollBarPosition();
    });

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    vScrollBar = new ScrollBar(ScrollBar::Orientation::Vertical, scrollBarWidth, this);
    connect(vScrollBar, &ScrollBar::dragged, this, &ScrollArea::vScrollBarDrag);

    hScrollBar = new ScrollBar(ScrollBar::Orientation::Horizontal, scrollBarWidth, this);
    connect(hScrollBar, &ScrollBar::dragged, this, &ScrollArea::hScrollBarDrag);

    connect(verticalScrollBar(), &QScrollBar::valueChanged, this, &ScrollArea::updateVScrollBarPosition);
    connect(horizontalScrollBar(), &QScrollBar::valueChanged, this, &ScrollArea::updateHScrollBarPosition);
}

void ScrollArea::wheelEvent(QWheelEvent * event) {

    QScrollArea::wheelEvent(event);
    updateVScrollBarPosition();
    updateHScrollBarPosition();
}

void ScrollArea::enterEvent(QEvent * event) {

    QWidget::enterEvent(event);
    vScrollBar->setShown();
    hScrollBar->setShown();
}

void ScrollArea::leaveEvent(QEvent * event) {

    QWidget::leaveEvent(event);
    vScrollBar->setHidden();
    hScrollBar->setHidden();
}

void ScrollArea::resizeEvent(QResizeEvent * event) {

    QScrollArea::resizeEvent(event);
    updateVScrollBarPosition();
    updateHScrollBarPosition();
}

void ScrollArea::vScrollBarDrag(int diff) {

    const int vh = viewport()->height();
    const int wh = widget()->height();

    verticalScrollBar()->setValue(
            verticalScrollBar()->value() + diff * wh / vh
    );
    updateVScrollBarPosition();
}

void ScrollArea::hScrollBarDrag(int diff) {

    const int vw = viewport()->width();
    const int ww = widget()->width();

    horizontalScrollBar()->setValue(
            horizontalScrollBar()->value() + diff * ww / vw
    );
    updateHScrollBarPosition();
}

void ScrollArea::updateVScrollBarPosition() {

    const int vh = viewport()->height();
    const int wh = widget()->height();

    if (vh >= wh) {
        vScrollBar->setFixedHeight(0);
        return;
    }

    const int sh = vh * (vh - 2 * scrollBarMargin) / wh;
    const int maxYP = vh - sh - 2 * scrollBarMargin - (hScrollBar->width() == 0 ? 0 : 2 * scrollBarMargin + scrollBarWidth);
    const int yp = scrollBarMargin + verticalScrollBar()->value() * maxYP / (wh - vh);

    vScrollBar->setFixedHeight(sh);
    vScrollBar->move(width() - vScrollBar->width() - scrollBarMargin, yp);
}

void ScrollArea::updateHScrollBarPosition() {

    const int vw = viewport()->width();
    const int ww = widget()->width();

    if (vw >= ww) {
        hScrollBar->setFixedWidth(0);
        return;
    }

    const int sh = vw * (vw - 2 * scrollBarMargin) / ww;
    int maxXP = vw - sh - 2 * scrollBarMargin - (vScrollBar->height() == 0 ? 0 : 2 * scrollBarMargin + scrollBarWidth);
    const int xp = scrollBarMargin + horizontalScrollBar()->value() * maxXP / (ww - vw);

    hScrollBar->setFixedWidth(sh);
    hScrollBar->move(xp, height() - hScrollBar->height() - scrollBarMargin);
}
