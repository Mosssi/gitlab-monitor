#include "GuiManager.h"

void GuiManager::setApplicationWindow(ApplicationWidget * widget) {

    GuiManager::getInstance().applicationWindow = widget;
}

ApplicationWidget * GuiManager::getApplicationWindow() {

    return GuiManager::getInstance().applicationWindow;
}

GuiManager &GuiManager::getInstance() {

    static GuiManager instance;
    return instance;
}
