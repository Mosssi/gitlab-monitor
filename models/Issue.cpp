#include "Issue.h"

Issue::Issue(const QJsonObject &jsonObject) : BaseModel(jsonObject) {

    iid = jsonObject.value("iid").toInt();
    title = jsonObject.value("title").toString();
    description = jsonObject.value("description").toString();
}

QJsonObject Issue::getJson() const {

    return QJsonObject{
            BASE_MODEL_JSON,
            {"iid", iid},
            {"title", title},
            {"description", description}
    };
}
