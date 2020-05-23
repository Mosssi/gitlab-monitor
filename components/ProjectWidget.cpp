#include "ProjectWidget.h"

#include <QtWidgets/QLabel>

#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"

ProjectWidget::ProjectWidget(int projectId, bool oddRow, QWidget * parent) : QFrame(parent), projectId(projectId), oddRow(oddRow) {

    setupUi();
}

void ProjectWidget::setupUi() {

    const Project project = DataStore::getInstance().getProject(projectId);

    mainLayout = new QHBoxLayout(this);

    auto * projectDetailsLayout = new QVBoxLayout();
    projectDetailsLayout->setSpacing(0);

    setFixedHeight(GuiManager::projectHeight());
    setStyleSheet("background-color: " + (oddRow ? QString("#ffffff") : QString("#f5f5f5")));

    projectDetailsLayout->addWidget(new QLabel(project.name));
    if (!project.description.isEmpty()) {
        auto * descriptionLabel = new QLabel(project.description);
        descriptionLabel->setStyleSheet(QString("color: %1; font-size: %2px;").arg(GuiManager::grayColor(10)).arg(GuiManager::smallFontSize()));
        projectDetailsLayout->addWidget(descriptionLabel);
    }

    mainLayout->addLayout(projectDetailsLayout);
}
