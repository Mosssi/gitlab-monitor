#ifndef GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H
#define GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H


#include "library/Modal.h"
#include "library/ToggleSwitch.h"

class ConfigurationWindow : public Modal {
public:
    explicit ConfigurationWindow(QWidget * parent = nullptr);

private:
    void setupUi();

    ToggleSwitch * darkThemeSwitch = nullptr;
    ToggleSwitch * autoStartSwitch = nullptr;
    ToggleSwitch * assignedToMeSwitch = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H
