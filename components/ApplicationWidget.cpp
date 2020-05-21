#include "ApplicationWidget.h"

#include <QApplication>
#include <QScreen>

#include "../network/NetworkManager.h"
#include "../utilities/Configuration.h"

ApplicationWidget::ApplicationWidget(QWidget * parent) : QWidget(parent) {

    setupTrayIcon();

    setWindowFlags(Qt::FramelessWindowHint);

    Configuration::getInstance().setToken("u-tAYr8T-MyrqhVHVD6G");

    ServiceMediator::getInstance().requestUser();
    QObject::connect(&ServiceMediator::getInstance(), &ServiceMediator::userReceived, [](const NetworkResponse<User> &response) {
        qDebug() << response.entity.getJson();
    });

    setFixedSize(400, 500);
}

void ApplicationWidget::setupTrayIcon() {

    systemTrayIcon = new SystemTrayIcon(this);
    connect(systemTrayIcon, &SystemTrayIcon::clicked, [this]() {
        QPoint point = QCursor::pos();
        move(point.x() - 200, QApplication::primaryScreen()->availableSize().height() - 500);
        this->setVisible(!this->isVisible());
    });
}
