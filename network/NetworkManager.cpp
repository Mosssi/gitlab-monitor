#include "NetworkManager.h"

#include <QtCore/QJsonDocument>
#include <QJsonArray>

#include "../utilities/Configuration.h"

NetworkManager::NetworkManager() {

    networkAccessManager = new QNetworkAccessManager();
}

NetworkManager &NetworkManager::getInstance() {

    static NetworkManager instance;
    return instance;
}

void NetworkManager::get(const QString &url, const CallbackFunction &callback) {

    if (Configuration::getInstance().getToken().isEmpty()) {
        return;
    }

    QNetworkRequest request(url);

    auto * reply = networkAccessManager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [reply, callback]() { processReply(reply, callback); });
}

void NetworkManager::post(const QString &url, const QJsonObject &body, const CallbackFunction &callback) {

    if (Configuration::getInstance().getToken().isEmpty()) {
        return;
    }

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    QJsonDocument jsonDocument(body);
    QString jsonString(jsonDocument.toJson(QJsonDocument::Compact));

    auto * reply = networkAccessManager->post(request, jsonString.toLocal8Bit());
    QObject::connect(reply, &QNetworkReply::finished, [reply, callback]() { processReply(reply, callback); });
}

void NetworkManager::put(const QString &url, const QJsonObject &body, const CallbackFunction &callback) {

    if (Configuration::getInstance().getToken().isEmpty()) {
        return;
    }

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));

    QJsonDocument jsonDocument(body);
    QString jsonString(jsonDocument.toJson(QJsonDocument::Compact));

    auto * reply = networkAccessManager->put(request, jsonString.toLocal8Bit());
    QObject::connect(reply, &QNetworkReply::finished, [reply, callback]() { processReply(reply, callback); });
}

void NetworkManager::processReply(QNetworkReply * reply, const CallbackFunction &callback) {

    if (reply->error() != QNetworkReply::NetworkError::NoError) {
        callback(QJsonObject{{"error", reply->error()}}, ResponseStatus::UNSUCCESSFUL);
        reply->deleteLater();
        return;
    }

    QJsonValue jsonValue;
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());

    if (!doc.isNull()) {
        if (doc.isObject()) {
            jsonValue = doc.object();
        } else if (doc.isArray()) {
            jsonValue = doc.array();
        }
    }

    callback(jsonValue, ResponseStatus::SUCCESSFUL);

    reply->deleteLater();
}
