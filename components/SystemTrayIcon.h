#ifndef GITLAB_DESKTOP_MONITOR_SYSTEMTRAYICON_H
#define GITLAB_DESKTOP_MONITOR_SYSTEMTRAYICON_H

#include <QSystemTrayIcon>

class SystemTrayIcon : public QSystemTrayIcon {
Q_OBJECT
public:
    explicit SystemTrayIcon();
    void setEnabled(bool enabled);

signals:
    void clicked();
    void rightClicked();
};


#endif //GITLAB_DESKTOP_MONITOR_SYSTEMTRAYICON_H
