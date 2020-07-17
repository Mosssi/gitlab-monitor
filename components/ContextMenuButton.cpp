#include "ContextMenuButton.h"

#include <QtWidgets/QHBoxLayout>

#include "library/Label.h"

ContextMenuButton::ContextMenuButton(const QString &text, QWidget * parent) : HoverClickFrame(parent), text(text) {

    setFixedWidth(GuiManager::contextMenuButtonWidth());
    setupUi();
}

void ContextMenuButton::setupUi() {

    auto * mainLayout = new QHBoxLayout(this);
    auto * label = new Label(text);
    label->setFontSize(GuiManager::smallFontSize());

    mainLayout->addWidget(label);
}
