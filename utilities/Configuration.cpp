#include "Configuration.h"

#define SERVER_ADDR_KEY "server-address"
#define TOKEN_KEY "token"
#define THEME_KEY "theme"
#define ASSIGNED_TO_ME_KEY "assigned-to-me"

Configuration::Configuration() : QObject(nullptr) {

    if (settings.contains(SERVER_ADDR_KEY)) {
        serverAddress = settings.value(SERVER_ADDR_KEY).toString();
    }

    if (settings.contains(TOKEN_KEY)) {
        token = settings.value(TOKEN_KEY).toString();
    }

    if (settings.contains(THEME_KEY)) {
        theme = enumerateThemeMode(settings.value(THEME_KEY).toString());
    } else {
        settings.setValue(THEME_KEY, stringifyThemeMode(ThemeMode::LIGHT));
        theme = ThemeMode::LIGHT;
    }

    if (settings.contains(ASSIGNED_TO_ME_KEY)) {
        assignedToMe = settings.value(ASSIGNED_TO_ME_KEY).toBool();
    } else {
        settings.setValue(ASSIGNED_TO_ME_KEY, false);
        assignedToMe = false;
    }
}

Configuration &Configuration::getInstance() {

    static Configuration instance;
    return instance;
}

void Configuration::setServerAddress(const QString &serverAddress) {

    // TODO: parse serverAddress and act more flexible
    const QString &addr = serverAddress + "/api/v4";
    settings.setValue(SERVER_ADDR_KEY, addr);
    this->serverAddress = addr;
}

QString Configuration::getServerAddress() const {

    return serverAddress;
}

void Configuration::setToken(const QString &token) {

    settings.setValue(TOKEN_KEY, token);
    this->token = token;
}

QString Configuration::getToken() const {

    return token;
}

void Configuration::setTheme(ThemeMode theme) {

    settings.setValue(THEME_KEY, stringifyThemeMode(theme));
    this->theme = theme;
    emit themeChanged();
}

ThemeMode Configuration::getTheme() const {

    return theme;
}

void Configuration::setAssignedToMe(bool assignedToMe) {

    settings.setValue(ASSIGNED_TO_ME_KEY, assignedToMe);
    this->assignedToMe = assignedToMe;
    emit assignedToMeChanged();
}

bool Configuration::getAssignedToMe() const {

    return assignedToMe;
}

QString stringifyThemeMode(const ThemeMode &themeMode) {

    switch (themeMode) {
        case ThemeMode::LIGHT:
            return "LIGHT";
        case ThemeMode::DARK:
            return "DARK";
    }
}

ThemeMode enumerateThemeMode(const QString &themeMode) {

    if (themeMode == "DARK") {
        return ThemeMode::DARK;
    } else {
        return ThemeMode::LIGHT;
    }
}
