#ifndef GITLAB_DESKTOP_MONITOR_THEME_H
#define GITLAB_DESKTOP_MONITOR_THEME_H


#include <QtCore/QString>

class Theme {
public:
    virtual QString textColor() = 0;
    virtual QString secondaryTextColor() = 0;
    virtual QString tertiaryTextColor() = 0;
    virtual QString titleColor() = 0;

    virtual QString headerBorderColor() = 0;
    virtual QString mainHeaderColor() = 0;
    virtual QString headerColor() = 0;
    virtual QString backgroundColor() = 0;
    virtual QString hoverColor() = 0;
    virtual QString pressColor() = 0;
    virtual QString buttonColor() = 0;
    virtual QString buttonHoverColor() = 0;
    virtual QString buttonPressColor() = 0;
    virtual QString loadingColor() = 0;
    virtual QString loadingRingColor() = 0;
    virtual QString switchOffColor() = 0;
    virtual QString switchOffBackgroundColor() = 0;
    virtual QString switchOnColor() = 0;
    virtual QString switchOnBackgroundColor() = 0;

    virtual QString infoNotificationColor() = 0;
    virtual QString infoNotificationTextColor() = 0;
    virtual QString errorNotificationColor() = 0;
    virtual QString errorNotificationTextColor() = 0;
};


#endif //GITLAB_DESKTOP_MONITOR_THEME_H
