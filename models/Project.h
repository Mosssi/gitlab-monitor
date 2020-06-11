#ifndef GITLAB_DESKTOP_MONITOR_PROJECT_H
#define GITLAB_DESKTOP_MONITOR_PROJECT_H

#include <QtCore/QJsonObject>
#include <QtCore/QObject>
#include <QtCore/QDateTime>

#include "BaseModel.h"
#include "Issue.h"

class Project : public BaseModel {
public:
    Project() = default;
    explicit Project(const QJsonObject &jsonObject);
    void setOpenIssues(const QList<Issue> &openIssues);

    [[nodiscard]] QJsonObject getJson() const override;

    QString name = "";
    QString description = "";
    bool starred = false;
    int openIssuesCount = 0;
    QDateTime lastActivity = QDateTime::currentDateTime();
    QList<Issue> openIssues = {};
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECT_H
