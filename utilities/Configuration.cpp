#include "Configuration.h"

#include <QDebug>
#include <QtCore/QDir>
#include <QApplication>

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

    const QString &basePath = QString("%1/.local/share/Mosssi/gitlab-monitor").arg(QDir::homePath());
    QDir binDirectory = QDir(basePath + "/bin/");
    QDir logDirectory = QDir(basePath + "/log/");
    QDir iconDirectory = QDir(basePath + "/icon/");
    if (!binDirectory.exists("gitlab-monitor")) {
        QDir(basePath).mkpath("/bin");
        QFile(QApplication::applicationFilePath()).copy(basePath + "/bin/gitlab-monitor");
    }
    if (!logDirectory.exists()) {
        QDir(basePath).mkpath("/log");
    }
    if (!iconDirectory.exists("gitlab-monitor.svg")) {
        QFile(":/images/gitlab-icon.svg").copy(basePath + "/icon/gitlab-monitor.svg");
    }

    if (!QFile("/home/mohsen/.local/share/applications/gitlab-monitor.desktop").exists()) {
        QFile file("/home/mohsen/.local/share/applications/gitlab-monitor.desktop");
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);

        QString fileContents = QString("[Desktop Entry]\n"
                               "Icon=%1/.local/share/Mosssi/gitlab-monitor/icon/gitlab-monitor.svg\n"
                               "Exec=%1/.local/share/Mosssi/gitlab-monitor/bin/gitlab-monitor %u\n"
                               "Version=1.0\n"
                               "Type=Application\n"
                               "Categories=Development\n"
                               "Name=Gitlab Monitor\n"
                               "StartupWMClass=gitlab-monitor\n"
                               "Terminal=false\n").arg(QDir::homePath());
        out << fileContents;
    }

    // TODO: refactor codes above, add to .config/autologin ...
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

void Configuration::setAutoStart(bool autoStart) {

    settings.setValue(ASSIGNED_TO_ME_KEY, autoStart);
    this->autoStart = autoStart;
}

bool Configuration::getAutoStart() const {

    return assignedToMe;
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
