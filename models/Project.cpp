#include "Project.h"

Project::Project(const QJsonObject &jsonObject) {

    id = jsonObject.value("id").toInt();
    name = jsonObject.value("name").toString();
    description = jsonObject.value("description").toString();
    starred = jsonObject.value("star_count").toInt() > 0;
    openIssuesCount = jsonObject.value("open_issues_count").toInt();
}

QJsonObject Project::getJson() const {

    return QJsonObject{
            {"id",              id},
            {"name",            name},
            {"description",     description},
            {"starred",         starred},
            {"openIssuesCount", openIssuesCount}
    };
}
