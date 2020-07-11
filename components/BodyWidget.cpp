#include "BodyWidget.h"

#include "../utilities/Configuration.h"
#include "../utilities/DataStore.h"
#include "ProjectWidget.h"

BodyWidget::BodyWidget(QWidget * parent) : SlidingStackedWidget(parent) {

    setupUi();
    setStyleSheet("background-color: #ffffff;");
}

void BodyWidget::setupUi() {

    addWidget(projectsListWidget = new ProjectsListWidget());
    addWidget(issuesListWidget = new IssuesListWidget());

    connect(projectsListWidget, &ProjectsListWidget::projectSelected, [this](int projectId, QString projectName) {
        issuesListWidget->setProjectId(projectId);
        issuesListWidget->setProjectName(projectName);
        showIssuesList();
    });

    connect(issuesListWidget, &IssuesListWidget::backClicked, [this]() {
        showProjectList();
    });

    connect(&Configuration::getInstance(), &Configuration::assignedToMeChanged, [this]() {
        if (currentWidget() == issuesListWidget) {
            issuesListWidget->refreshList(true);
        }
    });
}

void BodyWidget::showProjectList() {

    slideInIdx(0);
}

void BodyWidget::showIssuesList() {

    slideInIdx(1);
}
