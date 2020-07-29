#include "ConfigurationWindow.h"

#include <QtWidgets/QVBoxLayout>

#include "../utilities/Configuration.h"
#include "../utilities/GuiManager.h"
#include "library/Label.h"
#include "library/PushButton.h"
#include "library/ToggleSwitch.h"
#include "library/HoverClickFrame.h"

ConfigurationWindow::ConfigurationWindow(QWidget * parent) : Modal("CONFIGURATION", parent) {

    setupUi();
}

void ConfigurationWindow::setupUi() {

    mainLayout->setContentsMargins(0, 5, 0, 5);

    auto * themeFrame = new HoverClickFrame();
    themeFrame->setGeneralStyle("border-radius: 0");
    auto * themeLayout = new QHBoxLayout(themeFrame);
    themeLayout->addWidget(new Label("Dark Theme"));
    themeLayout->addStretch();
    auto * darkThemeSwitch = new ToggleSwitch();
    darkThemeSwitch->setChecked(Configuration::getInstance().getTheme() == ThemeMode::DARK);
    themeLayout->addWidget(darkThemeSwitch);
    connect(darkThemeSwitch, &ToggleSwitch::toggled, [this](bool checked) {
        Configuration::getInstance().setTheme(checked ? ThemeMode::DARK : ThemeMode::LIGHT);
    });
    connect(themeFrame, &HoverClickFrame::clicked, [darkThemeSwitch]() {
        darkThemeSwitch->toggleState();
    });

    auto * issuesFrame = new HoverClickFrame();
    issuesFrame->setGeneralStyle("border-radius: 0");
    auto * issuesLayout = new QHBoxLayout(issuesFrame);
    issuesLayout->addWidget(new Label("Assigned To Me"));
    issuesLayout->addStretch();
    auto * assignedToMeSwitch = new ToggleSwitch();
    assignedToMeSwitch->setChecked(Configuration::getInstance().getAssignedToMe());
    issuesLayout->addWidget(assignedToMeSwitch);
    connect(assignedToMeSwitch, &ToggleSwitch::toggled, &Configuration::getInstance(), &Configuration::setAssignedToMe);
    connect(issuesFrame, &HoverClickFrame::clicked, [assignedToMeSwitch]() {
        assignedToMeSwitch->toggleState();
    });

    auto * logoutFrame = new HoverClickFrame();
    logoutFrame->setGeneralStyle("border-radius: 0");
    auto * logoutLayout = new QHBoxLayout(logoutFrame);
    logoutLayout->addWidget(new Label("Logout"));
    logoutLayout->addStretch();
    connect(logoutFrame, &HoverClickFrame::clicked, [this]() {
        GuiManager::getApplicationWindow()->logout();
        emit closed();
    });

    mainLayout->addWidget(themeFrame);
    mainLayout->addWidget(issuesFrame);
    mainLayout->addWidget(logoutFrame);
}
