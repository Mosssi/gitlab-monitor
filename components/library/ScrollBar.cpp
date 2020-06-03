#include "ScrollBar.h"

#include <QPainter>

const int scrollBarWidth = 5;
const int maxOpacity = 150;
const int hideDelay = 1000;

ScrollBar::ScrollBar(int height, QWidget * parent) : QWidget(parent) {

    setFixedWidth(scrollBarWidth);
    setFixedHeight(height);

    showHideTimer = new QTimer(this);
    showHideTimer->setInterval(25);
    connect(showHideTimer, &QTimer::timeout, this, &ScrollBar::updateOpacity);

    hideDelayTimer = new QTimer(this);
    hideDelayTimer->setInterval(hideDelay);
    hideDelayTimer->setSingleShot(true);
    connect(hideDelayTimer, &QTimer::timeout, [this]() {
        shown = false;
        showHideTimer->start();
    });
}

void ScrollBar::paintEvent(QPaintEvent * event) {

    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    QPainterPath path;
    path.addRoundRect(0, 0, scrollBarWidth, height(), 100);

    painter.fillPath(path, QBrush(QColor(100, 100, 100, currentOpacity)));
}

void ScrollBar::setShown() {

    hideDelayTimer->stop();
    shown = true;
    showHideTimer->start();
}

void ScrollBar::setHidden() {

    if (preDragValue == -1) {
        hideDelayTimer->start();
    }
}

void ScrollBar::updateOpacity() {

    if (shown) {
        currentOpacity = qMin(maxOpacity, currentOpacity + 40);
    } else {
        currentOpacity = qMax(0, currentOpacity - 20);
    }

    if (currentOpacity == maxOpacity || currentOpacity == 0) {
        showHideTimer->stop();
    }

    setVisible(currentOpacity > 0);

    update();
}

void ScrollBar::enterEvent(QEvent * event) {

    currentOpacity = 200;
    update();
}

void ScrollBar::leaveEvent(QEvent * event) {

    currentOpacity = maxOpacity;
    update();
}

void ScrollBar::mousePressEvent(QMouseEvent * event) {

    preDragValue = QCursor::pos().y();
}

void ScrollBar::mouseReleaseEvent(QMouseEvent * event) {

    preDragValue = -1;
    if (!underMouse()) {
        hideDelayTimer->start();
    }
}

void ScrollBar::mouseMoveEvent(QMouseEvent * event) {

    emit dragged(QCursor::pos().y() - preDragValue);
    preDragValue = QCursor::pos().y();
}

