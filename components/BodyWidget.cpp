#include "BodyWidget.h"

#include "../utilities/DataStore.h"
#include "ProjectWidget.h"

BodyWidget::BodyWidget(QWidget * parent) : SlidingStackedWidget(parent) {

    setupUi();
    BodyWidget::updateStyleSheet();
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

void BodyWidget::updateStyleSheet() {

    setStyleSheet(QString("background-color: %1;").arg(GuiManager::backgroundColor()));
}
