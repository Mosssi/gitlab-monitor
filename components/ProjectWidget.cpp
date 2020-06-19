#include "ProjectWidget.h"

#include <QtWidgets/QHBoxLayout>

#include "../utilities/DataStore.h"
#include "../network/ServiceMediator.h"
#include "library/LoadingWidget.h"

ProjectWidget::ProjectWidget(int projectId, QWidget * parent) : QFrame(parent), projectId(projectId) {

    setupUi();
    updateUi();

    connect(&DataStore::getInstance(), &DataStore::projectOpenIssuesReceived, this, &ProjectWidget::updateUi);
}

void ProjectWidget::setupUi() {

    setFixedHeight(GuiManager::projectHeight());
    setStyleSheet("background-color: #ffffff;"); // TODO: use GuiManager

    auto * mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 20, 10);

    auto * projectDetailsLayout = new QVBoxLayout();
    projectDetailsLayout->setSpacing(0);

    projectDetailsLayout->addWidget(nameLabel = new Label());

    projectDetailsLayout->addWidget(descriptionLabel = new Label());
    descriptionLabel->setVisible(false);
    descriptionLabel->setColor(GuiManager::lightGrayColor());
    descriptionLabel->setFontSize(GuiManager::smallFontSize());

    mainLayout->addLayout(projectDetailsLayout);

    mainLayout->addStretch();

    mainLayout->addWidget(openIssuesCountLabel = new Label());
    openIssuesCountLabel->setColor(GuiManager::grayColor());
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

void ProjectWidget::enterEvent(QEvent * event) {

    setStyleSheet("background-color: #f7f7f7;");
    QWidget::enterEvent(event);
}

void ProjectWidget::leaveEvent(QEvent * event) {

    setStyleSheet("background-color: #ffffff;");
    QWidget::leaveEvent(event);
}

void ProjectWidget::mouseReleaseEvent(QMouseEvent * event) {

    emit clicked();
}
