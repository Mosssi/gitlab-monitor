#include "ServiceMediator.h"

#include <QUrl>
#include <QUrlQuery>

#include "../utilities/Configuration.h"

#define SERVICE_ADDRESS "https://gitlab.com/api/v4"

QString ServiceMediator::getUrl(const QString &url, const QList<QPair<QString, QString>> &queries) {

    QUrl qUrl(SERVICE_ADDRESS + url);
    QUrlQuery urlQuery;
    urlQuery.addQueryItem("private_token", Configuration::getInstance().getToken());
    for (const auto &pair : queries) {
        urlQuery.addQueryItem(pair.first, pair.second);
    }
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

void ServiceMediator::starProject(int projectId, const CallbackFunction &callback) {
    NetworkManager::getInstance().post(
            getUrl(QString("/projects/%1/star").arg(projectId)),
            {},
            callback
    );
}

void ServiceMediator::unStarProject(int projectId, const CallbackFunction &callback) {
    NetworkManager::getInstance().post(
            getUrl(QString("/projects/%1/unstar").arg(projectId)),
            {},
            callback
    );
}
