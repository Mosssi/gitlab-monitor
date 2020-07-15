#include "Configuration.h"

Configuration::Configuration() : QObject(nullptr) {

}

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

void Configuration::setTheme(ThemeMode theme) {

    this->theme = theme;
    emit themeChanged();
}

ThemeMode Configuration::getTheme() const {

    return theme;
}

void Configuration::setAssignedToMe(bool assignedToMe) {

    this->assignedToMe = assignedToMe;
    emit assignedToMeChanged();
}

bool Configuration::getAssignedToMe() const {

    return assignedToMe;
}

void Configuration::setServerAddress(const QString &serverAddress) {

    // TODO: parse serverAddress and act more flexible
    this->serverAddress = serverAddress + "/api/v4";
}

QString Configuration::getServerAddress() const {

    return serverAddress;
}
