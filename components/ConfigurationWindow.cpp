#include "ConfigurationWindow.h"

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QCheckBox>

#include "../utilities/GuiManager.h"
#include "library/Label.h"
#include "library/PushButton.h"
#include "../utilities/Configuration.h"

ConfigurationWindow::ConfigurationWindow(QWidget * parent) : Frame(parent) {

    setBackgroundColor("#44000000");
    setFixedSize(GuiManager::applicationWidth(), GuiManager::applicationHeight());
    setupUi();
}

void ConfigurationWindow::setupUi() {

    auto * mainWidget = new QWidget(this);
    auto * mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->addWidget(new Label("Configuration"));

    auto * themeLayout = new QHBoxLayout();
    themeLayout->addWidget(new Label("Dark Theme"));
    themeLayout->addStretch();
    auto * darkThemeCheckbox = new QCheckBox();
    themeLayout->addWidget(darkThemeCheckbox);
    connect(darkThemeCheckbox, &QCheckBox::toggled, &Configuration::getInstance(), &Configuration::setDarkTheme);

    auto * issuesLayout = new QHBoxLayout();
    issuesLayout->addWidget(new Label("Assigned To Me"));
    issuesLayout->addStretch();
    auto * assignedToMeCheckbox = new QCheckBox();
    issuesLayout->addWidget(assignedToMeCheckbox);

    mainLayout->addLayout(themeLayout);
    mainLayout->addLayout(issuesLayout);

    auto * doneButton = new PushButton(IconType::DONE);
    connect(doneButton, &PushButton::clicked, [this]() {
        GuiManager::getApplicationWindow()->hideConfiguration();
    });
    mainLayout->addWidget(doneButton, 0, Qt::AlignCenter);

    mainWidget->setFixedSize(GuiManager::configurationWindowWidth(), GuiManager::configurationWindowHeight());
    mainWidget->setStyleSheet("border-radius: 6px;");
    mainWidget->move(
            (GuiManager::applicationWidth() - GuiManager::configurationWindowWidth()) / 2,
            (GuiManager::applicationHeight() - GuiManager::configurationWindowHeight()) / 2
    );
}
