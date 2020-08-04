#ifndef GITLAB_DESKTOP_MONITOR_CONFIGURATION_H
#define GITLAB_DESKTOP_MONITOR_CONFIGURATION_H

#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtCore/QSettings>

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
    void setAutoStart(bool autoStart);
    [[nodiscard]] bool getAutoStart() const;
    void setAssignedToMe(bool assignedToMe);
    [[nodiscard]] bool getAssignedToMe() const;

signals:
    void themeChanged();
    void assignedToMeChanged();

private:
    explicit Configuration();
    static QString getDesktopFileContents();

    QSettings settings;

    QString serverAddress;
    QString token;
    ThemeMode theme;
    bool autoStart;
    bool assignedToMe;
};


#endif //GITLAB_DESKTOP_MONITOR_CONFIGURATION_H
