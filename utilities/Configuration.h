#ifndef GITLAB_DESKTOP_MONITOR_CONFIGURATION_H
#define GITLAB_DESKTOP_MONITOR_CONFIGURATION_H

#include <QtCore/QString>

class Configuration {
public:
    static Configuration &getInstance();

    void setToken(const QString &token);
    [[nodiscard]] QString getToken() const;

private:
    Configuration() = default;

    QString token;
};


#endif //GITLAB_DESKTOP_MONITOR_CONFIGURATION_H
