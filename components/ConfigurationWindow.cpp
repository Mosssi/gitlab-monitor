#include "ConfigurationWindow.h"

#include <QtWidgets/QVBoxLayout>

#include "../utilities/Configuration.h"
#include "../utilities/GuiManager.h"
#include "library/Label.h"
#include "library/PushButton.h"
#include "library/ToggleSwitch.h"

ConfigurationWindow::ConfigurationWindow(QWidget * parent) : Modal("CONFIGURATION", parent) {

    setupUi();
}

void ConfigurationWindow::setupUi() {

    auto * themeLayout = new QHBoxLayout();
    themeLayout->addWidget(new Label("Dark Theme"));
    themeLayout->addStretch();
    auto * darkThemeSwitch = new ToggleSwitch();
    darkThemeSwitch->setChecked(Configuration::getInstance().getTheme() == ThemeMode::DARK);
    themeLayout->addWidget(darkThemeSwitch);
    connect(darkThemeSwitch, &ToggleSwitch::toggled, [this](bool checked) {
        Configuration::getInstance().setTheme(checked ? ThemeMode::DARK : ThemeMode::LIGHT);
    });

    auto * issuesLayout = new QHBoxLayout();
    issuesLayout->addWidget(new Label("Assigned To Me"));
    issuesLayout->addStretch();
    auto * assignedToMeSwitch = new ToggleSwitch();
    assignedToMeSwitch->setChecked(Configuration::getInstance().getAssignedToMe());
    issuesLayout->addWidget(assignedToMeSwitch);
    connect(assignedToMeSwitch, &ToggleSwitch::toggled, &Configuration::getInstance(), &Configuration::setAssignedToMe);

    mainLayout->addLayout(themeLayout);
    mainLayout->addLayout(issuesLayout);

    auto * doneButton = new PushButton(IconType::DONE);
    connect(doneButton, &PushButton::clicked, [this]() {
        GuiManager::getApplicationWindow()->hideConfiguration();
    });
    mainLayout->addSpacing(10);
    mainLayout->addWidget(doneButton, 0, Qt::AlignCenter);

    auto * logoutButton = new PushButton(IconType::CLOSE);
    connect(logoutButton, &PushButton::clicked, [this]() {
        GuiManager::getApplicationWindow()->logout();
        GuiManager::getApplicationWindow()->hideConfiguration();
    });
    mainLayout->addWidget(logoutButton);
}
