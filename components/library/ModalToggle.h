#ifndef GITLAB_DESKTOP_MONITOR_MODALTOGGLE_H
#define GITLAB_DESKTOP_MONITOR_MODALTOGGLE_H


#include "HoverClickFrame.h"
#include "ToggleSwitch.h"

class ModalToggle : public HoverClickFrame {
public:
    explicit ModalToggle(const QString &text, bool checked, QWidget * parent = nullptr);
    bool isChecked();
    void setChecked(bool checked);

private:
    void setupUi(const QString &text, bool checked);

    ToggleSwitch * toggleSwitch = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_MODALTOGGLE_H
