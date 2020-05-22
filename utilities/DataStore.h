#ifndef GITLAB_DESKTOP_MONITOR_DATASTORE_H
#define GITLAB_DESKTOP_MONITOR_DATASTORE_H

#include "../models/User.h"
#include "../models/Project.h"

class DataStore : public QObject {
Q_OBJECT
public:
    static DataStore &getInstance();
    void initialize();
    [[nodiscard]] User getUser() const;

signals:
    void userReceived(const User &user);
    void projectsReceived();

private:
    User user;
    QList<Project> projects;
};


#endif //GITLAB_DESKTOP_MONITOR_DATASTORE_H
