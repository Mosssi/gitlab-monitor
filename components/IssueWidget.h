#ifndef GITLAB_DESKTOP_MONITOR_ISSUEWIDGET_H
#define GITLAB_DESKTOP_MONITOR_ISSUEWIDGET_H


#include "../models/Issue.h"
#include "library/HoverClickFrame.h"
#include "library/Label.h"

class IssueWidget : public HoverClickFrame {
Q_OBJECT
public:
    explicit IssueWidget(int projectId, const Issue &issue, QWidget * parent = nullptr);

signals:
    void closed();

private:
    void setupUi();
    void updateUi();

    Issue issue;
    int projectId;

    Label * nameLabel = nullptr;
    Label * iidLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_ISSUEWIDGET_H
