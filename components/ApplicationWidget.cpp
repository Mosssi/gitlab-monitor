#include "ApplicationWidget.h"

#include <QApplication>
#include <QJsonArray>
#include <QScreen>
#include <QtWidgets/QVBoxLayout>
#include <QDesktopWidget>

#include "../models/Project.h"
#include "../models/User.h"
#include "../network/ServiceMediator.h"
#include "../utilities/Configuration.h"
#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "BodyWidget.h"
#include "HeaderWidget.h"

ApplicationWidget::ApplicationWidget(QWidget * parent) : QWidget(parent) {

    setupTrayIcon();
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    setFixedSize(GuiManager::applicationWidth(), GuiManager::applicationHeight());
    setStyleSheet(QString("background-color: %1; color: %2;").arg(GuiManager::lightColor()).arg(GuiManager::darkGrayColor()));
    setupUi();

    Configuration::getInstance().setToken("BEqfZheThA3cR9bpLMF-");

    DataStore::getInstance().initialize();
}

void ApplicationWidget::setupTrayIcon() {

    auto &systemTrayIcon = SystemTrayIcon::getInstance();
    systemTrayIcon.setParent(this);
    connect(&systemTrayIcon, &SystemTrayIcon::clicked, [this]() {
        const QPoint &cursorPosition = QCursor::pos();
        const int availableHeight = QApplication::primaryScreen()->availableGeometry().height();
        const int availableWidth = QApplication::desktop()->size().width();
        int x = qMin(
                cursorPosition.x() - GuiManager::applicationWidth() / 2,
                availableWidth - GuiManager::applicationWidth()
        );
        int y = QApplication::primaryScreen()->availableGeometry().y();
        if (cursorPosition.y() > availableHeight / 2) {
            y = availableHeight - GuiManager::applicationHeight();
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
