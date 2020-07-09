#include "ConfigurationWindow.h"

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QCheckBox>

#include "../utilities/GuiManager.h"
#include "library/Label.h"

ConfigurationWindow::ConfigurationWindow(QWidget * parent) : Frame(parent) {

    setBackgroundColor(GuiManager::darkLightColor());
    setFixedSize(GuiManager::ConfigurationWindowWidth(), GuiManager::ConfigurationWindowHeight());
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
}
