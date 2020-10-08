#ifndef GITLAB_DESKTOP_MONITOR_CONFIGURATION_H
#define GITLAB_DESKTOP_MONITOR_CONFIGURATION_H

#include <QtCore/QObject>
#include <QtCore/QSettings>
#include <QtCore/QString>

#ifndef __linux
 #define NO_AUTO_START
#endif

enum class ThemeMode {
    LIGHT,
    DARK,
};

QString stringifyThemeMode(const ThemeMode &themeMode);

ThemeMode enumerateThemeMode(const QString &themeMode);

class Configuration : public QObject {
Q_OBJECT
public:
    static Configuration &getInstance();
    void setServerAddress(const QString &serverAddress);
    [[nodiscard]] QString getServerAddress() const;
    void setToken(const QString &token);
    [[nodiscard]] QString getToken() const;
    void setTheme(ThemeMode theme);
    [[nodiscard]] ThemeMode getTheme() const;
    void setValidCredentials(bool validCredentials);
    [[nodiscard]] bool getValidCredentials() const;
#ifndef NO_AUTO_START
    void setAutoStart(bool autoStart);
    [[nodiscard]] bool getAutoStart() const;
#endif
    void setAssignedToMe(bool assignedToMe);
    [[nodiscard]] bool getAssignedToMe() const;

signals:
    void themeChanged();
    void assignedToMeChanged();
    void autoStartChanged();

private:
    explicit Configuration();
    static QString getDesktopFileContents();

    QSettings settings;

    QString serverAddress;
    QString token;
    bool validCredentials;
    ThemeMode theme;
    bool autoStart;
    bool assignedToMe;
};


#endif //GITLAB_DESKTOP_MONITOR_CONFIGURATION_H
