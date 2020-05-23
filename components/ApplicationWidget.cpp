#include "ApplicationWidget.h"

#include <QApplication>
#include <QScreen>
#include <QtWidgets/QVBoxLayout>
#include <QJsonArray>

#include "../network/ServiceMediator.h"
#include "../utilities/Configuration.h"
#include "../models/User.h"
#include "../models/Project.h"
#include "../utilities/GuiManager.h"
#include "../utilities/DataStore.h"
#include "HeaderWidget.h"
#include "BodyWidget.h"

ApplicationWidget::ApplicationWidget(QWidget * parent) : QWidget(parent) {

    setupTrayIcon();
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    setFixedSize(GuiManager::applicationWidth(), GuiManager::applicationHeight());
    setStyleSheet("background-color: " + GuiManager::grayColor(20));
    setupUi();

    Configuration::getInstance().setToken("u-tAYr8T-MyrqhVHVD6G");

    DataStore::getInstance().initialize();
}

void ApplicationWidget::setupTrayIcon() {

    systemTrayIcon = new SystemTrayIcon(this);
    connect(systemTrayIcon, &SystemTrayIcon::clicked, [this]() {
        move(
                QCursor::pos().x() - GuiManager::applicationWidth() / 2,
                QApplication::primaryScreen()->availableSize().height() - GuiManager::applicationHeight()
        );
        this->setVisible(!this->isVisible());
    });
}

void ApplicationWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addWidget(new HeaderWidget());
    mainLayout->addWidget(new BodyWidget());
}
