#include "BodyWidget.h"

#include "../utilities/Configuration.h"
#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "ProjectWidget.h"

BodyWidget::BodyWidget(QWidget * parent) : SlidingStackedWidget(parent) {

    setupUi();
    BodyWidget::updateStyleSheet();
}

void BodyWidget::setupUi() {

    addWidget(projectsListWidget = new ProjectsListWidget());
    addWidget(issuesListWidget = new IssuesListWidget());

    connect(projectsListWidget, &ProjectsListWidget::projectSelected, [this](int projectId, const QString &projectName) {
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

    DataStore::getInstance().initialize();
}

void BodyWidget::showProjectList() {

    slideInIdx(0);
}

void BodyWidget::showIssuesList() {

    slideInIdx(1);
}

void BodyWidget::updateStyleSheet() {

    setStyleSheet(QString("background-color: %1;").arg(GuiManager::getTheme().backgroundColor()));
}

bool BodyWidget::isIssuesListVisible() {

    return currentIndex() == 1;
}
