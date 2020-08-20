#ifndef GITLAB_DESKTOP_MONITOR_NETWORKMANAGER_H
#define GITLAB_DESKTOP_MONITOR_NETWORKMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>

#include "ResponseStatus.h"

#define CALLBACK_SIGNATURE const QJsonValue &jsonValue, ResponseStatus status
typedef std::function<void(CALLBACK_SIGNATURE)> CallbackFunction;

class NetworkManager : public QObject {
Q_OBJECT
private:
    friend class ServiceMediator;

    NetworkManager();
    static NetworkManager &getInstance();
    void get(const QString &url, const CallbackFunction &callback);
    void post(const QString &url, const QJsonObject &body, const CallbackFunction &callback);
    void put(const QString &url, const QJsonObject &body, const CallbackFunction &callback);
    static void processReply(QNetworkReply * reply, const CallbackFunction &callback);
    static ResponseStatus getResponseStatus(QNetworkReply::NetworkError error);

    QNetworkAccessManager * networkAccessManager;

signals:
    void networkError();
    void networkOk();
};


#endif //GITLAB_DESKTOP_MONITOR_NETWORKMANAGER_H
