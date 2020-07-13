#ifndef GITLAB_DESKTOP_MONITOR_GUIMANAGER_H
#define GITLAB_DESKTOP_MONITOR_GUIMANAGER_H


#include <QtGui/QFont>

#include "../components/ApplicationWidget.h"
#include "Configuration.h"

class GuiManager {
public:
    static QFont applicationFont() { return QFont("Ubuntu", normalFontSize()); }

    static QFont iconFont() { return QFont("gitlab-monitoring", smallFontSize()); }

    constexpr static int smallFontSize() { return 12; }
    constexpr static int normalFontSize() { return 14; }
    constexpr static int largeFontSize() { return 16; }
    constexpr static int applicationWidth() { return 300; }
    constexpr static int applicationHeight() { return 400; }
    constexpr static int headerHeight() { return 70; }
    constexpr static int logoHeight() { return 45; }
    constexpr static int projectHeight() { return 55; }
    constexpr static int issueHeight() { return 55; }
    constexpr static int pushButtonHeight() { return 24; }
    constexpr static int bodyHeaderHeight() { return 40; }
    constexpr static int loadingWidgetHeight() { return 28; }
    constexpr static int contextMenuButtonWidth() { return 160; }
    constexpr static int contextMenuButtonHeight() { return 30; }
    constexpr static int configurationWindowWidth() { return 200; }
    constexpr static int configurationWindowHeight() { return 150; }
    constexpr static int toggleSwitchWidth() { return 26; }
    constexpr static int toggleSwitchHeight() { return 14; }

    static inline QString lightOrangeColor() { return "#fca121"; }
    static inline QString orangeColor() { return "#fc6d26"; }
    static inline QString redOrangeColor() { return "#db3b21"; }
    static inline QString lightPurpleColor() { return "#6e49cb"; }
    static inline QString purpleColor() { return "#380d75"; }

    static QString textColor() { return Configuration::getInstance().getDarkTheme() ? lightColor() : darkGrayColor(); }
    static QString secondaryTextColor() { return Configuration::getInstance().getDarkTheme() ? darkerLightColor() : grayColor(); }
    static QString tertiaryTextColor() { return Configuration::getInstance().getDarkTheme() ? evenDarkerLightColor() : lighterGrayColor(); }
    static QString titleColor() { return Configuration::getInstance().getDarkTheme() ? darkerLightColor() : lightGrayColor(); } // TODO: fix name

    static QString mainHeaderColor() { return Configuration::getInstance().getDarkTheme() ? darkGrayColor() : lightColor(); }
    static QString headerColor() { return Configuration::getInstance().getDarkTheme() ? lightGrayColor() : darkLightColor(); }
    static QString backgroundColor() { return Configuration::getInstance().getDarkTheme() ? darkGrayColor() : whiteColor(); }
    static QString hoverColor() { return Configuration::getInstance().getDarkTheme() ? grayColor() : lighterColor(); }
    static QString pressColor() { return Configuration::getInstance().getDarkTheme() ? lightGrayColor() : lightColor(); }
    static QString buttonColor() { return Configuration::getInstance().getDarkTheme() ? lightGrayColor() : darkLightColor(); }
    static QString buttonHoverColor() { return Configuration::getInstance().getDarkTheme() ? lighterGrayColor() : darkerLightColor(); }
    static QString buttonPressColor() { return Configuration::getInstance().getDarkTheme() ? grayColor() : lightColor(); }

    static void setApplicationWindow(ApplicationWidget * widget);
    static ApplicationWidget * getApplicationWindow();

private:
    static GuiManager &getInstance();

    static inline QString darkGrayColor() { return "#2e2e2e"; }
    static inline QString grayColor() { return "#4a4a4a"; }
    static inline QString lightGrayColor() { return "#666666"; }
    static inline QString lighterGrayColor() { return "#888888"; }
    static inline QString whiteColor() { return "#ffffff"; }
    static inline QString lighterColor() { return "#f7f7f7"; }
    static inline QString lightColor() { return "#f0f0f0"; }
    static inline QString darkLightColor() { return "#e5e5e5"; }
    static inline QString darkerLightColor() { return "#d0d0d0"; }
    static inline QString evenDarkerLightColor() { return "#a0a0a0"; }

    ApplicationWidget * applicationWindow;
};


#endif //GITLAB_DESKTOP_MONITOR_GUIMANAGER_H
