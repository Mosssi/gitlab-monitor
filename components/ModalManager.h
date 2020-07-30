#ifndef GITLAB_DESKTOP_MONITOR_MODALMANAGER_H
#define GITLAB_DESKTOP_MONITOR_MODALMANAGER_H


#include "ConfigurationWindow.h"
#include "IssueInputWindow.h"

class ModalManager : public QObject {
Q_OBJECT
public:
    static ModalManager &getInstance();
    void showConfigurationWindow();
    void hideConfigurationWindow();
    void showIssueInputWindow();
    void hideIssueInputWindow();
    ConfigurationWindow * getConfigurationWindow();
    IssueInputWindow * getIssueInputWindow();

private:
    explicit ModalManager();

    ConfigurationWindow * configurationWindow = nullptr;
    IssueInputWindow * issueInputWindow = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_MODALMANAGER_H
