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
    connect(&Configuration::getInstance(), &Configuration::themeChanged, [this]() {
        darkThemeSwitch->setChecked(Configuration::getInstance().getTheme() == ThemeMode::DARK);
    });
#ifndef NO_AUTO_START
    connect(&Configuration::getInstance(), &Configuration::autoStartChanged, [this]() {
        autoStartSwitch->setChecked(Configuration::getInstance().getAutoStart());
    });
#endif
    connect(&Configuration::getInstance(), &Configuration::assignedToMeChanged, [this]() {
        assignedToMeSwitch->setChecked(Configuration::getInstance().getAssignedToMe());
    });
}

void ConfigurationWindow::setupUi() {

    mainLayout->setContentsMargins(0, 5, 0, 5);

    auto * themeFrame = new HoverClickFrame();
    themeFrame->setGeneralStyle("border-radius: 0");
    auto * themeLayout = new QHBoxLayout(themeFrame);
    themeLayout->addWidget(new Label("Dark Theme"));
    themeLayout->addStretch();
    darkThemeSwitch = new ToggleSwitch(Configuration::getInstance().getTheme() == ThemeMode::DARK);
    themeLayout->addWidget(darkThemeSwitch);
    connect(themeFrame, &HoverClickFrame::clicked, [this]() {
        Configuration::getInstance().setTheme(Configuration::getInstance().getTheme() == ThemeMode::LIGHT ? ThemeMode::DARK : ThemeMode::LIGHT);
    });
    mainLayout->addWidget(themeFrame);

#ifndef NO_AUTO_START
    auto * autoStartFrame = new HoverClickFrame();
    autoStartFrame->setGeneralStyle("border-radius: 0");
    auto * autoStartLayout = new QHBoxLayout(autoStartFrame);
    autoStartLayout->addWidget(new Label("Launch on Startup"));
    autoStartLayout->addStretch();
    autoStartSwitch = new ToggleSwitch(Configuration::getInstance().getAutoStart());
    autoStartLayout->addWidget(autoStartSwitch);
    connect(autoStartFrame, &HoverClickFrame::clicked, [this]() {
        Configuration::getInstance().setAutoStart(!Configuration::getInstance().getAutoStart());
    });
    mainLayout->addWidget(autoStartFrame);
#endif

    auto * issuesFrame = new HoverClickFrame();
    issuesFrame->setGeneralStyle("border-radius: 0");
    auto * issuesLayout = new QHBoxLayout(issuesFrame);
    issuesLayout->addWidget(new Label("Filter Assigned To Me"));
    issuesLayout->addStretch();
    assignedToMeSwitch = new ToggleSwitch(Configuration::getInstance().getAssignedToMe());
    issuesLayout->addWidget(assignedToMeSwitch);
    connect(issuesFrame, &HoverClickFrame::clicked, [this]() {
        Configuration::getInstance().setAssignedToMe(!Configuration::getInstance().getAssignedToMe());
    });
    mainLayout->addWidget(issuesFrame);

    auto * logoutFrame = new HoverClickFrame();
    logoutFrame->setGeneralStyle("border-radius: 0");
    auto * logoutLayout = new QHBoxLayout(logoutFrame);
    logoutLayout->addWidget(new Label("Logout"));
    logoutLayout->addStretch();
    connect(logoutFrame, &HoverClickFrame::clicked, [this]() {
        GuiManager::getApplicationWindow()->logout();
        emit closed();
    });
    mainLayout->addWidget(logoutFrame);
}
