#include "Project.h"

Project::Project(const QJsonObject &jsonObject) : BaseModel(jsonObject) {

    name = jsonObject.value("name").toString();
    description = jsonObject.value("description").toString();
    starred = jsonObject.value("star_count").toInt() > 0;
    openIssuesCount = jsonObject.value("open_issues_count").toInt();
    lastActivity = QDateTime::fromString(jsonObject.value("last_activity_at").toString(), Qt::ISODate);
}

QJsonObject Project::getJson() const {

    return QJsonObject{
            BASE_MODEL_JSON,
            {"name", name},
            {"description", description},
            {"starred", starred},
            {"openIssuesCount", openIssuesCount}
    };
}

void Project::setOpenIssues(const QList<Issue> &openIssues) {

    this->openIssues = openIssues;
    this->openIssuesCount = openIssues.count();
}
