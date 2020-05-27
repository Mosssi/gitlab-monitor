#include "ProjectWidget.h"

#include <QtWidgets/QHBoxLayout>

#include "../utilities/DataStore.h"
#include "../network/ServiceMediator.h"

ProjectWidget::ProjectWidget(int projectId, bool oddRow, QWidget * parent) : QFrame(parent), projectId(projectId), oddRow(oddRow) {

    setupUi();
    updateUi();
}

void ProjectWidget::setupUi() {

    setFixedHeight(GuiManager::projectHeight());
    setStyleSheet("background-color: #ffffff;");

    auto * mainLayout = new QHBoxLayout(this);

    auto * projectDetailsLayout = new QVBoxLayout();
    projectDetailsLayout->setSpacing(0);

    projectDetailsLayout->addWidget(nameLabel = new Label());
//    nameLabel->setBold(true);

    projectDetailsLayout->addWidget(descriptionLabel = new Label());
    descriptionLabel->setVisible(false);
    descriptionLabel->setColor(GuiManager::lightGrayColor());
    descriptionLabel->setFontSize(GuiManager::smallFontSize());

    mainLayout->addLayout(projectDetailsLayout);

    mainLayout->addStretch();

    mainLayout->addWidget(openIssuesCountLabel = new Label());
}

void ProjectWidget::updateUi() {

    const Project &project = DataStore::getInstance().getProject(projectId);

    nameLabel->setText(project.name);
    if (!project.description.isEmpty()) {
        descriptionLabel->setText(project.description.mid(0, 20));
        descriptionLabel->setVisible(true);
    }

    openIssuesCountLabel->setText(QString::number(project.openIssuesCount));
}

void ProjectWidget::toggleProjectStar() {

    const Project &project = DataStore::getInstance().getProject(projectId);

    const auto updateContent = [this](CALLBACK_SIGNATURE) {
        if (status == ResponseStatus::SUCCESSFUL) {
            DataStore::getInstance().updateProject(Project(jsonValue.toObject()));
            updateUi();
        }
    };

    if (project.starred) {
        ServiceMediator::starProject(projectId, updateContent);
    } else {
        ServiceMediator::unStarProject(projectId, updateContent);
    }
}

void ProjectWidget::enterEvent(QEvent * event) {

    setStyleSheet("background-color: #f7f7f7;");
    QWidget::enterEvent(event);
}

void ProjectWidget::leaveEvent(QEvent * event) {

    setStyleSheet("background-color: #ffffff;");
    QWidget::leaveEvent(event);
}
