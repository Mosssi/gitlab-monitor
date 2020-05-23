#include "ScrollBar.h"

#include <QPainter>

const int scrollBarWidth = 5;
const int maxOpacity = 150;

ScrollBar::ScrollBar(int height, QWidget * parent) : QWidget(parent) {

    setFixedWidth(scrollBarWidth);
    setFixedHeight(height);

    showHideTimer = new QTimer(this);
    showHideTimer->setInterval(25);
    connect(showHideTimer, &QTimer::timeout, this, &ScrollBar::updateOpacity);
}

void ScrollBar::paintEvent(QPaintEvent * event) {

    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    QPainterPath path;
    path.addRoundRect(0, 0, scrollBarWidth, height(), 100);

    painter.fillPath(path, QBrush(QColor(100, 100, 100, currentOpacity)));
}

void ScrollBar::setShown() {

    shown = true;
    showHideTimer->start();
}

void ScrollBar::setHidden() {

    shown = false;
    showHideTimer->start();
}

void ScrollBar::updateOpacity() {

    if (shown) {
        currentOpacity = qMin(maxOpacity, currentOpacity + 60);
    } else {
        currentOpacity = qMax(0, currentOpacity - 20);
    }

    if (currentOpacity == maxOpacity || currentOpacity == 0) {
        showHideTimer->stop();
    }

    update();
}
