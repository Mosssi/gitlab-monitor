#ifndef GITLAB_DESKTOP_MONITOR_CONFIGURATION_H
#define GITLAB_DESKTOP_MONITOR_CONFIGURATION_H

#include <QtCore/QString>
#include <QtCore/QObject>

enum class ThemeMode {
    LIGHT,
    DARK,
};

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
    void setAssignedToMe(bool assignedToMe);
    [[nodiscard]] bool getAssignedToMe() const;

signals:
    void themeChanged();
    void assignedToMeChanged();

private:
    explicit Configuration();

    QString serverAddress = "";
    QString token = "";
    ThemeMode theme = ThemeMode::LIGHT;
    bool assignedToMe = false;
};


#endif //GITLAB_DESKTOP_MONITOR_CONFIGURATION_H
