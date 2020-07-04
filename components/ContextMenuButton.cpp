#include "ContextMenuButton.h"

ContextMenuButton::ContextMenuButton(const QString &text, QWidget * parent) : Label(text, parent) {

    setFontSize(GuiManager::smallFontSize());
    setBackgroundColor(GuiManager::lightColor());
    setFixedSize(GuiManager::contextMenuButtonWidth(), GuiManager::contextMenuButtonHeight());
}

void ContextMenuButton::mouseReleaseEvent(QMouseEvent *) {

    emit clicked();
}
