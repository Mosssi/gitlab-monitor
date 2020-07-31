#ifndef GITLAB_DESKTOP_MONITOR_GUIMANAGER_H
#define GITLAB_DESKTOP_MONITOR_GUIMANAGER_H


#include <QtGui/QFont>

#include "../components/ApplicationWidget.h"
#include "Configuration.h"
#include "Theme.h"

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
    constexpr static int configurationItemHeight() { return 18; }
    constexpr static int toggleSwitchWidth() { return 26; }
    constexpr static int toggleSwitchHeight() { return 14; }

    static Theme &getTheme();

    static void setApplicationWindow(ApplicationWidget * widget);
    static ApplicationWidget * getApplicationWindow();

private:
    static GuiManager &getInstance();

    ApplicationWidget * applicationWindow;
};


#endif //GITLAB_DESKTOP_MONITOR_GUIMANAGER_H
