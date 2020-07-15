#ifndef GITLAB_DESKTOP_MONITOR_DARKTHEME_H
#define GITLAB_DESKTOP_MONITOR_DARKTHEME_H


#include "Theme.h"
#include "GuiManager.h"

class DarkTheme : public Theme {
public:
    static DarkTheme &getInstance() {
        static DarkTheme theme;
        return theme;
    }

    QString textColor() override { return GuiManager::darkLightColor(); }
    QString secondaryTextColor() override { return GuiManager::darkerLightColor(); }
    QString tertiaryTextColor() override { return GuiManager::evenDarkerLightColor(); }
    QString titleColor() override { return GuiManager::darkerLightColor(); }
    QString headerBorderColor() override { return GuiManager::orangeColor(); }
    QString mainHeaderColor() override { return GuiManager::darkGrayColor(); }
    QString headerColor() override { return GuiManager::lightGrayColor(); }
    QString backgroundColor() override { return GuiManager::darkGrayColor(); }
    QString hoverColor() override { return GuiManager::grayColor(); }
    QString pressColor() override { return GuiManager::lightGrayColor(); }
    QString buttonColor() override { return GuiManager::lightGrayColor(); }
    QString buttonHoverColor() override { return GuiManager::lighterGrayColor(); }
    QString buttonPressColor() override { return GuiManager::grayColor(); }
    QString loadingColor() override { return GuiManager::evenDarkerLightColor(); }
    QString loadingRingColor() override { return GuiManager::grayColor(); }

    QString switchOffColor() override { return GuiManager::grayColor(); }
    QString switchOffBackgroundColor() override { return GuiManager::lighterGrayColor(); }
    QString switchOnColor() override { return GuiManager::darkerLightColor(); }
    QString switchOnBackgroundColor() override { return GuiManager::lightOrangeColor(); }

    QString infoNotificationColor() override { return GuiManager::grayColor(); }
    QString infoNotificationTextColor() override { return GuiManager::lightColor(); }
    QString errorNotificationColor() override { return GuiManager::redOrangeColor(); }
    QString errorNotificationTextColor() override { return GuiManager::lightColor(); }
};

#endif //GITLAB_DESKTOP_MONITOR_DARKTHEME_H
