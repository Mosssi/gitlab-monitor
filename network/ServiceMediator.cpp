#include "ServiceMediator.h"

#include "NetworkManager.h"

ServiceMediator &ServiceMediator::getInstance() {

    static ServiceMediator instance;
    return instance;
}

void ServiceMediator::requestUser() {

    NetworkManager::getInstance().get("/user", [this](const QJsonObject &obj, ResponseStatus status) {
        if (status == ResponseStatus::SUCCESSFUL) {
            emit userReceived(NetworkResponse<User>::ok(User(obj)));
        } else {
            emit userReceived(NetworkResponse<User>::error());
        }
    });
}
