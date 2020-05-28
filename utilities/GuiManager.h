#ifndef GITLAB_DESKTOP_MONITOR_GUIMANAGER_H
#define GITLAB_DESKTOP_MONITOR_GUIMANAGER_H


#include <QtGui/QFont>

class GuiManager {
public:
    static QFont applicationFont() { return QFont("Ubuntu", normalFontSize()); }
    static QFont iconFont() { return QFont("gitlab-monitoring", normalFontSize()); }
    constexpr static int smallFontSize() { return 13; }
    constexpr static int normalFontSize() { return 15; }
    constexpr static int largeFontSize() { return 17; }

    constexpr static int applicationWidth() { return 300; }
    constexpr static int applicationHeight() { return 400; }
    constexpr static int headerHeight() { return 70; }
    constexpr static int logoHeight() { return 45; }
    constexpr static int projectHeight() { return 55; }
    constexpr static int issueHeight() { return 55; }
    constexpr static int pushButtonHeight() { return 24; }

    static QString darkGrayColor() { return "#2e2e2e"; }
    static QString grayColor() { return "#4a4a4a"; }
    static QString lightGrayColor() { return "#666666"; }
    static QString lightColor() { return "#f0f0f0"; }
    static QString darkLightColor() { return "#e5e5e5"; }
    static QString darkerLightColor() { return "#d0d0d0"; }

    static QString lightOrangeColor() { return "#fca121"; }
    static QString orangeColor() { return "#fc6d26"; }
    static QString redOrangeColor() { return "#db3b21"; }
    static QString lightPurpleColor() { return "#6e49cb"; }
    static QString purpleColor() { return "#380d75"; }
};


#endif //GITLAB_DESKTOP_MONITOR_GUIMANAGER_H
