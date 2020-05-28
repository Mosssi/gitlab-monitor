#include "Issue.h"

Issue::Issue(const QJsonObject &jsonObject) {

    id = jsonObject.value("id").toInt();
    title = jsonObject.value("title").toString();
    description = jsonObject.value("description").toString();
}

QJsonObject Issue::getJson() const {

    return QJsonObject{
            {"id",          id},
            {"title",       title},
            {"description", description}
    };
}
