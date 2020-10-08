#include "ModalManager.h"

#include "../utilities/GuiManager.h"

ModalManager &ModalManager::getInstance() {

    static ModalManager modalManager;
    return modalManager;
}

ModalManager::ModalManager() : QObject() {

    configurationWindow = new ConfigurationWindow(GuiManager::getApplicationWindow());
    issueInputWindow = new IssueInputWindow(GuiManager::getApplicationWindow());

    configurationWindow->move(0, 0);
    configurationWindow->hide();
    QObject::connect(configurationWindow, &Modal::closed, this, &ModalManager::hideConfigurationWindow);

    issueInputWindow->move(0, 0);
    issueInputWindow->hide();
    QObject::connect(issueInputWindow, &Modal::closed, this, &ModalManager::hideIssueInputWindow);
}

void ModalManager::showConfigurationWindow() {

    configurationWindow->setVisible(true);
}

void ModalManager::hideConfigurationWindow() {

    configurationWindow->setVisible(false);
}

void ModalManager::showIssueInputWindow() {

    issueInputWindow->setVisible(true);
}

void ModalManager::hideIssueInputWindow() {

    issueInputWindow->setVisible(false);
    issueInputWindow->clearInput();
}

ConfigurationWindow * ModalManager::getConfigurationWindow() {

    return configurationWindow;
}

IssueInputWindow * ModalManager::getIssueInputWindow() {

    return issueInputWindow;
}
