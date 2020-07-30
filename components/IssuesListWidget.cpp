#include "IssuesListWidget.h"

#include "../network/ServiceMediator.h"
#include "../utilities/DataStore.h"
#include "IssueWidget.h"
#include "library/PushButton.h"
#include "../utilities/NotificationService.h"
#include "ModalManager.h"


IssuesListWidget::IssuesListWidget(QWidget * parent) : Frame(parent) {

    setupUi();
    IssuesListWidget::updateStyleSheet();

    connect(&DataStore::getInstance(), &DataStore::projectOpenIssuesReceived, this, &IssuesListWidget::updateUi);
    connect(&DataStore::getInstance(), &DataStore::projectOpenIssuesReceiveFailed, [this]() {
        if (DataStore::getInstance().getProject(projectId).openIssues.isEmpty()) {
            contentWidget->setState(LoadableContentState::ERROR);
        } else {
            NotificationService::error("Error in updating list of open issues");
            contentWidget->setState(LoadableContentState::CONTENT);
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
        emit backClicked();
    });
    headerLayout->addWidget(backButton);
    headerLayout->addWidget(projectNameLabel = new Label());
    projectNameLabel->setColor(TextColor::TITLE);
    auto * createIssueButton = new PushButton(IconType::NEW);
    headerLayout->addStretch();
    headerLayout->addWidget(createIssueButton);
    connect(createIssueButton, &PushButton::clicked, &ModalManager::getInstance(), &ModalManager::showIssueInputWindow);

    mainLayout->addWidget(headerFrame);

    connect(ModalManager::getInstance().getIssueInputWindow(), &IssueInputWindow::submitted, this, &IssuesListWidget::requestIssueCreation);

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
            connect(issueWidget, &IssueWidget::closed, [this, issue, issueWidget]() {
                issueWidget->setLoading(true);
                ServiceMediator::closeIssue(projectId, issue.iid, [this, issueWidget](CALLBACK_SIGNATURE) {
                    // TODO: You know what, this loading thing should become false when the result of next
                    // request is received, unless we have a gap between falsifying loading and hiding close issue
                    issueWidget->setLoading(false);
                    if (status == ResponseStatus::SUCCESSFUL) {
                        DataStore::getInstance().refreshProjectOpenIssues(projectId);
                    }
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

void IssuesListWidget::requestIssueCreation(const QString &issueTitle) {

    ModalManager::getInstance().getIssueInputWindow()->setLoading(true);
    ServiceMediator::createIssue(projectId, issueTitle, [this](CALLBACK_SIGNATURE) {
        ModalManager::getInstance().getIssueInputWindow()->setLoading(false);
        if (status == ResponseStatus::SUCCESSFUL) {
            ModalManager::getInstance().hideIssueInputWindow();
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
}
