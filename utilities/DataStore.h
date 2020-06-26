#ifndef GITLAB_DESKTOP_MONITOR_DATASTORE_H
#define GITLAB_DESKTOP_MONITOR_DATASTORE_H

#include <QtCore/QMap>

#include "../models/User.h"
#include "../models/Project.h"

class DataStore : public QObject {
Q_OBJECT
    friend class ServiceMediator;
public:
    static DataStore &getInstance();
    void initialize();
    [[nodiscard]] User getUser() const;
    [[nodiscard]] Project getProject(int projectId) const;
    [[nodiscard]] QList<Project> getProjects() const;
    void updateProject(const Project &project);
    void refreshUser();
    void refreshProjects();
    void refreshProjectOpenIssues(int projectId);
    // TO-CONSIDER: I don't like the difference between ways of calling and using these functions

signals:
    void userReceived();
    void userReceiveFailed();
    void projectsReceived();
    void projectsReceiveFailed();
    void projectOpenIssuesReceived();
    void projectOpenIssuesReceiveFailed();

private:
    User user;
    QMap<int, Project> projects;
};


#endif //GITLAB_DESKTOP_MONITOR_DATASTORE_H
