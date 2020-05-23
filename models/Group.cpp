#include "Group.h"

Group::Group(const QJsonObject &jsonObject) {

    id = jsonObject.value("id").toInt();
    name = jsonObject.value("name").toString();
}

QJsonObject Group::getJson() const {

    return QJsonObject{
            {"id",   id},
            {"name", name}
    };
}
