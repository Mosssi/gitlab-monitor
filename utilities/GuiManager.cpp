#include "GuiManager.h"

void GuiManager::setApplicationWindow(QWidget * widget) {

    GuiManager::getInstance().applicationWindow = widget;
}

QWidget * GuiManager::getApplicationWindow() {

    return GuiManager::getInstance().applicationWindow;
}

GuiManager &GuiManager::getInstance() {

    static GuiManager instance;
    return instance;
}
