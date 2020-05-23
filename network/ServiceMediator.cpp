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
                            {"simple",     "true"},
                            {"order_by",   "last_activity_at"},
                            {"archived",   "false"},
                            {"membership", "true"},
                            {"per_page",   "30"}
                    }
            ),
            callback
    );
}
