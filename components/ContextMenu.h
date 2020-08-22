#ifndef GITLAB_DESKTOP_MONITOR_CONTEXTMENU_H
#define GITLAB_DESKTOP_MONITOR_CONTEXTMENU_H

#include "library/Frame.h"

class ContextMenu : public Frame {
Q_OBJECT
public:
    explicit ContextMenu();

signals:
    void openClicked();
    void exitClicked();

private:
    void setupUi();
    void updateStyleSheet() override;
};


#endif //GITLAB_DESKTOP_MONITOR_CONTEXTMENU_H
