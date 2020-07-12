#include "HoverClickFrame.h"

HoverClickFrame::HoverClickFrame(QWidget * parent, bool pressEnabled) : Frame(parent), pressEnabled(pressEnabled) {

}

void HoverClickFrame::mousePressEvent(QMouseEvent * event) {

    QWidget::mousePressEvent(event);
    if (pressEnabled) {
        pressed = true;
        updateStyleSheet();
    }
}

void HoverClickFrame::mouseReleaseEvent(QMouseEvent * event) {

    QWidget::mouseReleaseEvent(event);
    if (pressEnabled) {
        pressed = false;
        emit clicked();
        updateStyleSheet();
    }
}

void HoverClickFrame::enterEvent(QEvent * event) {

    QWidget::enterEvent(event);
    hovered = true;
    updateStyleSheet();
}

void HoverClickFrame::leaveEvent(QEvent * event) {

    QWidget::leaveEvent(event);
    hovered = false;
    updateStyleSheet();
}

void HoverClickFrame::updateStyleSheet() {

    if (pressed) {
        setBackgroundColor(pressColor);
    } else if (hovered) {
        setBackgroundColor(hoverColor);
    } else {
        setBackgroundColor(normalColor);
    }
}
