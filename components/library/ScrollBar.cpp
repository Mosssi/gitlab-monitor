#include "ScrollBar.h"

#include <QPainter>

const int maxOpacity = 150;
const int hideDelay = 1000;

ScrollBar::ScrollBar(Orientation orientation, int thickness, QWidget * parent) : QWidget(parent), orientation(orientation), thickness(thickness) {

    if (orientation == Orientation::Vertical) {
        setFixedWidth(thickness);
    } else {
        setFixedHeight(thickness);
    }

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
    if (orientation == Orientation::Vertical) {
        path.addRoundRect(0, 0, thickness, height(), 100);
    } else {
        path.addRoundRect(0, 0, width(), thickness, 100);
    }

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

    if (orientation == Orientation::Vertical) {
        preDragValue = QCursor::pos().y();
    } else {
        preDragValue = QCursor::pos().x();
    }
}

void ScrollBar::mouseReleaseEvent(QMouseEvent * event) {

    preDragValue = -1;
    if (!underMouse()) {
        hideDelayTimer->start();
    }
}

void ScrollBar::mouseMoveEvent(QMouseEvent * event) {

    if (orientation == Orientation::Vertical) {
        emit dragged(QCursor::pos().y() - preDragValue);
        preDragValue = QCursor::pos().y();
    } else {
        emit dragged(QCursor::pos().x() - preDragValue);
        preDragValue = QCursor::pos().x();
    }
}
