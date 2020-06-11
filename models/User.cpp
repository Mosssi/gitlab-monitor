#include "User.h"

User::User(const QJsonObject &jsonObject) : BaseModel(jsonObject) {

    username = jsonObject.value("username").toString();
    name = jsonObject.value("name").toString();
}

QJsonObject User::getJson() const {

    return QJsonObject{
            BASE_MODEL_JSON,
            {"username", username},
            {"name",     name}
    };
}
