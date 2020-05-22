#ifndef GITLAB_DESKTOP_MONITOR_GUIMANAGER_H
#define GITLAB_DESKTOP_MONITOR_GUIMANAGER_H


#include <QtGui/QFont>

class GuiManager {
public:
    static QFont applicationFont();
    constexpr static int smallFontSize() { return 10; }
    constexpr static int normalFontSize() { return 11; }
    constexpr static int largeFontSize() { return 13; }

    constexpr static int applicationWidth() { return 300; }
    constexpr static int applicationHeight() { return 400; }
    constexpr static int headerHeight() { return 75; }

    static QString grayColor(int lightness);
};


#endif //GITLAB_DESKTOP_MONITOR_GUIMANAGER_H
