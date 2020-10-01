#include "IssueInputWindow.h"

#include <QtWidgets/QHBoxLayout>
#include <QKeyEvent>

#include "../utilities/GuiManager.h"
#include "library/Label.h"

IssueInputWindow::IssueInputWindow(QWidget * parent) : Modal("NEW ISSUE", parent) {

    setupUi();
}

void IssueInputWindow::setupUi() {

    issueTitleInput = new LineEdit();
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->addWidget(new Label("Title:", GuiManager::smallFontSize(), TextColor::TERTIARY));
    mainLayout->addWidget(issueTitleInput);
    connect(issueTitleInput, &LineEdit::textChanged, [this]() {
        issueTitleInput->setHasError(false);
    });

    auto * assignToMeLayout = new QHBoxLayout();
    assignToMeLayout->setContentsMargins(0, 10, 0, 10);
    assignToMeLayout->addWidget(new Label("Assign To Me"));
    assignToMeLayout->addWidget(assignToMe = new ToggleSwitch());
    connect(assignToMe, &ToggleSwitch::clicked, [this]() {
        assignToMe->setChecked(!assignToMe->isChecked());
    });
    mainLayout->addLayout(assignToMeLayout);

    createButton = new PushButton(IconType::DONE);

    auto * buttonsLayout = new QHBoxLayout();
    buttonsLayout->setAlignment(Qt::AlignCenter);
    buttonsLayout->addWidget(createButton);
    mainLayout->addLayout(buttonsLayout);

    connect(createButton, &PushButton::clicked, this, &IssueInputWindow::submit);
}

void IssueInputWindow::clearInput() {

    issueTitleInput->clear();
    issueTitleInput->setHasError(false);
    assignToMe->setChecked(false);
}

void IssueInputWindow::setLoading(bool loading) {

    createButton->setLoading(loading);
}

void IssueInputWindow::keyPressEvent(QKeyEvent * event) {

    if (event->key() == Qt::Key_Return) {
        submit();
    }
    QWidget::keyPressEvent(event);
}

void IssueInputWindow::submit() {
    if (issueTitleInput->text().isEmpty()) {
        issueTitleInput->setHasError(true);
    } else {
        emit submitted(issueTitleInput->text(), assignToMe->isChecked());
    }
}
