#include "IssueWidget.h"

#include <QtWidgets/QHBoxLayout>

#include "../utilities/DataStore.h"
#include "../network/ServiceMediator.h"
#include "library/PushButton.h"

IssueWidget::IssueWidget(int projectId, const Issue &issue, QWidget * parent) : QFrame(parent), issue(issue), projectId(projectId) {

    setupUi();
    updateUi();
}

void IssueWidget::setupUi() {

    setFixedHeight(GuiManager::issueHeight());
    setStyleSheet("background-color: #ffffff;");

    auto * mainLayout = new QHBoxLayout(this);

    auto * projectDetailsLayout = new QVBoxLayout();
    projectDetailsLayout->setSpacing(0);

    projectDetailsLayout->addWidget(nameLabel = new Label());

    mainLayout->addLayout(projectDetailsLayout);

    mainLayout->addStretch();

    auto * closeIssueButton = new PushButton(IconType::DONE);
    connect(closeIssueButton, &PushButton::clicked, [this]() {
        ServiceMediator::closeIssue(projectId, issue.iid, [](CALLBACK_SIGNATURE) {}); // TODO, TO-CONSIDER, TO-DECIDE!
    });
    mainLayout->addWidget(closeIssueButton);
}

void IssueWidget::updateUi() {

    nameLabel->setText(issue.title);
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

