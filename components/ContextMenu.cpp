#include "ContextMenu.h"

#include <QtWidgets/QVBoxLayout>

#include "ContextMenuButton.h"

ContextMenu::ContextMenu() : Frame(nullptr) {

    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    setupUi();
}

void ContextMenu::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    auto * openButton = new ContextMenuButton("Open GitLab Monitor");
    auto * exitButton = new ContextMenuButton("Exit");
    mainLayout->addWidget(openButton);
    mainLayout->addWidget(exitButton);
    mainLayout->setSpacing(1);
    mainLayout->setContentsMargins(3, 3, 3, 3);

    connect(openButton, &ContextMenuButton::clicked, [this]() { emit openClicked(); });
    connect(exitButton, &ContextMenuButton::clicked, [this]() { emit exitClicked(); });
}

void ContextMenu::updateStyleSheet() {

    setBackgroundColor(GuiManager::getTheme().backgroundColor());
}
