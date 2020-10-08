#include "BodyWidget.h"

#include "../utilities/Configuration.h"
#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "ProjectWidget.h"

BodyWidget::BodyWidget(QWidget * parent) : SlidingStackedWidget(parent) {

    setupUi();
    BodyWidget::updateStyleSheet();

    connect(&DataStore::getInstance(), &DataStore::userReceiveFailed, [this](ResponseStatus status) {
        setCurrentIndex(2);
    });
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

    auto * refreshWidget = new QWidget();
    auto * refreshLayout = new QHBoxLayout(refreshWidget);
    auto * refreshButton = new PushButton(IconType::RELOAD);
    refreshLayout->addWidget(refreshButton, 0, Qt::AlignCenter);
    connect(refreshButton, &PushButton::clicked, [this]() {
        DataStore::getInstance().initialize();
        setCurrentIndex(0);
    });
    addWidget(refreshWidget);
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
