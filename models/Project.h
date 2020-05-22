#ifndef GITLAB_DESKTOP_MONITOR_PROJECT_H
#define GITLAB_DESKTOP_MONITOR_PROJECT_H

#include <QtCore/QJsonObject>
#include <QtCore/QObject>

class Project {
public:
    Project() = default;
    explicit Project(const QJsonObject &jsonObject);

    [[nodiscard]] QJsonObject getJson() const;

    int id = 0;
    QString name = "";
    QString description = "";
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECT_H
