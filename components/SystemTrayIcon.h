#ifndef GITLAB_DESKTOP_MONITOR_SYSTEMTRAYICON_H
#define GITLAB_DESKTOP_MONITOR_SYSTEMTRAYICON_H

#include <QSystemTrayIcon>
#include <QEvent>

class SystemTrayIcon : public QSystemTrayIcon {
Q_OBJECT
public:
    static SystemTrayIcon &getInstance();
    void setEnabled(bool enabled);

signals:
    void clicked();

private:
    explicit SystemTrayIcon();
};


#endif //GITLAB_DESKTOP_MONITOR_SYSTEMTRAYICON_H
