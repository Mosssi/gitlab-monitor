#ifndef GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H
#define GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H

#include "library/Modal.h"
#include "library/ModalToggle.h"
#include "library/ToggleSwitch.h"

class ConfigurationWindow : public Modal {
public:
    explicit ConfigurationWindow(QWidget * parent = nullptr);

private:
    void setupUi();

    ModalToggle * themeToggle = nullptr;
    ModalToggle * autoStartToggle = nullptr;
    ModalToggle * filterAssigneeToggle = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H
