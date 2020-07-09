#ifndef GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H
#define GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H


#include "library/Frame.h"

class ConfigurationWindow : public Frame {
public:
    explicit ConfigurationWindow(QWidget * parent = nullptr);

private:
    void setupUi();
};


#endif //GITLAB_DESKTOP_MONITOR_CONFIGURATIONWINDOW_H
