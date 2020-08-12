#include "IssueInputWindow.h"

#include <QtWidgets/QHBoxLayout>

IssueInputWindow::IssueInputWindow(QWidget * parent) : Modal("NEW ISSUE", parent) {

    setupUi();
}

void IssueInputWindow::setupUi() {

    issueTitleInput = new LineEdit();
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->addWidget(issueTitleInput);

    createButton = new PushButton(IconType::DONE);

    auto * buttonsLayout = new QHBoxLayout();
    buttonsLayout->setAlignment(Qt::AlignCenter);
    buttonsLayout->addWidget(createButton);
    mainLayout->addLayout(buttonsLayout);

    connect(createButton, &PushButton::clicked, [this]() { emit submitted(issueTitleInput->text()); });
}

void IssueInputWindow::clearInput() {

    issueTitleInput->clear();
}

void IssueInputWindow::setLoading(bool loading) {

    createButton->setLoading(loading);
}
