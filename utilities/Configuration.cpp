#include "Configuration.h"

Configuration &Configuration::getInstance() {

    static Configuration instance;
    return instance;
}

void Configuration::setToken(const QString &token) {

    this->token = token;
}

QString Configuration::getToken() const {

    return token;
}
