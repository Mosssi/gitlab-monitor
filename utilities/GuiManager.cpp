#include "GuiManager.h"

void GuiManager::setApplicationWindow(QWidget * widget) {

    GuiManager::applicationWindow = widget;
}

QWidget * GuiManager::getApplicationWindow() {

    return GuiManager::applicationWindow;
}
