#include "Project.h"

Project::Project(const QJsonObject &jsonObject) {

    id = jsonObject.value("id").toInt();
    name = jsonObject.value("name").toString();
    description = jsonObject.value("description").toString();
}

QJsonObject Project::getJson() const {

    return QJsonObject{
            {"id", id},
            {"name", name},
            {"description", description},
    };
}
