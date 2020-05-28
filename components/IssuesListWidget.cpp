#include "IssuesListWidget.h"

#include <QtWidgets/QPushButton>

#include "library/ScrollArea.h"
#include "../utilities/DataStore.h"
#include "IssueWidget.h"


IssuesListWidget::IssuesListWidget(QWidget * parent) : QFrame(parent) {

    setupUi();
}

void IssuesListWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    auto * headerFrame = new QFrame(); // TOCONSIDER: What about having our own layout with setBackgroundColor functionality?
    headerFrame->setStyleSheet("background-color: " + GuiManager::lightColor() + ";"); // TODO: fix design
    auto * headerLayout = new QHBoxLayout(headerFrame);
    headerLayout->setContentsMargins(5, 5, 5, 5);
    auto * backButton = new QPushButton("<");
    connect(backButton, &QPushButton::clicked, this, &IssuesListWidget::backClicked);
    headerLayout->addWidget(backButton);
    headerLayout->addWidget(projectNameLabel = new Label());

    mainLayout->addWidget(headerFrame);

    scrollLayout = new QVBoxLayout();
    scrollLayout->setContentsMargins(0, 0, 0, 0);
    scrollLayout->setSpacing(0);
    scrollLayout->setAlignment(Qt::AlignTop);

    mainLayout->addWidget(new ScrollArea(scrollLayout));
}

void IssuesListWidget::updateUi() {

    emptyScrollLayout();

    const auto &project = DataStore::getInstance().getProject(projectId);

    projectNameLabel->setText(project.name);

    for (const auto &issue: project.openIssues) {
        auto * issueWidget = new IssueWidget(issue);
        scrollLayout->addWidget(issueWidget);
    }
}

void IssuesListWidget::setProjectId(int projectId) {

    bool projectChanged = this->projectId != projectId;
    this->projectId = projectId;

    if (projectChanged) {
        projectNameLabel->setText("");
        emptyScrollLayout();
    }

    DataStore::getInstance().getProjectOpenIssues(projectId);

    connect(&DataStore::getInstance(), &DataStore::projectOpenIssuesReceived, this, &IssuesListWidget::updateUi);
}

void IssuesListWidget::emptyScrollLayout() {

    QLayoutItem *child;
    while ((child = scrollLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}
