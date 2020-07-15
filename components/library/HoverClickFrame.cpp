#include "HoverClickFrame.h"

#include <QDebug>

HoverClickFrame::HoverClickFrame(QWidget * parent, bool pressEnabled) : Frame(parent), pressEnabled(pressEnabled) {

    HoverClickFrame::updateStyleSheet();
}

void HoverClickFrame::mousePressEvent(QMouseEvent * event) {

    QWidget::mousePressEvent(event);
    if (pressEnabled) {
        pressed = true;
        HoverClickFrame::updateStyleSheet();
    }
}

void HoverClickFrame::mouseReleaseEvent(QMouseEvent * event) {

    QWidget::mouseReleaseEvent(event);
    if (pressEnabled) {
        pressed = false;
        emit clicked();
        HoverClickFrame::updateStyleSheet();
    }
}

void HoverClickFrame::enterEvent(QEvent * event) {

    QWidget::enterEvent(event);
    hovered = true;
    HoverClickFrame::updateStyleSheet();
}

void HoverClickFrame::leaveEvent(QEvent * event) {

    QWidget::leaveEvent(event);
    hovered = false;
    HoverClickFrame::updateStyleSheet();
}

void HoverClickFrame::updateStyleSheet() {

    if (pressed) {
        setBackgroundColor(GuiManager::getTheme().pressColor());
    } else if (hovered) {
        setBackgroundColor(GuiManager::getTheme().hoverColor());
    } else {
        setBackgroundColor(GuiManager::getTheme().backgroundColor());
    }
}
