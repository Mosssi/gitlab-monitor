#include "IssueInputWidget.h"

#include <QtWidgets/QHBoxLayout>

#include "library/PushButton.h"
#include "../network/ServiceMediator.h"

IssueInputWidget::IssueInputWidget() : QFrame(nullptr) {

    setupUi();
}

void IssueInputWidget::setupUi() {

    auto * mainLayout = new QHBoxLayout(this);

    issueTitleInput = new LineEdit();
    mainLayout->addWidget(issueTitleInput);

    auto * cancelButton = new PushButton(IconType::CLOSE);
    auto * createButton = new PushButton(IconType::DONE);

    mainLayout->addWidget(cancelButton);
    mainLayout->addWidget(createButton);

    connect(cancelButton, &PushButton::clicked, this, &IssueInputWidget::cancelled);

    connect(createButton, &PushButton::clicked, [this]() { emit submitted(issueTitleInput->text()); });
}

void IssueInputWidget::clearInput() {

    issueTitleInput->clear();
}
