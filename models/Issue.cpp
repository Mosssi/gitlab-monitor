#include "Issue.h"

#include <QDebug>

Issue::Issue(const QJsonObject &jsonObject) {

    id = jsonObject.value("id").toInt();
    iid = jsonObject.value("iid").toInt();
    title = jsonObject.value("title").toString();
    description = jsonObject.value("description").toString();
}

QJsonObject Issue::getJson() const {

    return QJsonObject{
            {"id",          id},
            {"iid",         iid},
            {"title",       title},
            {"description", description}
    };
}
