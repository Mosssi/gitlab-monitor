#include "ConfigurationWindow.h"

#include <QtWidgets/QVBoxLayout>

#include "../utilities/Configuration.h"
#include "../utilities/GuiManager.h"
#include "library/Label.h"
#include "library/PushButton.h"
#include "library/ToggleSwitch.h"

ConfigurationWindow::ConfigurationWindow(QWidget * parent) : Frame(parent) {

    setBackgroundColor("#44000000");
    setFixedSize(GuiManager::applicationWidth(), GuiManager::applicationHeight());
    setupUi();
}

void ConfigurationWindow::setupUi() {

    auto * mainWidget = new QWidget(this);
    auto * mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    auto * titleFrame = new Frame();
    auto * titleLayout = new QHBoxLayout(titleFrame);
    titleFrame->setBackgroundColor(GuiManager::darkLightColor());
    titleFrame->setGeneralStyle("border-bottom-left-radius: 0; border-bottom-right-radius: 0;");
    titleFrame->setFixedHeight(GuiManager::bodyHeaderHeight());
    auto titleLabel = new Label("CONFIGURATION");
    titleLabel->setColor(GuiManager::lightGrayColor());
    titleLayout->addWidget(titleLabel, 0, Qt::AlignVCenter | Qt::AlignLeft);

    mainLayout->addWidget(titleFrame);

    auto * themeLayout = new QHBoxLayout();
    themeLayout->addWidget(new Label("Dark Theme"));
    themeLayout->addStretch();
    auto * darkThemeSwitch = new ToggleSwitch();
    darkThemeSwitch->setChecked(Configuration::getInstance().getDarkTheme());
    themeLayout->addWidget(darkThemeSwitch);
    connect(darkThemeSwitch, &ToggleSwitch::toggled, &Configuration::getInstance(), &Configuration::setDarkTheme);

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
    mainLayout->addWidget(doneButton, 0, Qt::AlignCenter);

    mainWidget->setFixedSize(GuiManager::configurationWindowWidth(), GuiManager::configurationWindowHeight());
    mainWidget->setStyleSheet("border-radius: 6px;");
    mainWidget->move(
            (GuiManager::applicationWidth() - GuiManager::configurationWindowWidth()) / 2,
            (GuiManager::applicationHeight() - GuiManager::configurationWindowHeight()) / 2
    );
}
