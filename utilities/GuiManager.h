#ifndef GITLAB_DESKTOP_MONITOR_GUIMANAGER_H
#define GITLAB_DESKTOP_MONITOR_GUIMANAGER_H


#include <QtGui/QFont>

class GuiManager {
public:
    static QFont applicationFont();
    constexpr static int smallFontSize() { return 10; }
    constexpr static int normalFontSize() { return 10; }
    constexpr static int largeFontSize() { return 13; }

    constexpr static int applicationWidth() { return 350; }
    constexpr static int applicationHeight() { return 450; }
    constexpr static int headerHeight() { return 75; }

    constexpr static int projectHeight() { return 65; }

    static QString darkGrayColor() { return "#2e2e2e"; }
    static QString lightColor() { return "#e3e3e3"; }
    static QString lightOrangeColor() { return "#fca121"; }
    static QString orangeColor() { return "#fc6d26"; }
    static QString redOrangeColor() { return "#db3b21"; }
    static QString lightPurpleColor() { return "#6e49cb"; }
    static QString purpleColor() { return "#380d75"; }
};


#endif //GITLAB_DESKTOP_MONITOR_GUIMANAGER_H
