#include "IssuesListWidget.h"

#include "library/ScrollArea.h"
#include "../utilities/DataStore.h"
#include "IssueWidget.h"
#include "library/PushButton.h"


IssuesListWidget::IssuesListWidget(QWidget * parent) : QFrame(parent) {

    setupUi();
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
        issueInputWidget->setVisible(false);
        emit backClicked();
    });
    headerLayout->addWidget(backButton);
    headerLayout->addWidget(projectNameLabel = new Label());
    auto * createIssueButton = new PushButton(IconType::NEW);
    headerLayout->addStretch();
    headerLayout->addWidget(createIssueButton);
    connect(createIssueButton, &PushButton::clicked, [this]() {
        issueInputWidget->setVisible(true);
        issueInputWidget->setProjectId(projectId);
    });
    projectNameLabel->setColor(GuiManager::lightGrayColor());

    mainLayout->addWidget(headerFrame);

    mainLayout->addWidget(issueInputWidget = new IssueInputWidget());
    issueInputWidget->setVisible(false);

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
        scrollLayout->addWidget(issueWidget);
    }
}

void IssuesListWidget::setProjectId(int projectId) {

    this->projectId = projectId;

    emptyScrollLayout();
    updateUi(); // Filling UI with old contents

    DataStore::getInstance().getProjectOpenIssues(projectId);

    connect(&DataStore::getInstance(), &DataStore::projectOpenIssuesReceived, this, &IssuesListWidget::updateUi);
}

void IssuesListWidget::emptyScrollLayout() {

    QLayoutItem * child;
    while ((child = scrollLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}
