#ifndef GITLAB_DESKTOP_MONITOR_BODYWIDGET_H
#define GITLAB_DESKTOP_MONITOR_BODYWIDGET_H

#include "IssuesListWidget.h"
#include "ProjectsListWidget.h"
#include "library/SlidingStackedWidget.h"

class BodyWidget : public SlidingStackedWidget, StyledWidget {
public:
    explicit BodyWidget(QWidget * parent = nullptr);
    void showProjectList();
    bool isIssuesListVisible();

private:
    void setupUi();
    void showIssuesList();
    void updateStyleSheet() override;

    ProjectsListWidget * projectsListWidget = nullptr;
    IssuesListWidget * issuesListWidget = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_BODYWIDGET_H
