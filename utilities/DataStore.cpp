#include "DataStore.h"

#include <QJsonArray>

#include "../network/ServiceMediator.h"

DataStore &DataStore::getInstance() {

    static DataStore instance;
    return instance;
}

void DataStore::initialize() {

    ServiceMediator::requestUser([this](CALLBACK_SIGNATURE) {
        if (status == ResponseStatus::SUCCESSFUL) {
            user = User(jsonValue.toObject());
            emit userReceived(user);
            ServiceMediator::requestProjects(user.id, true, [this](CALLBACK_SIGNATURE) {
                if (status == ResponseStatus::SUCCESSFUL) {
                    for (const auto &projectJsonValue: jsonValue.toArray()) {
                        const Project &project = Project(projectJsonValue.toObject());
                        projects.insert(project.id, project);
                    }
                    emit projectsReceived();
                }
            });
        }
    });
}

User DataStore::getUser() const {

    return user;
}

Project DataStore::getProject(int projectId) const {

    return projects.value(projectId);
}

QList<Project> DataStore::getProjects() const {

    return projects.values();
}
