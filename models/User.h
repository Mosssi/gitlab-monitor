#ifndef GITLAB_DESKTOP_MONITOR_USER_H
#define GITLAB_DESKTOP_MONITOR_USER_H

#include <QtCore/QJsonObject>

#include "BaseModel.h"

class User {
public:
    User() = default;
    explicit User(const QJsonObject &jsonObject);

    [[nodiscard]] QJsonObject getJson() const;

    int id = 0;
    QString username = "";
    QString name = "";
};


#endif //GITLAB_DESKTOP_MONITOR_USER_H
