#ifndef GITLAB_DESKTOP_MONITOR_ISSUE_H
#define GITLAB_DESKTOP_MONITOR_ISSUE_H


#include <QtCore/QJsonObject>

#include "BaseModel.h"

class Issue : public BaseModel {
public:
    Issue() = default;
    explicit Issue(const QJsonObject &jsonObject);

    [[nodiscard]] QJsonObject getJson() const override;

    int iid = 0;
    QString title = "";
    QString description = "";
};


#endif //GITLAB_DESKTOP_MONITOR_ISSUE_H
