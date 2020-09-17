#include "ConfigurationWindow.h"

#include <QtWidgets/QVBoxLayout>

#include "../utilities/Configuration.h"
#include "../utilities/GuiManager.h"
#include "library/HoverClickFrame.h"
#include "library/Label.h"
#include "library/ModalToggle.h"
#include "library/ToggleSwitch.h"

ConfigurationWindow::ConfigurationWindow(QWidget * parent) : Modal("CONFIGURATION", parent) {

    setupUi();
    connect(&Configuration::getInstance(), &Configuration::themeChanged, [this]() {
        themeToggle->setChecked(Configuration::getInstance().getTheme() == ThemeMode::DARK);
    });
#ifndef NO_AUTO_START
    connect(&Configuration::getInstance(), &Configuration::autoStartChanged, [this]() {
        autoStartToggle->setChecked(Configuration::getInstance().getAutoStart());
    });
#endif
    connect(&Configuration::getInstance(), &Configuration::assignedToMeChanged, [this]() {
        filterAssigneeToggle->setChecked(Configuration::getInstance().getAssignedToMe());
    });
}

void ConfigurationWindow::setupUi() {

    mainLayout->setContentsMargins(0, 5, 0, 5);

    themeToggle = new ModalToggle("Dark Theme", Configuration::getInstance().getTheme() == ThemeMode::DARK);
    connect(themeToggle, &HoverClickFrame::clicked, []() {
        Configuration::getInstance().setTheme(Configuration::getInstance().getTheme() == ThemeMode::LIGHT ? ThemeMode::DARK : ThemeMode::LIGHT);
    });
    mainLayout->addWidget(themeToggle);

#ifndef NO_AUTO_START
    autoStartToggle = new ModalToggle("Launch on Startup", Configuration::getInstance().getAutoStart());
    connect(autoStartToggle, &HoverClickFrame::clicked, []() {
        Configuration::getInstance().setAutoStart(!Configuration::getInstance().getAutoStart());
    });
    mainLayout->addWidget(autoStartToggle);
#endif

    filterAssigneeToggle = new ModalToggle("Filter Assigned To Me", Configuration::getInstance().getAssignedToMe());
    connect(filterAssigneeToggle, &HoverClickFrame::clicked, []() {
        Configuration::getInstance().setAssignedToMe(!Configuration::getInstance().getAssignedToMe());
    });
    mainLayout->addWidget(filterAssigneeToggle);

    auto * logoutFrame = new HoverClickFrame();
    logoutFrame->setFixedHeight(GuiManager::configurationItemHeight());
    logoutFrame->setGeneralStyle("border-radius: 0");
    auto * logoutLayout = new QHBoxLayout(logoutFrame);
    logoutLayout->setContentsMargins(10, 0, 10, 0);
    logoutLayout->addWidget(new Label("Logout"));
    logoutLayout->addStretch();
    connect(logoutFrame, &HoverClickFrame::clicked, [this]() {
        GuiManager::getApplicationWindow()->logout();
        emit closed();
    });
    mainLayout->addWidget(logoutFrame);
}
