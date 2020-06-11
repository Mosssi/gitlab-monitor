#ifndef GITLAB_DESKTOP_MONITOR_USER_H
#define GITLAB_DESKTOP_MONITOR_USER_H

#include <QtCore/QJsonObject>

#include "BaseModel.h"

class User : public BaseModel {
public:
    User() = default;
    explicit User(const QJsonObject &jsonObject);

    [[nodiscard]] QJsonObject getJson() const override;

    QString username = "";
    QString name = "";
};


#endif //GITLAB_DESKTOP_MONITOR_USER_H
