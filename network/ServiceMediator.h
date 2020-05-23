#ifndef GITLAB_DESKTOP_MONITOR_SERVICEMEDIATOR_H
#define GITLAB_DESKTOP_MONITOR_SERVICEMEDIATOR_H

#include <QtCore/QObject>

#include "NetworkManager.h"

class ServiceMediator {
public:
    static void requestUser(const CallbackFunction &callback);
    static void requestProjects(const int &userId, bool simple, const CallbackFunction &callback);
    static void requestGroups(const int &userId, const CallbackFunction &callback);

private:
    ServiceMediator() = default;
    static QString getUrl(const QString &url, const QList<QPair<QString, QString>> &queries = {{}});
};


#endif //GITLAB_DESKTOP_MONITOR_SERVICEMEDIATOR_H
