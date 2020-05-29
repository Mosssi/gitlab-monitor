#ifndef GITLAB_DESKTOP_MONITOR_BODYWIDGET_H
#define GITLAB_DESKTOP_MONITOR_BODYWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QVBoxLayout>

#include "ProjectsListWidget.h"
#include "IssuesListWidget.h"
#include "library/SlidingStackedWidget.h"

class BodyWidget : public SlidingStackedWidget {
public:
    explicit BodyWidget(QWidget * parent = nullptr);

private:
    void setupUi();
    void showProjectList();
    void showIssuesList();

    ProjectsListWidget * projectsListWidget = nullptr;
    IssuesListWidget * issuesListWidget = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_BODYWIDGET_H
