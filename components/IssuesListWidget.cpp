#include "IssuesListWidget.h"

#include "../network/ServiceMediator.h"
#include "../utilities/DataStore.h"
#include "IssueWidget.h"
#include "library/PushButton.h"
#include "../utilities/NotificationService.h"


IssuesListWidget::IssuesListWidget(QWidget * parent) : Frame(parent) {

    setupUi();
    IssuesListWidget::updateStyleSheet();

    connect(&DataStore::getInstance(), &DataStore::projectOpenIssuesReceived, this, &IssuesListWidget::updateUi);
    connect(&DataStore::getInstance(), &DataStore::projectOpenIssuesReceiveFailed, [this]() {
        if (DataStore::getInstance().getProject(projectId).openIssues.isEmpty()) {
            contentWidget->setState(LoadableContentState::ERROR);
        } else {
            NotificationService::error("Error in updating list of open issues");
        }
    });
}

void IssuesListWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    headerFrame = new Frame();
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

    mainLayout->addWidget(headerFrame);

    mainLayout->addWidget(issueInputWidget = new IssueInputWidget());
    issueInputWidget->setVisible(false);
    connect(issueInputWidget, &IssueInputWidget::cancelled, this, &IssuesListWidget::hideIssueInputWidget);
    connect(issueInputWidget, &IssueInputWidget::submitted, this, &IssuesListWidget::requestIssueCreation);

    scrollLayout = new QVBoxLayout();
    scrollLayout->setContentsMargins(0, 0, 0, 0);
    scrollLayout->setSpacing(0);
    scrollLayout->setAlignment(Qt::AlignTop);

    mainLayout->addWidget(contentWidget = new LoadableContentWidget(scrollLayout));
}

void IssuesListWidget::updateUi() {

    const auto &project = DataStore::getInstance().getProject(projectId);

    projectNameLabel->setText(project.name.toUpper());

    emptyScrollLayout();
    if (project.openIssues.isEmpty()) {
        // TODO: create no content page, perhaps in LoadableContentWidget
    } else {
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

    contentWidget->setState(LoadableContentState::CONTENT);
}

void IssuesListWidget::setProjectId(int projectId) {

    this->projectId = projectId;
    refreshList();
}

void IssuesListWidget::setProjectName(const QString &projectName) {

    projectNameLabel->setText(projectName.toUpper());
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
        } else {
            NotificationService::error("An error occurred in creating issue");
        }
    });
}

void IssuesListWidget::refreshList(bool forceLoading) {

    if (DataStore::getInstance().getProject(projectId).openIssues.isEmpty() || forceLoading) {
        contentWidget->setState(LoadableContentState::LOADING);
    } else {
        updateUi();
    }

    DataStore::getInstance().refreshProjectOpenIssues(projectId);
}

void IssuesListWidget::updateStyleSheet() {

    headerFrame->setBackgroundColor(GuiManager::getTheme().headerColor());
    projectNameLabel->setColor(GuiManager::getTheme().titleColor());
}
