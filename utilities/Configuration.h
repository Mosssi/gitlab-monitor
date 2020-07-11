#ifndef GITLAB_DESKTOP_MONITOR_CONFIGURATION_H
#define GITLAB_DESKTOP_MONITOR_CONFIGURATION_H

#include <QtCore/QString>
#include <QtCore/QObject>

class Configuration : public QObject {
Q_OBJECT
public:
    static Configuration &getInstance();
    void setServerAddress(const QString &serverAddress);
    [[nodiscard]] QString getServerAddress() const;
    void setToken(const QString &token);
    [[nodiscard]] QString getToken() const;
    void setDarkTheme(bool darkTheme);
    [[nodiscard]] bool getDarkTheme() const;
    void setAssignedToMe(bool assignedToMe);
    [[nodiscard]] bool getAssignedToMe() const;

signals:
    void darkThemeChanged();
    void assignedToMeChanged();

private:
    explicit Configuration();

    QString serverAddress = "";
    QString token = "";
    bool darkTheme = false;
    bool assignedToMe = false;
};


#endif //GITLAB_DESKTOP_MONITOR_CONFIGURATION_H
