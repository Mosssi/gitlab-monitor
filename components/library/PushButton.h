#ifndef GITLAB_DESKTOP_MONITOR_PUSHBUTTON_H
#define GITLAB_DESKTOP_MONITOR_PUSHBUTTON_H


#include <QtWidgets/QPushButton>

#include "IconType.h"

class PushButton : public QPushButton {
public:
    explicit PushButton(const IconType &icon, QWidget * parent = nullptr);
};


#endif //GITLAB_DESKTOP_MONITOR_PUSHBUTTON_H
