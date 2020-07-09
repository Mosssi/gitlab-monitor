#include "ConfigurationWindow.h"

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QCheckBox>

#include "../utilities/GuiManager.h"
#include "library/Label.h"
#include "library/PushButton.h"

ConfigurationWindow::ConfigurationWindow(QWidget * parent) : Frame(parent) {

    setBackgroundColor(GuiManager::lightColor());
    setFixedSize(GuiManager::configurationWindowWidth(), GuiManager::configurationWindowHeight());
    setGeneralStyle("border-radius: 5px;");
    setupUi();
}

void ConfigurationWindow::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new Label("Configuration"));

    auto * themeLayout = new QHBoxLayout();
    themeLayout->addWidget(new Label("Dark Theme"));
    themeLayout->addStretch();
    themeLayout->addWidget(new QCheckBox());

    auto * issuesLayout = new QHBoxLayout();
    issuesLayout->addWidget(new Label("Assigned To Me"));
    issuesLayout->addStretch();
    issuesLayout->addWidget(new QCheckBox());

    mainLayout->addLayout(themeLayout);
    mainLayout->addLayout(issuesLayout);

    auto * doneButton = new PushButton(IconType::DONE);
    connect(doneButton, &PushButton::clicked, [this]() {
        GuiManager::getApplicationWindow()->hideConfiguration();
    });
    mainLayout->addWidget(doneButton, 0, Qt::AlignCenter);
}
