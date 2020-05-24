#include "ProjectWidget.h"

#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
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

    projectDetailsLayout->addWidget(nameLabel = new QLabel());
//    nameLabel->setStyleSheet("font-weight: bold;");
    projectDetailsLayout->addWidget(descriptionLabel = new QLabel());
    descriptionLabel->setVisible(false);
    descriptionLabel->setStyleSheet(QString("color: %1; font-size: %2px;").arg(GuiManager::darkGrayColor()).arg(GuiManager::smallFontSize()));

    mainLayout->addLayout(projectDetailsLayout);

    mainLayout->addStretch();

    mainLayout->addWidget(starButton = new QPushButton("★"));
    connect(starButton, &QPushButton::clicked, this, &ProjectWidget::toggleProjectStar);
}

void ProjectWidget::updateUi() {

    const Project &project = DataStore::getInstance().getProject(projectId);

    nameLabel->setText(project.name);
    if (!project.description.isEmpty()) {
        descriptionLabel->setText(project.description.mid(0, 20));
        descriptionLabel->setVisible(true);
    }

    if (project.starred) {
        starButton->setStyleSheet("color: #bbbb44;");
    } else {
        starButton->setStyleSheet("color: #777777;");
    }
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

    setStyleSheet("background-color: #f0f0f0;");
    QWidget::enterEvent(event);
}

void ProjectWidget::leaveEvent(QEvent * event) {

    setStyleSheet("background-color: #ffffff;");
    QWidget::leaveEvent(event);
}
