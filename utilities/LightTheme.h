#ifndef GITLAB_DESKTOP_MONITOR_LIGHTTHEME_H
#define GITLAB_DESKTOP_MONITOR_LIGHTTHEME_H


#include "Theme.h"
#include "ColorPalette.h"

class LightTheme : public Theme {
public:
    static LightTheme &getInstance() {
        static LightTheme theme;
        return theme;
    }

    QString textColor() override { return D_GRAY_COLOR; }
    QString secondaryTextColor() override { return GRAY_COLOR; }
    QString tertiaryTextColor() override { return LL_GRAY_COLOR; }
    QString titleColor() override { return L_GRAY_COLOR; }
    QString headerBorderColor() override { return ORANGE_COLOR; }
    QString mainHeaderColor() override { return LIGHT_COLOR; }
    QString headerColor() override { return DARK_LIGHT_COLOR; }
    QString backgroundColor() override { return WHITE_COLOR; }
    QString hoverColor() override { return LIGHTER_COLOR; }
    QString pressColor() override { return LIGHT_COLOR; }
    QString buttonColor() override { return DARK_LIGHT_COLOR; }
    QString buttonHoverColor() override { return DARKER_LIGHT_COLOR; }
    QString buttonPressColor() override { return LIGHT_COLOR; }
    QString loadingColor() override { return EVEN_DARKER_LIGHT_COLOR; }
    QString loadingRingColor() override { return DARK_LIGHT_COLOR; }

    QString switchOffColor() override { return DARKER_LIGHT_COLOR; }
    QString switchOffBackgroundColor() override { return LL_GRAY_COLOR; }
    QString switchOnColor() override { return LL_GRAY_COLOR; }
    QString switchOnBackgroundColor() override { return LIGHT_ORANGE_COLOR; }

    QString infoNotificationColor() override { return GRAY_COLOR; }
    QString infoNotificationTextColor() override { return LIGHT_COLOR; }
    QString errorNotificationColor() override { return RED_ORANGE_COLOR; }
    QString errorNotificationTextColor() override { return LIGHT_COLOR; }
};


#endif //GITLAB_DESKTOP_MONITOR_LIGHTTHEME_H
