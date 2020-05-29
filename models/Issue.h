#ifndef GITLAB_DESKTOP_MONITOR_ISSUE_H
#define GITLAB_DESKTOP_MONITOR_ISSUE_H


#include <QtCore/QJsonObject>

class Issue {
public:
    Issue() = default;
    explicit Issue(const QJsonObject &jsonObject);

    [[nodiscard]] QJsonObject getJson() const;

    int id = 0;
    int iid = 0;
    QString title = "";
    QString description = "";
};


#endif //GITLAB_DESKTOP_MONITOR_ISSUE_H
