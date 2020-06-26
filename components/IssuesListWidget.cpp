#include "IssuesListWidget.h"

#include "../network/ServiceMediator.h"
#include "../utilities/DataStore.h"
#include "IssueWidget.h"
#include "library/PushButton.h"
#include "library/ScrollArea.h"


IssuesListWidget::IssuesListWidget(QWidget * parent) : QFrame(parent) {

    setupUi();

    connect(&DataStore::getInstance(), &DataStore::projectOpenIssuesReceived, this, &IssuesListWidget::updateUi);
}

void IssuesListWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    auto * headerFrame = new QFrame();
    headerFrame->setStyleSheet("background-color: " + GuiManager::darkLightColor() + ";");
    headerFrame->setFixedHeight(GuiManager::bodyHeaderHeight());
    auto * headerLayout = new QHBoxLayout(headerFrame);
    auto * backButton = new PushButton(IconType::BACK);
    connect(backButton, &PushButton::clicked, [this]() {
        hideIssueInputWidget();
        emit backClicked();
    });
    headerLayout->addWidget(backButton);
    headerLayout->addWidget(projectNameLabel = new Label());
    auto * createIssueButton = new PushButton(IconType::NEW);
    headerLayout->addStretch();
    headerLayout->addWidget(createIssueButton);
    connect(createIssueButton, &PushButton::clicked, this, &IssuesListWidget::showIssueInputWidget);
    projectNameLabel->setColor(GuiManager::lightGrayColor());

    mainLayout->addWidget(headerFrame);

    mainLayout->addWidget(issueInputWidget = new IssueInputWidget());
    issueInputWidget->setVisible(false);
    connect(issueInputWidget, &IssueInputWidget::cancelled, this, &IssuesListWidget::hideIssueInputWidget);
    connect(issueInputWidget, &IssueInputWidget::submitted, this, &IssuesListWidget::requestIssueCreation);

    scrollLayout = new QVBoxLayout();
    scrollLayout->setContentsMargins(0, 0, 0, 0);
    scrollLayout->setSpacing(0);
    scrollLayout->setAlignment(Qt::AlignTop);

    mainLayout->addWidget(new ScrollArea(scrollLayout));
}

void IssuesListWidget::updateUi() {

    emptyScrollLayout();

    const auto &project = DataStore::getInstance().getProject(projectId);

    projectNameLabel->setText(project.name.toUpper());

    for (const auto &issue: project.openIssues) {
        auto * issueWidget = new IssueWidget(projectId, issue);
        connect(issueWidget, &IssueWidget::closed, [this, issue]() {
            ServiceMediator::closeIssue(projectId, issue.iid, [this](CALLBACK_SIGNATURE) {
                DataStore::getInstance().refreshProjectOpenIssues(projectId);
            });
        });
        scrollLayout->addWidget(issueWidget);
    }
}

void IssuesListWidget::setProjectId(int projectId) {

    this->projectId = projectId;

    updateUi();

    DataStore::getInstance().refreshProjectOpenIssues(projectId);
}

void IssuesListWidget::emptyScrollLayout() {

    QLayoutItem * child;
    while ((child = scrollLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}

void IssuesListWidget::showIssueInputWidget() {

    issueInputWidget->setVisible(true);
    issueInputWidget->clearInput();
    issueInputWidget->setProjectId(projectId);
}

void IssuesListWidget::hideIssueInputWidget() {

    issueInputWidget->setVisible(false);
}

void IssuesListWidget::requestIssueCreation(const QString &issueTitle) {

    ServiceMediator::createIssue(projectId, issueTitle, [this](CALLBACK_SIGNATURE) {
        if (status == ResponseStatus::SUCCESSFUL) {
            hideIssueInputWidget();
            DataStore::getInstance().refreshProjectOpenIssues(projectId);
            updateUi();
        }
    });
}
