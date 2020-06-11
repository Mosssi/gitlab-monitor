#ifndef GITLAB_DESKTOP_MONITOR_BASEMODEL_H
#define GITLAB_DESKTOP_MONITOR_BASEMODEL_H


#include <QtCore/QJsonObject>

#define BASE_MODEL_JSON {"id", id}

class BaseModel {
public:
    BaseModel() = default;
    explicit BaseModel(const QJsonObject &jsonObject);
    [[maybe_unused]] [[nodiscard]] virtual QJsonObject getJson() const = 0;

    bool empty = true;
    int id = 0;
};


#endif //GITLAB_DESKTOP_MONITOR_BASEMODEL_H
