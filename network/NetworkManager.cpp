#include "NetworkManager.h"

#include <QtCore/QJsonDocument>

#include "../utilities/Configuration.h"

NetworkManager::NetworkManager() {

    networkAccessManager = new QNetworkAccessManager();
}

NetworkManager &NetworkManager::getInstance() {

    static NetworkManager instance;
    return instance;
}

void NetworkManager::post(const QString &url, const QJsonObject &body, const CallbackFunction &callback) {

    if (Configuration::getInstance().getToken().isEmpty()) {
        return;
    }

    QNetworkRequest request(getCompleteUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    QJsonDocument jsonDocument(body);
    QString jsonString(jsonDocument.toJson(QJsonDocument::Compact));

    auto * reply = networkAccessManager->post(request, jsonString.toLocal8Bit());
    QObject::connect(reply, &QNetworkReply::finished, [reply, callback]() { processReply(reply, callback); });
}

void NetworkManager::get(const QString &url, const CallbackFunction &callback) {

    if (Configuration::getInstance().getToken().isEmpty()) {
        return;
    }

    QNetworkRequest request(getCompleteUrl(url));

    auto * reply = networkAccessManager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [reply, callback]() { processReply(reply, callback); });
}

void NetworkManager::processReply(QNetworkReply * reply, const CallbackFunction &callback) {

    if (reply->error() != QNetworkReply::NetworkError::NoError) {
//        qDebug() << "Error" << reply->error() << reply->url();
        reply->deleteLater();
        callback({}, ResponseStatus::UNSUCCESSFUL);
        return;
    }

    QJsonObject jsonObject;
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());

    if (!doc.isNull() && doc.isObject()) {
        jsonObject = doc.object();
    }

    callback(jsonObject, ResponseStatus::SUCCESSFUL);

    reply->deleteLater();
}

QString NetworkManager::getCompleteUrl(const QString &url) {

    return SERVICE_ADDRESS + url + "?private_token=" + Configuration::getInstance().getToken();
}
