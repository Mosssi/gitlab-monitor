#include "ProjectsListWidget.h"

#include "../utilities/DataStore.h"
#include "../utilities/NotificationService.h"
#include "ProjectWidget.h"
#include "library/LoadingWidget.h"
#include "library/PushButton.h"

ProjectsListWidget::ProjectsListWidget(QWidget * parent) : Frame(parent) {

    setupUi();
    ProjectsListWidget::updateStyleSheet();

    connect(&DataStore::getInstance(), &DataStore::projectsReceived, this, &ProjectsListWidget::updateUi);
    connect(&DataStore::getInstance(), &DataStore::projectsReceiveFailed, [this]() {
        if (DataStore::getInstance().getProjects().isEmpty()) {
            contentWidget->setState(LoadableContentState::ERROR);
        } else {
            NotificationService::error("Error in updating list of projects");
            contentWidget->setState(LoadableContentState::CONTENT);
        }
    });
}

void ProjectsListWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    topFrame = new Frame();
    auto * topLayout = new QHBoxLayout(topFrame);
    topFrame->setFixedHeight(GuiManager::bodyHeaderHeight());
    auto * starredIssuesLabel = new Label("STARRED PROJECTS");
    starredIssuesLabel->setColor(TextColor::TITLE);
    topLayout->addWidget(starredIssuesLabel);
    topLayout->addStretch();
    auto * refreshButton = new PushButton(IconType::RELOAD);
    topLayout->addWidget(refreshButton);
    connect(refreshButton, &PushButton::clicked, [this]() {
        DataStore::getInstance().refreshProjects();
        contentWidget->setState(LoadableContentState::LOADING);
    });

    mainLayout->addWidget(topFrame);

    scrollLayout = new QVBoxLayout();
    scrollLayout->setContentsMargins(0, 0, 0, 0);
    scrollLayout->setSpacing(0);
    scrollLayout->setAlignment(Qt::AlignTop);

    mainLayout->addWidget(contentWidget = new LoadableContentWidget(scrollLayout));

    contentWidget->setState(LoadableContentState::LOADING);
}

void ProjectsListWidget::updateUi() {

    const QList<Project> projects = DataStore::getInstance().getProjects();

    if (projects.isEmpty()) {
        // TODO: Show no contents page
    } else {
        emptyScrollLayout();
        for (const auto &project : projects) {
            auto * projectWidget = new ProjectWidget(project.id);
            connect(projectWidget, &ProjectWidget::clicked, [this, project]() {
                emit projectSelected(project.id, project.name);
            });
            scrollLayout->addWidget(projectWidget);
        }
    }

    contentWidget->setState(LoadableContentState::CONTENT);
}

void ProjectsListWidget::emptyScrollLayout() {

    QLayoutItem * child;
    while ((child = scrollLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}

void ProjectsListWidget::updateStyleSheet() {

    setBackgroundColor(GuiManager::getTheme().backgroundColor());
    topFrame->setBackgroundColor(GuiManager::getTheme().headerColor());
}
