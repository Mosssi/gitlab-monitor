#include "ContextMenuButton.h"

ContextMenuButton::ContextMenuButton(const QString &text, QWidget * parent) : Label(text, parent) {

    setFontSize(GuiManager::smallFontSize());
    setBackgroundColor(GuiManager::lightColor());
    setFixedSize(GuiManager::contextMenuButtonWidth(), GuiManager::contextMenuButtonHeight());
    setGeneralStyle("padding: 5px;");
}

void ContextMenuButton::mouseReleaseEvent(QMouseEvent *) {

    emit clicked();
}

void ContextMenuButton::enterEvent(QEvent * event) {

    setBackgroundColor(GuiManager::darkLightColor());
    QWidget::enterEvent(event);
}

void ContextMenuButton::leaveEvent(QEvent * event) {

    setBackgroundColor(GuiManager::lightColor());
    QWidget::leaveEvent(event);
}