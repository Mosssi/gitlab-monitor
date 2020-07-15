#ifndef GITLAB_DESKTOP_MONITOR_LIGHTTHEME_H
#define GITLAB_DESKTOP_MONITOR_LIGHTTHEME_H


#include "Theme.h"
#include "GuiManager.h"

class LightTheme : public Theme {
public:
    static LightTheme &getInstance() {
        static LightTheme theme;
        return theme;
    }

    QString textColor() override { return GuiManager::darkGrayColor(); }
    QString secondaryTextColor() override { return GuiManager::grayColor(); }
    QString tertiaryTextColor() override { return GuiManager::lighterGrayColor(); }
    QString titleColor() override { return GuiManager::lightGrayColor(); }
    QString headerBorderColor() override { return GuiManager::orangeColor(); }
    QString mainHeaderColor() override { return GuiManager::lightColor(); }
    QString headerColor() override { return GuiManager::darkLightColor(); }
    QString backgroundColor() override { return GuiManager::whiteColor(); }
    QString hoverColor() override { return GuiManager::lighterColor(); }
    QString pressColor() override { return GuiManager::lightColor(); }
    QString buttonColor() override { return GuiManager::darkLightColor(); }
    QString buttonHoverColor() override { return GuiManager::darkerLightColor(); }
    QString buttonPressColor() override { return GuiManager::lightColor(); }
    QString loadingColor() override { return GuiManager::evenDarkerLightColor(); }
    QString loadingRingColor() override { return GuiManager::darkLightColor(); }

    QString switchOffColor() override { return GuiManager::darkerLightColor(); }
    QString switchOffBackgroundColor() override { return GuiManager::lighterGrayColor(); }
    QString switchOnColor() override { return GuiManager::lighterGrayColor(); }
    QString switchOnBackgroundColor() override { return GuiManager::lightOrangeColor(); }

    QString infoNotificationColor() override { return GuiManager::grayColor(); }
    QString infoNotificationTextColor() override { return GuiManager::lightColor(); }
    QString errorNotificationColor() override { return GuiManager::redOrangeColor(); }
    QString errorNotificationTextColor() override { return GuiManager::lightColor(); }
};


#endif //GITLAB_DESKTOP_MONITOR_LIGHTTHEME_H
