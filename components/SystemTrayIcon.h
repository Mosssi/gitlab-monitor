#ifndef GITLAB_DESKTOP_MONITOR_SYSTEMTRAYICON_H
#define GITLAB_DESKTOP_MONITOR_SYSTEMTRAYICON_H

#include <QSystemTrayIcon>
#include <QEvent>

class SystemTrayIcon : public QSystemTrayIcon {
Q_OBJECT
public:
    explicit SystemTrayIcon(QObject * parent);

signals:
    void clicked();
};


#endif //GITLAB_DESKTOP_MONITOR_SYSTEMTRAYICON_H
