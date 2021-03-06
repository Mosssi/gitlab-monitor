#include "IssueWidget.h"

#include <QtWidgets/QHBoxLayout>

#include "../network/ServiceMediator.h"
#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"

IssueWidget::IssueWidget(int projectId, const Issue &issue, QWidget * parent) : HoverClickFrame(parent, false), issue(issue), projectId(projectId) {

    setupUi();
    updateUi();
    IssueWidget::updateStyleSheet();
}

void IssueWidget::setupUi() {

    setFixedHeight(GuiManager::issueHeight());
    setFixedWidth(GuiManager::applicationWidth());

    auto * mainLayout = new QHBoxLayout(this);

    auto * projectDetailsLayout = new QVBoxLayout();
    projectDetailsLayout->setSpacing(0);
    projectDetailsLayout->setAlignment(Qt::AlignTop);

    projectDetailsLayout->addWidget(iidLabel = new Label());
    iidLabel->setFontSize(GuiManager::smallFontSize());
    iidLabel->setColor(TextColor::TERTIARY);
    projectDetailsLayout->addWidget(nameLabel = new Label());

    mainLayout->addLayout(projectDetailsLayout);

    mainLayout->addStretch();

    closeIssueButton = new PushButton(IconType::DONE, true);
    connect(closeIssueButton, &PushButton::clicked, this, &IssueWidget::closed);
    mainLayout->addWidget(closeIssueButton);
}

void IssueWidget::updateUi() {

    nameLabel->setText(issue.title);
    iidLabel->setText(QString("#%1").arg(issue.iid));
}

void IssueWidget::updateStyleSheet() {

    HoverClickFrame::updateStyleSheet();
}

void IssueWidget::setLoading(bool loading) {

    closeIssueButton->setLoading(loading);
}
