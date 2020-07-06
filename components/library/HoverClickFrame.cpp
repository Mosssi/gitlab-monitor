#include "HoverClickFrame.h"

HoverClickFrame::HoverClickFrame(QWidget * parent, bool pressEnabled) : Frame(parent), pressEnabled(pressEnabled) {

    setBackgroundColor(normalColor);
}

void HoverClickFrame::mousePressEvent(QMouseEvent * event) {

    QWidget::mousePressEvent(event);
    if (pressEnabled) {
        setBackgroundColor(pressColor);
    }
}

void HoverClickFrame::mouseReleaseEvent(QMouseEvent * event) {

    QWidget::mouseReleaseEvent(event);
    if (pressEnabled) {
        setBackgroundColor(hoverColor);
        emit clicked();
    }
}

void HoverClickFrame::enterEvent(QEvent * event) {

    QWidget::enterEvent(event);
    setBackgroundColor(hoverColor);
}

void HoverClickFrame::leaveEvent(QEvent * event) {

    QWidget::leaveEvent(event);
    setBackgroundColor(normalColor);
}