#ifndef GITLAB_DESKTOP_MONITOR_NETWORKMANAGER_H
#define GITLAB_DESKTOP_MONITOR_NETWORKMANAGER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>

#include "ResponseStatus.h"
#include "ServiceMediator.h"

#define SERVICE_ADDRESS "https://gitlab.com/api/v4"

typedef std::function<void(const QJsonObject &, ResponseStatus)> CallbackFunction;

class NetworkManager {
private:
    friend class ServiceMediator;

    NetworkManager();
    static NetworkManager &getInstance();
    void post(const QString &url, const QJsonObject &body, const CallbackFunction &callback);
    void get(const QString &url, const CallbackFunction &callback);
    static void processReply(QNetworkReply * reply, const CallbackFunction &callback);
    static QString getCompleteUrl(const QString &url);

    QNetworkAccessManager * networkAccessManager;
};


#endif //GITLAB_DESKTOP_MONITOR_NETWORKMANAGER_H
