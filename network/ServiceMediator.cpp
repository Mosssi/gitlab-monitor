#include "ServiceMediator.h"

#include <QUrl>
#include <QUrlQuery>

#include "../utilities/Configuration.h"

#define SERVICE_ADDRESS "https://gitlab.com/api/v4"

QString ServiceMediator::getUrl(const QString &url, const QList<QPair<QString, QString>> &queries) {

    QUrl qUrl(SERVICE_ADDRESS + url);
    QUrlQuery urlQuery;
    for (const auto &pair : queries) {
        urlQuery.addQueryItem(pair.first, pair.second);
    }
    urlQuery.addQueryItem("private_token", Configuration::getInstance().getToken());
    qUrl.setQuery(urlQuery);

    return qUrl.toString();
}

// TODO: Consider making required changes on DataStore right here
void ServiceMediator::requestUser(const CallbackFunction &callback) {
    NetworkManager::getInstance().get(
            getUrl("/user"),
            callback
    );
}

void ServiceMediator::requestProjects(const CallbackFunction &callback) {
    NetworkManager::getInstance().get(
            getUrl(
                    "/projects",
                    {
                            {"order_by",   "last_activity_at"},
                            {"archived",   "false"},
                            {"membership", "true"},
                            {"starred",    "true"}
                    }
            ),
            callback
    );
}

void ServiceMediator::requestProject(int projectId, const CallbackFunction &callback) {
    NetworkManager::getInstance().get(
            getUrl(QString("/project/%1").arg(projectId)),
            callback
    );
}

void ServiceMediator::requestProjectOpenIssues(int projectId, const CallbackFunction &callback) {
    NetworkManager::getInstance().get(
            getUrl(QString("/projects/%1/issues").arg(projectId), {{"state", "opened"}}),
            callback
    );
}

void ServiceMediator::closeIssue(int projectId, int issueId, const CallbackFunction &callback) {
    NetworkManager::getInstance().put(
            getUrl(QString("/projects/%1/issues/%2").arg(projectId).arg(issueId), {{"state_event", "close"}}),
            {},
            callback
    );
}

void ServiceMediator::createIssue(int projectId, const QString &title, const CallbackFunction &callback) {
    NetworkManager::getInstance().post(
            getUrl(QString("/projects/%1/issues").arg(projectId), {{"title", title}}),
            {},
            callback
    );
}
