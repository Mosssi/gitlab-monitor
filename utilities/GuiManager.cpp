#include "GuiManager.h"

#include "DarkTheme.h"
#include "LightTheme.h"

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

Theme &GuiManager::getTheme() {

    switch (Configuration::getInstance().getTheme()) {
        case ThemeMode::LIGHT:
            return LightTheme::getInstance();
        case ThemeMode::DARK:
            return DarkTheme::getInstance();
    }
}
