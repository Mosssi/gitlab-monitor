#include "IssueInputWidget.h"

#include <QtWidgets/QHBoxLayout>

IssueInputWidget::IssueInputWidget() : QFrame(nullptr) {

    setupUi();
}

void IssueInputWidget::setupUi() {

    auto * mainLayout = new QHBoxLayout(this);

    issueTitleInput = new LineEdit();
    mainLayout->addWidget(issueTitleInput);

    auto * cancelButton = new PushButton(IconType::CLOSE);
    createButton = new PushButton(IconType::DONE);

    mainLayout->addWidget(cancelButton);
    mainLayout->addWidget(createButton);

    connect(cancelButton, &PushButton::clicked, this, &IssueInputWidget::cancelled);

    connect(createButton, &PushButton::clicked, [this]() { emit submitted(issueTitleInput->text()); });
}

void IssueInputWidget::clearInput() {

    issueTitleInput->clear();
}

void IssueInputWidget::setLoading(bool loading) {

    createButton->setLoading(loading);
}
