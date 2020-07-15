#include "ProjectWidget.h"

#include <QtWidgets/QHBoxLayout>

#include "../utilities/DataStore.h"
#include "../network/ServiceMediator.h"
#include "library/LoadingWidget.h"

ProjectWidget::ProjectWidget(int projectId, QWidget * parent) : HoverClickFrame(parent), projectId(projectId) {

    setupUi();
    ProjectWidget::updateStyleSheet();
    updateUi();
}

void ProjectWidget::setupUi() {

    setFixedHeight(GuiManager::projectHeight());
    setFixedWidth(GuiManager::applicationWidth());

    auto * mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 20, 10);

    auto * projectDetailsLayout = new QVBoxLayout();
    projectDetailsLayout->setSpacing(0);

    projectDetailsLayout->addWidget(nameLabel = new Label());

    projectDetailsLayout->addWidget(descriptionLabel = new Label());
    descriptionLabel->setVisible(false);
    descriptionLabel->setFontSize(GuiManager::smallFontSize());

    mainLayout->addLayout(projectDetailsLayout);

    mainLayout->addStretch();

    mainLayout->addWidget(openIssuesCountLabel = new Label());
}

void ProjectWidget::updateUi() {

    const Project &project = DataStore::getInstance().getProject(projectId);

    nameLabel->setText(project.name);
    if (!project.description.isEmpty()) {
        descriptionLabel->setText(project.description);
        descriptionLabel->setVisible(true);
    }

    openIssuesCountLabel->setText(QString::number(project.openIssuesCount));
}

void ProjectWidget::updateStyleSheet() {

    HoverClickFrame::updateStyleSheet();
    nameLabel->setColor(GuiManager::getTheme().textColor());
    descriptionLabel->setColor(GuiManager::getTheme().secondaryTextColor());
    openIssuesCountLabel->setColor(GuiManager::getTheme().textColor());
}
