#ifndef GITLAB_DESKTOP_MONITOR_DARKTHEME_H
#define GITLAB_DESKTOP_MONITOR_DARKTHEME_H


#include "Theme.h"
#include "ColorPalette.h"

class DarkTheme : public Theme {
public:
    static DarkTheme &getInstance() {
        static DarkTheme theme;
        return theme;
    }

    QString textColor() override { return DARK_LIGHT_COLOR; }
    QString secondaryTextColor() override { return DARKER_LIGHT_COLOR; }
    QString tertiaryTextColor() override { return EVEN_DARKER_LIGHT_COLOR; }
    QString titleColor() override { return DARKER_LIGHT_COLOR; }
    QString headerBorderColor() override { return ORANGE_COLOR; }
    QString mainHeaderColor() override { return D_GRAY_COLOR; }
    QString headerColor() override { return L_GRAY_COLOR; }
    QString backgroundColor() override { return D_GRAY_COLOR; }
    QString hoverColor() override { return GRAY_COLOR; }
    QString pressColor() override { return L_GRAY_COLOR; }
    QString buttonColor() override { return L_GRAY_COLOR; }
    QString buttonHoverColor() override { return LL_GRAY_COLOR; }
    QString buttonPressColor() override { return GRAY_COLOR; }
    QString loadingColor() override { return EVEN_DARKER_LIGHT_COLOR; }
    QString loadingRingColor() override { return GRAY_COLOR; }

    QString switchOffColor() override { return GRAY_COLOR; }
    QString switchOffBackgroundColor() override { return LL_GRAY_COLOR; }
    QString switchOnColor() override { return DARKER_LIGHT_COLOR; }
    QString switchOnBackgroundColor() override { return LIGHT_ORANGE_COLOR; }

    QString infoNotificationColor() override { return GRAY_COLOR; }
    QString infoNotificationTextColor() override { return LIGHT_COLOR; }
    QString errorNotificationColor() override { return RED_ORANGE_COLOR; }
    QString errorNotificationTextColor() override { return LIGHT_COLOR; }
};

#endif //GITLAB_DESKTOP_MONITOR_DARKTHEME_H
