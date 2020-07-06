#ifndef GITLAB_DESKTOP_MONITOR_CONTEXTMENUBUTTON_H
#define GITLAB_DESKTOP_MONITOR_CONTEXTMENUBUTTON_H


#include "library/HoverClickFrame.h"

class ContextMenuButton : public HoverClickFrame {
Q_OBJECT
public:
    explicit ContextMenuButton(const QString &text, QWidget * parent = nullptr);

private:
    void setupUi();
    QString text;
};


#endif //GITLAB_DESKTOP_MONITOR_CONTEXTMENUBUTTON_H
