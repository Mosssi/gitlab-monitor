#include "ApplicationWidget.h"

#include <QApplication>
#include <QScreen>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>

#include "../network/ServiceMediator.h"
#include "../utilities/Configuration.h"
#include "../models/User.h"

ApplicationWidget::ApplicationWidget(QWidget * parent) : QWidget(parent) {

    setupTrayIcon();

    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);

    Configuration::getInstance().setToken("u-tAYr8T-MyrqhVHVD6G");

    ServiceMediator::requestUser([](CALLBACK_SIGNATURE) {
        if (status == ResponseStatus::SUCCESSFUL) {
            qDebug() << User(object).getJson();
        }
    });

    setFixedSize(400, 500);

    setupUi();
}

void ApplicationWidget::setupTrayIcon() {

    systemTrayIcon = new SystemTrayIcon(this);
    connect(systemTrayIcon, &SystemTrayIcon::clicked, [this]() {
        QPoint point = QCursor::pos();
        move(point.x() - 200, QApplication::primaryScreen()->availableSize().height() - 500);
        this->setVisible(!this->isVisible());
    });
}

void ApplicationWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("GitLab Desktop Monitor"));
}
