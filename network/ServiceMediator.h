#ifndef GITLAB_DESKTOP_MONITOR_SERVICEMEDIATOR_H
#define GITLAB_DESKTOP_MONITOR_SERVICEMEDIATOR_H

#include <QtCore/QObject>

#include "NetworkManager.h"

class ServiceMediator {
public:
    static void requestUser(const CallbackFunction &callback);

private:
    ServiceMediator() = default;
};


#endif //GITLAB_DESKTOP_MONITOR_SERVICEMEDIATOR_H
