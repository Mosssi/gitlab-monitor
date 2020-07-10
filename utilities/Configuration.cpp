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

void Configuration::setDarkTheme(bool darkTheme) {

    this->darkTheme = darkTheme;
    emit darkThemeChanged();
}

bool Configuration::getDarkTheme() const {

    return darkTheme;
}

void Configuration::setAssignedToMe(bool assignedToMe) {

    this->assignedToMe = assignedToMe;
    emit assignedToMeChanged();
}

bool Configuration::getAssignedToMe() const {

    return assignedToMe;
}

Configuration::Configuration() : QObject(nullptr) {

}
