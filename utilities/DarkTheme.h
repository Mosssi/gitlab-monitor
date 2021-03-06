#ifndef GITLAB_DESKTOP_MONITOR_DARKTHEME_H
#define GITLAB_DESKTOP_MONITOR_DARKTHEME_H

#include "ColorPalette.h"
#include "Theme.h"

class DarkTheme : public Theme {
public:
    static DarkTheme &getInstance() {
        static DarkTheme theme;
        return theme;
    }

    [[nodiscard]] QString textColor() const override { return DARK_LIGHT_COLOR; }
    [[nodiscard]] QString secondaryTextColor() const override { return DARKER_LIGHT_COLOR; }
    [[nodiscard]] QString tertiaryTextColor() const override { return EVEN_DARKER_LIGHT_COLOR; }
    [[nodiscard]] QString titleColor() const override { return DARKER_LIGHT_COLOR; }
    [[nodiscard]] QString headerBorderColor() const override { return ORANGE_COLOR; }
    [[nodiscard]] QString mainHeaderColor() const override { return D_GRAY_COLOR; }
    [[nodiscard]] QString headerColor() const override { return L_GRAY_COLOR; }
    [[nodiscard]] QString backgroundColor() const override { return D_GRAY_COLOR; }
    [[nodiscard]] QString hoverColor() const override { return GRAY_COLOR; }
    [[nodiscard]] QString pressColor() const override { return L_GRAY_COLOR; }
    [[nodiscard]] QString buttonColor() const override { return L_GRAY_COLOR; }
    [[nodiscard]] QString buttonHoverColor() const override { return LL_GRAY_COLOR; }
    [[nodiscard]] QString buttonPressColor() const override { return GRAY_COLOR; }
    [[nodiscard]] QString loadingColor() const override { return EVEN_DARKER_LIGHT_COLOR; }
    [[nodiscard]] QString loadingRingColor() const override { return GRAY_COLOR; }

    [[nodiscard]] QString switchOffColor() const override { return L_GRAY_COLOR; }
    [[nodiscard]] QString switchOffBackgroundColor() const override { return LL_GRAY_COLOR; }
    [[nodiscard]] QString switchOnColor() const override { return DARKER_LIGHT_COLOR; }
    [[nodiscard]] QString switchOnBackgroundColor() const override { return LIGHT_ORANGE_COLOR; }

    [[nodiscard]] QString infoNotificationColor() const override { return GRAY_COLOR; }
    [[nodiscard]] QString infoNotificationTextColor() const override { return LIGHT_COLOR; }
    [[nodiscard]] QString errorNotificationColor() const override { return RED_ORANGE_COLOR; }
    [[nodiscard]] QString errorNotificationTextColor() const override { return LIGHT_COLOR; }

    [[nodiscard]] QString lineEditBackgroundColor() const override { return L_GRAY_COLOR; }
    [[nodiscard]] QString lineEditErrorBackgroundColor() const override { return ORANGE_COLOR; }
};

#endif //GITLAB_DESKTOP_MONITOR_DARKTHEME_H
