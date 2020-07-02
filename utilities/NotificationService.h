#ifndef GITLAB_DESKTOP_MONITOR_NOTIFICATIONSERVICE_H
#define GITLAB_DESKTOP_MONITOR_NOTIFICATIONSERVICE_H

#include <QList>

#include "NotificationWidget.h"

class NotificationService {
public:
    static void info(const QString &message);
    static void warning(const QString &message);
    static void error(const QString &message);

private:
    static NotificationService &getInstance();
    void refreshPositions();
    void addNotification(const QString &message, NotificationStatus status);

    QList<NotificationWidget *> notificationWidgets;
};


#endif //GITLAB_DESKTOP_MONITOR_NOTIFICATIONSERVICE_H
