#ifndef GITLAB_DESKTOP_MONITOR_DATASTORE_H
#define GITLAB_DESKTOP_MONITOR_DATASTORE_H

#include <QtCore/QMap>

#include "../models/User.h"
#include "../models/Project.h"

class DataStore : public QObject {
Q_OBJECT
public:
    static DataStore &getInstance();
    void initialize();
    [[nodiscard]] User getUser() const;
    [[nodiscard]] Project getProject(int projectId) const;
    [[nodiscard]] QList<Project> getProjects() const;

signals:
    void userReceived(const User &user);
    void projectsReceived();

private:
    User user;
    QMap<int, Project> projects;
};


#endif //GITLAB_DESKTOP_MONITOR_DATASTORE_H
