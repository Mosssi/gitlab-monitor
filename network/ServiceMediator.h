#ifndef GITLAB_DESKTOP_MONITOR_SERVICEMEDIATOR_H
#define GITLAB_DESKTOP_MONITOR_SERVICEMEDIATOR_H

#include <QtCore/QObject>

#include "../models/User.h"
#include "NetworkManager.h"
#include "ResponseStatus.h"
#include "NetworkResponse.h"

class ServiceMediator : public QObject {
Q_OBJECT
public:
    static ServiceMediator &getInstance();
    void requestUser();

signals:
    void userReceived(const NetworkResponse<User> &);

private:
    ServiceMediator() = default;
};


#endif //GITLAB_DESKTOP_MONITOR_SERVICEMEDIATOR_H
