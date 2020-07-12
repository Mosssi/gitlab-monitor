#ifndef GITLAB_DESKTOP_MONITOR_NOTIFICATIONSERVICE_H
#define GITLAB_DESKTOP_MONITOR_NOTIFICATIONSERVICE_H

#include <QList>

#include "NotificationWidget.h"

int const margin = 15;
int const spacing = 1;

class NotificationService : public QObject {
Q_OBJECT
Q_PROPERTY(int baseHeight READ getBaseHeight WRITE setBaseHeight)
public:
    static void info(const QString &message);
    static void error(const QString &message);

private:
    explicit NotificationService();
    static NotificationService &getInstance();
    void refreshPositions();
    void addNotification(const QString &message, NotificationStatus status);

    void setBaseHeight(int baseHeight) { this->baseHeight = baseHeight; refreshPositions(); }
    int getBaseHeight() { return this->baseHeight; }

    QList<NotificationWidget *> notificationWidgets;
    int baseHeight;
};


#endif //GITLAB_DESKTOP_MONITOR_NOTIFICATIONSERVICE_H
