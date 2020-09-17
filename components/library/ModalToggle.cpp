#include "ModalToggle.h"

#include <QtWidgets/QHBoxLayout>

#include "../../utilities/GuiManager.h"
#include "Label.h"

ModalToggle::ModalToggle(const QString &text, bool checked, QWidget * parent) : HoverClickFrame(parent) {

    setupUi(text, checked);
}

void ModalToggle::setupUi(const QString &text, bool checked) {

    setFixedHeight(GuiManager::configurationItemHeight());
    setGeneralStyle("border-radius: 0");

    auto * mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(10, 0, 10, 0);

    mainLayout->addWidget(new Label(text));
    mainLayout->addStretch();
    toggleSwitch = new ToggleSwitch(checked);
    mainLayout->addWidget(toggleSwitch);
}

bool ModalToggle::isChecked() {

    return toggleSwitch->isChecked();
}

void ModalToggle::setChecked(bool checked) {

    toggleSwitch->setChecked(checked);
}
