#include "ProjectsListWidget.h"

#include "../utilities/DataStore.h"
#include "library/ScrollArea.h"
#include "ProjectWidget.h"

ProjectsListWidget::ProjectsListWidget(QWidget * parent) : QFrame(parent) {

    setupUi();
    setStyleSheet("background-color: #ffffff;");

    connect(&DataStore::getInstance(), &DataStore::projectsReceived, this, &ProjectsListWidget::updateUi);
}

void ProjectsListWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    scrollLayout = new QVBoxLayout();
    scrollLayout->setContentsMargins(0, 0, 0, 0);
    scrollLayout->setSpacing(0);
    scrollLayout->setAlignment(Qt::AlignTop);

    mainLayout->addWidget(new ScrollArea(scrollLayout));
}

void ProjectsListWidget::updateUi() {

    const QList<Project> projects = DataStore::getInstance().getProjects();

    for (const auto &project : projects) {
        auto * projectWidget = new ProjectWidget(project.id);
        connect(projectWidget, &ProjectWidget::clicked, [this, project]() {
            emit projectSelected(project.id);
        });
        scrollLayout->addWidget(projectWidget);
    }
}
