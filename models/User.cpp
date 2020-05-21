#include "User.h"

User::User(const QJsonObject &jsonObject) {

    id = jsonObject.value("id").toInt();
    username = jsonObject.value("username").toString();
    name = jsonObject.value("name").toString();
}

QJsonObject User::getJson() const {

    return QJsonObject{
            {"id",       id},
            {"username", username},
            {"name",     name}
    };
}
