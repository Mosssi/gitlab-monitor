#ifndef GITLAB_DESKTOP_MONITOR_THEME_H
#define GITLAB_DESKTOP_MONITOR_THEME_H

#include <QtCore/QString>

class Theme {
public:
    [[nodiscard]] virtual QString textColor() const = 0;
    [[nodiscard]] virtual QString secondaryTextColor() const = 0;
    [[nodiscard]] virtual QString tertiaryTextColor() const = 0;
    [[nodiscard]] virtual QString titleColor() const = 0;

    [[nodiscard]] virtual QString headerBorderColor() const = 0;
    [[nodiscard]] virtual QString mainHeaderColor() const = 0;
    [[nodiscard]] virtual QString headerColor() const = 0;
    [[nodiscard]] virtual QString backgroundColor() const = 0;
    [[nodiscard]] virtual QString hoverColor() const = 0;
    [[nodiscard]] virtual QString pressColor() const = 0;
    [[nodiscard]] virtual QString buttonColor() const = 0;
    [[nodiscard]] virtual QString buttonHoverColor() const = 0;
    [[nodiscard]] virtual QString buttonPressColor() const = 0;
    [[nodiscard]] virtual QString loadingColor() const = 0;
    [[nodiscard]] virtual QString loadingRingColor() const = 0;
    [[nodiscard]] virtual QString switchOffColor() const = 0;
    [[nodiscard]] virtual QString switchOffBackgroundColor() const = 0;
    [[nodiscard]] virtual QString switchOnColor() const = 0;
    [[nodiscard]] virtual QString switchOnBackgroundColor() const = 0;
    [[nodiscard]] virtual QString lineEditBackgroundColor() const = 0;
    [[nodiscard]] virtual QString lineEditErrorBackgroundColor() const = 0;

    [[nodiscard]] virtual QString infoNotificationColor() const = 0;
    [[nodiscard]] virtual QString infoNotificationTextColor() const = 0;
    [[nodiscard]] virtual QString errorNotificationColor() const = 0;
    [[nodiscard]] virtual QString errorNotificationTextColor() const = 0;
};


#endif //GITLAB_DESKTOP_MONITOR_THEME_H
