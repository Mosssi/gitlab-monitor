#include "ServiceMediator.h"

void ServiceMediator::requestUser(const CallbackFunction &callback) {
    NetworkManager::getInstance().get("/user", callback);
}
