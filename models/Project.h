#ifndef GITLAB_DESKTOP_MONITOR_PROJECT_H
#define GITLAB_DESKTOP_MONITOR_PROJECT_H

#include <QtCore/QJsonObject>
#include <QtCore/QObject>
#include "Issue.h"

class Project {
public:
    Project() = default;
    explicit Project(const QJsonObject &jsonObject);
    void setOpenIssues(const QList<Issue> &openIssues);

    [[nodiscard]] QJsonObject getJson() const;

    int id = 0;
    QString name = "";
    QString description = "";
    bool starred = false;
    int openIssuesCount = 0;
    QList<Issue> openIssues = {};
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECT_H
