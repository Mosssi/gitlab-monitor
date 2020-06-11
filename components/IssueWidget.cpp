#include "IssueWidget.h"

#include <QtWidgets/QHBoxLayout>

#include "../network/ServiceMediator.h"
#include "../utilities/DataStore.h"
#include "library/PushButton.h"

IssueWidget::IssueWidget(int projectId, const Issue &issue, QWidget * parent) : QFrame(parent), issue(issue), projectId(projectId) {

    setupUi();
    updateUi();
}

void IssueWidget::setupUi() {

    setFixedHeight(GuiManager::issueHeight());
    setFixedWidth(GuiManager::applicationWidth());
    setStyleSheet("background-color: #ffffff;"); // TODO

    auto * mainLayout = new QHBoxLayout(this);

    auto * projectDetailsLayout = new QVBoxLayout();
    projectDetailsLayout->setSpacing(0);
    projectDetailsLayout->setAlignment(Qt::AlignTop);

    projectDetailsLayout->addWidget(iidLabel = new Label());
    iidLabel->setFontSize(GuiManager::smallFontSize());
    iidLabel->setColor(GuiManager::evenDarkerLightColor());
    projectDetailsLayout->addWidget(nameLabel = new Label());

    mainLayout->addLayout(projectDetailsLayout);

    mainLayout->addStretch();

    auto * closeIssueButton = new PushButton(IconType::DONE, true);
    connect(closeIssueButton, &PushButton::clicked, this, &IssueWidget::closed);
    mainLayout->addWidget(closeIssueButton);
}

void IssueWidget::updateUi() {

    nameLabel->setText(issue.title);
    iidLabel->setText(QString("#%1").arg(issue.iid));
}

void IssueWidget::enterEvent(QEvent * event) {

    setStyleSheet("background-color: #f7f7f7;");
    QWidget::enterEvent(event);
}

void IssueWidget::leaveEvent(QEvent * event) {

    setStyleSheet("background-color: #ffffff;");
    QWidget::leaveEvent(event);
}

void IssueWidget::mouseReleaseEvent(QMouseEvent * event) {

    emit clicked();
}

