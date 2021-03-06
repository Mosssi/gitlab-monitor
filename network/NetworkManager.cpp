#include "NetworkManager.h"

#include <QtCore/QJsonDocument>
#include <QJsonArray>

#include "../components/SystemTrayIcon.h"
#include "../utilities/Configuration.h"

NetworkManager::NetworkManager() {

    networkAccessManager = new QNetworkAccessManager();
}

NetworkManager &NetworkManager::getInstance() {

    static NetworkManager instance;
    return instance;
}

void NetworkManager::get(const QString &url, const CallbackFunction &callback) {

    qDebug() << "Sending GET request, url:" << url;

    if (Configuration::getInstance().getToken().isEmpty()) {
        return;
    }

    QNetworkRequest request(url);

    auto * reply = networkAccessManager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, [reply, callback]() { processReply(reply, callback); });
}

void NetworkManager::post(const QString &url, const QJsonObject &body, const CallbackFunction &callback) {

    qDebug() << "Sending POST request, url:" << url;

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

    qDebug() << "Sending PUT request, url:" << url;

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
        qDebug() << "Error in network reply," << reply->error();
        callback(QJsonObject{{"error", reply->error()}}, getResponseStatus(reply->error()));
        reply->deleteLater();
        emit getInstance().networkError();
        return;
    }

    emit getInstance().networkOk();

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

ResponseStatus NetworkManager::getResponseStatus(QNetworkReply::NetworkError error) {

    switch (error) {
        case QNetworkReply::TimeoutError:
            return ResponseStatus::TIMEOUT;
        case QNetworkReply::InternalServerError:
            return ResponseStatus::INTERNAL_SERVER_ERROR;
        case QNetworkReply::AuthenticationRequiredError:
            return ResponseStatus::AUTHENTICATION_REQUIRED_ERROR;
        case QNetworkReply::HostNotFoundError:
            return ResponseStatus::HOST_NOT_FOUND_ERROR;
        default:
            return ResponseStatus::UNSUCCESSFUL;
    }
}
