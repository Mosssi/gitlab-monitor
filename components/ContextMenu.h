#ifndef GITLAB_DESKTOP_MONITOR_CONTEXTMENU_H
#define GITLAB_DESKTOP_MONITOR_CONTEXTMENU_H


#include <QtWidgets/QWidget>

class ContextMenu : public QWidget {
Q_OBJECT
public:
    explicit ContextMenu();

signals:
    void openClicked();
    void exitClicked();

private:
    void setupUi();
};


#endif //GITLAB_DESKTOP_MONITOR_CONTEXTMENU_H
