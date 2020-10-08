#include "DataStore.h"

#include <QJsonArray>
#include <QtCore/QTimer>

#include "../network/ServiceMediator.h"

DataStore &DataStore::getInstance() {

    static DataStore instance;
    return instance;
}

void DataStore::initialize() {

    refreshUser();
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

    QList<Project> sortedProjects = projects.values();
    std::sort(sortedProjects.begin(), sortedProjects.end(), [](const Project &first, const Project &second) {
        return first.lastActivity > second.lastActivity;
    });
    return sortedProjects;
}

void DataStore::updateProject(const Project &project) {

    projects.insert(project.id, project);
}

void DataStore::refreshProjectOpenIssues(int projectId) {

    ServiceMediator::requestProjectOpenIssues(projectId, [this, projectId](CALLBACK_SIGNATURE) {
        if (status == ResponseStatus::SUCCESSFUL) {
            QList<Issue> projectOpenIssues;
            for (const auto &issueJsonValue: jsonValue.toArray()) {
                projectOpenIssues.append(Issue(issueJsonValue.toObject()));
            }
            Project project = getProject(projectId);
            project.setOpenIssues(projectOpenIssues);
            updateProject(project);

            emit projectOpenIssuesReceived();
        } else {
            emit projectOpenIssuesReceiveFailed();
        }
    });
}

void DataStore::refreshProjects() {

    ServiceMediator::requestProjects([this](CALLBACK_SIGNATURE) {
        if (status == ResponseStatus::SUCCESSFUL) {
            projects.clear();
            for (const auto &projectJsonValue: jsonValue.toArray()) {
                const Project &project = Project(projectJsonValue.toObject());
                projects.insert(project.id, project);
            }
            emit projectsReceived();
        } else {
            emit projectsReceiveFailed();
        }
    });
}

void DataStore::refreshUser() {

    ServiceMediator::requestUser([this](CALLBACK_SIGNATURE) {
        if (status == ResponseStatus::SUCCESSFUL) {
            user = User(jsonValue.toObject());
            refreshProjects();
            emit userReceived();
        } else {
            emit userReceiveFailed(status);
        }
    });
}

void DataStore::clear() {

    user = User();
    projects.clear();
}
