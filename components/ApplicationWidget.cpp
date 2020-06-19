#include "ApplicationWidget.h"

#include <QApplication>
#include <QJsonArray>
#include <QScreen>
#include <QtWidgets/QVBoxLayout>

#include "../models/Project.h"
#include "../models/User.h"
#include "../network/ServiceMediator.h"
#include "../utilities/Configuration.h"
#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "BodyWidget.h"
#include "HeaderWidget.h"
#include "LoadingIndicator.h"

ApplicationWidget::ApplicationWidget(QWidget * parent) : QWidget(parent) {

    setupTrayIcon();
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    setFixedSize(GuiManager::applicationWidth(), GuiManager::applicationHeight());
    setStyleSheet(QString("background-color: %1; color: %2;").arg(GuiManager::lightColor()).arg(GuiManager::darkGrayColor()));
    setupUi();

    Configuration::getInstance().setToken("BEqfZheThA3cR9bpLMF-");

    DataStore::getInstance().initialize();

    auto &loadingIndicator = LoadingIndicator::getInstance();
    loadingIndicator.setParent(this);
}

void ApplicationWidget::setupTrayIcon() {

    auto &systemTrayIcon = SystemTrayIcon::getInstance();
    systemTrayIcon.setParent(this);
    connect(&systemTrayIcon, &SystemTrayIcon::clicked, [this]() {
        const QPoint &cursorPosition = QCursor::pos();
        const QRect &screenGeometry = QApplication::primaryScreen()->availableGeometry();
        int x = qMin(
                cursorPosition.x() - GuiManager::applicationWidth() / 2,
                screenGeometry.width() - GuiManager::applicationWidth()
        );
        int y = screenGeometry.y();
        if (cursorPosition.y() > screenGeometry.height() / 2) {
            y = screenGeometry.height() - GuiManager::applicationHeight();
        }
        move(x, y);
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
