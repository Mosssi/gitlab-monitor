#ifndef GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H
#define GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H


#include "library/Modal.h"

class ConfigurationWindow : public Modal {
public:
    explicit ConfigurationWindow(QWidget * parent = nullptr);

private:
    void setupUi();
};


#endif //GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H
