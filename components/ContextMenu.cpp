#include <QtWidgets/QVBoxLayout>
#include "ContextMenu.h"
#include "ContextMenuButton.h"

ContextMenu::ContextMenu() : QWidget(nullptr) {

//    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    setupUi();
}

void ContextMenu::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    auto * openButton = new ContextMenuButton("Open GitLab Monitor");
    auto * exitButton = new ContextMenuButton("Exit");
    mainLayout->addWidget(openButton);
    mainLayout->addWidget(exitButton);
    mainLayout->setSpacing(2);
    mainLayout->setContentsMargins(4, 4, 4, 4);

    connect(openButton, &ContextMenuButton::clicked, [this]() { emit openClicked(); });
    connect(exitButton, &ContextMenuButton::clicked, [this]() { emit exitClicked(); });
}
