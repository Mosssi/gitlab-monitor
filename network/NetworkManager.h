#ifndef GITLAB_DESKTOP_MONITOR_NETWORKMANAGER_H
#define GITLAB_DESKTOP_MONITOR_NETWORKMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>

#include "ResponseStatus.h"

#define CALLBACK_SIGNATURE const QJsonValue &jsonValue, ResponseStatus status
typedef std::function<void(CALLBACK_SIGNATURE)> CallbackFunction;

class NetworkManager {
private:
    friend class ServiceMediator;

    NetworkManager();
    static NetworkManager &getInstance();
    void post(const QString &url, const QJsonObject &body, const CallbackFunction &callback);
    void get(const QString &url, const CallbackFunction &callback);
    static void processReply(QNetworkReply * reply, const CallbackFunction &callback);

    QNetworkAccessManager * networkAccessManager;
};


#endif //GITLAB_DESKTOP_MONITOR_NETWORKMANAGER_H
