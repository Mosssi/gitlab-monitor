#include "BodyWidget.h"

#include "../utilities/DataStore.h"
#include "ProjectWidget.h"

BodyWidget::BodyWidget(QWidget * parent) : SlidingStackedWidget(parent) {

    setupUi();
    setStyleSheet("background-color: #ffffff;");
}

void BodyWidget::setupUi() {

    addWidget(projectsListWidget = new ProjectsListWidget());
    addWidget(issuesListWidget = new IssuesListWidget());

    connect(projectsListWidget, &ProjectsListWidget::projectSelected, [this](int projectId) {
        issuesListWidget->setProjectId(projectId);
        showIssuesList();
    });

    connect(issuesListWidget, &IssuesListWidget::backClicked, [this]() {
        showProjectList();
    });
}

void BodyWidget::showProjectList() {

    slideInIdx(0);
}

void BodyWidget::showIssuesList() {

    slideInIdx(1);
}
