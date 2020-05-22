#include "ServiceMediator.h"

#include <QUrl>
#include <QUrlQuery>

#include "../utilities/Configuration.h"

#define SERVICE_ADDRESS "https://gitlab.com/api/v4"

void ServiceMediator::requestUser(const CallbackFunction &callback) {
    NetworkManager::getInstance().get(
            getUrl("/user"),
            callback
    );
}

void ServiceMediator::requestProjects(const int &userId, bool simple, const CallbackFunction &callback) {
    NetworkManager::getInstance().get(
            getUrl(QString("/users/%1/projects").arg(userId), {{"simple", simple ? "true" : "false"}}),
            callback
    );
}

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
