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

            ServiceMediator::requestProjects([this](CALLBACK_SIGNATURE) {
                if (status == ResponseStatus::SUCCESSFUL) {
                    for (const auto &projectJsonValue: jsonValue.toArray()) {
                        const Project &project = Project(projectJsonValue.toObject());
                        projects.insert(project.id, project);
                    }
                }
                emit projectsReceived();
            });
        }
    });
}

User DataStore::getUser() const {

    return user;
}

Project DataStore::getProject(int projectId) const {

    for (const auto &project: projects) {
        if (project.id == projectId) {
            return project;
        }
    }

    return Project();
}

QList<Project> DataStore::getProjects() const {

    return projects.values();
}

void DataStore::updateProject(const Project &project) {

    projects.insert(project.id, project);
}
