#include "IssueInputWidget.h"

#include <QtWidgets/QHBoxLayout>

#include "library/PushButton.h"
#include "../network/ServiceMediator.h"

IssueInputWidget::IssueInputWidget() : QFrame(nullptr) {

    setupUi();
}

void IssueInputWidget::setProjectId(int projectId) {

    this->projectId = projectId;
}

void IssueInputWidget::setupUi() {

    auto * mainLayout = new QHBoxLayout(this);

    issueTitleInput = new LineEdit();
    mainLayout->addWidget(issueTitleInput);

    auto * cancelButton = new PushButton(IconType::CLOSE);
    auto * createButton = new PushButton(IconType::DONE);

    mainLayout->addWidget(cancelButton);
    mainLayout->addWidget(createButton);

    connect(cancelButton, &PushButton::clicked, [this]() {
        setVisible(false);
        issueTitleInput->clear();
    });

    connect(createButton, &PushButton::clicked, [this]() {
        ServiceMediator::createIssue(projectId, issueTitleInput->text(), [this](CALLBACK_SIGNATURE) {
            if (status == ResponseStatus::SUCCESSFUL) {
                setVisible(false);
                issueTitleInput->clear();
            }
        });
    });
}

void IssueInputWidget::clearInput() {

    issueTitleInput->clear();
}
