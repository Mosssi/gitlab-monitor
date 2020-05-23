#ifndef GITLAB_DESKTOP_MONITOR_GROUP_H
#define GITLAB_DESKTOP_MONITOR_GROUP_H


#include <QtCore/QJsonObject>

class Group {
public:
    Group() = default;
    explicit Group(const QJsonObject &jsonObject);

    [[nodiscard]] QJsonObject getJson() const;

    int id = 0;
    QString name = "";
};


#endif //GITLAB_DESKTOP_MONITOR_GROUP_H
