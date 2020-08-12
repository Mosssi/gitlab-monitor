#include <QtWidgets/QHBoxLayout>
#include "ModalToggle.h"
#include "Label.h"

ModalToggle::ModalToggle(const QString &text, bool checked, QWidget * parent) : HoverClickFrame(parent) {

    setupUi(text, checked);
}

void ModalToggle::setupUi(const QString &text, bool checked) {

    setGeneralStyle("border-radius: 0");

    auto * mainLayout = new QHBoxLayout(this);

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
