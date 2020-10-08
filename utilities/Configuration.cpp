#include "Configuration.h"

#include <QApplication>
#include <QtCore/QDir>
#include <QTextStream>

#include "../constants.h"
#include "NotificationService.h"

#define SERVER_ADDR_KEY "server-address"
#define TOKEN_KEY "token"
#define VALID_CONFIG_KEY "valid-configs"
#define THEME_KEY "theme"
#define ASSIGNED_TO_ME_KEY "assigned-to-me"
#define AUTO_START_KEY "auto-start"

Configuration::Configuration() : QObject(nullptr) {

    if (settings.contains(SERVER_ADDR_KEY)) {
        serverAddress = settings.value(SERVER_ADDR_KEY).toString();
    }

    if (settings.contains(TOKEN_KEY)) {
        token = settings.value(TOKEN_KEY).toString();
    }

    if (settings.contains(VALID_CONFIG_KEY)) {
        validConfigs = settings.value(VALID_CONFIG_KEY).toBool();
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

    if (settings.contains(AUTO_START_KEY)) {
        autoStart = settings.value(AUTO_START_KEY).toBool();
    } else {
        settings.setValue(AUTO_START_KEY, true);
        autoStart = true;
    }

#ifndef NO_AUTO_START
    const QString &basePath = QString("%1/.local/share/%2/%3").arg(QDir::homePath()).arg(ORGANIZATION_NAME).arg(APP_NAME);
    if (!QDir(basePath + "/bin/").exists(BINARY_NAME)) {
        QDir(basePath).mkpath("bin");
        QFile(QApplication::applicationFilePath()).copy(basePath + "/bin/" + BINARY_NAME);
    }
    if (!QDir(basePath + "/log/").exists()) {
        QDir(basePath).mkpath("log");
    }
    if (!QDir(basePath + "/icon/").exists(ICON_NAME)) {
        const QString &name = basePath + "/icon/" + ICON_NAME;
        QDir(basePath).mkpath("icon");
        QFile(":/images/gitlab-icon.svg").copy(name);
    }

    const QString desktopFilePath = QString("%1/.local/share/applications/%2.desktop").arg(QDir::homePath()).arg(APP_NAME);
    if (!QFile(desktopFilePath).exists()) {
        QFile file(desktopFilePath);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);

        out << getDesktopFileContents();
    }
#endif
}

Configuration &Configuration::getInstance() {

    static Configuration instance;
    return instance;
}

void Configuration::setServerAddress(const QString &serverAddress) {

    settings.setValue(SERVER_ADDR_KEY, serverAddress);
    this->serverAddress = serverAddress;
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

#ifndef NO_AUTO_START
void Configuration::setAutoStart(bool autoStart) {

    bool result = false;
    const QString autoLoginFile = QString("%1/.config/autostart/%2.desktop").arg(QDir::homePath()).arg(APP_NAME);
    const QFile &autoStartFile = QFile(autoLoginFile);
    if (autoStart) {
        if (!autoStartFile.exists()) {
            QFile file(autoLoginFile);
            result = file.open(QIODevice::WriteOnly | QIODevice::Text);
            if (result) {
                QTextStream out(&file);
                out << getDesktopFileContents();
            }
        }
    } else {
        if (autoStartFile.exists()) {
            result = QFile::remove(autoLoginFile);
        } else {
            result = true;
        }
    }

    if (result) {
        settings.setValue(AUTO_START_KEY, autoStart);
        this->autoStart = autoStart;
        emit autoStartChanged();
    } else {
        NotificationService::error("Error in updating configuration");
    }
}

bool Configuration::getAutoStart() const {

    return autoStart;
}
#endif

void Configuration::setAssignedToMe(bool assignedToMe) {

    settings.setValue(ASSIGNED_TO_ME_KEY, assignedToMe);
    this->assignedToMe = assignedToMe;
    emit assignedToMeChanged();
}

bool Configuration::getAssignedToMe() const {

    return assignedToMe;
}

QString Configuration::getDesktopFileContents() {

    return QString("[Desktop Entry]\n"
                   "Icon=%1/.local/share/%2/%3/icon/%4\n"
                   "Exec=%1/.local/share/%2/%3/bin/%5\n"
                   "Version=1.0\n"
                   "Type=Application\n"
                   "Categories=Development\n"
                   "Name=Gitlab Monitor\n"
                   "StartupWMClass=gitlab-monitor\n"
                   "Terminal=false\n"
                   "X-GNOME-Autostart-Delay=10\n")
            .arg(QDir::homePath())
            .arg(ORGANIZATION_NAME)
            .arg(APP_NAME)
            .arg(ICON_NAME)
            .arg(BINARY_NAME);
}

void Configuration::setValidConfigs(bool validConfigs) {

    settings.setValue(VALID_CONFIG_KEY, validConfigs);
    this->validConfigs = validConfigs;
}

bool Configuration::getValidConfigs() const {

    return validConfigs;
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
