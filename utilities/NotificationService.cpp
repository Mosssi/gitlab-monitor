#include "NotificationService.h"

#include <QGuiApplication>
#include <QWindow>
#include <QTimer>

#include "GuiManager.h"

int const margin = 20;
int const spacing = 5;
int const interval = 5000;

NotificationService &NotificationService::getInstance() {

    static NotificationService instance;
    return instance;
}

void NotificationService::info(const QString &message) {

    NotificationService::getInstance().addNotification(message, NotificationStatus::INFO);
}

void NotificationService::warning(const QString &message) {

    NotificationService::getInstance().addNotification(message, NotificationStatus::WARNING);
}

void NotificationService::error(const QString &message) {

    NotificationService::getInstance().addNotification(message, NotificationStatus::ERROR);
}

void NotificationService::refreshPositions() {

    int currentHeight = GuiManager::applicationHeight() - margin + spacing;
    for (const auto &notificationWidget : NotificationService::notificationWidgets) {
        currentHeight -= spacing + notificationWidget->height();
        notificationWidget->move(margin, currentHeight);
        notificationWidget->show();
    }
}

void NotificationService::addNotification(const QString &message, NotificationStatus status) {

    auto * notificationWidget = new NotificationWidget(message, status, GuiManager::getApplicationWindow());
    QTimer::singleShot(interval, [this, notificationWidget]() {
        notificationWidget->hide();
        notificationWidget->deleteLater();
        notificationWidgets.removeOne(notificationWidget);
        refreshPositions();
    });

    NotificationService::getInstance().NotificationService::notificationWidgets.append(notificationWidget);
    NotificationService::getInstance().refreshPositions();
}
