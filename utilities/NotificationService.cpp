#include "NotificationService.h"
#include "GuiManager.h"

#include <QGuiApplication>
#include <QWindow>

int const margin = 30;
int const spacing = 10;

NotificationService &NotificationService::getInstance() {

    static NotificationService instance;
    return instance;
}

void NotificationService::info(const QString &message) {

    NotificationService::getInstance().notificationWidgets.append(new NotificationWidget(message, NotificationStatus::INFO, GuiManager::getApplicationWindow());
    NotificationService::getInstance().refreshPositions();
}

void NotificationService::warning(const QString &message) {

    NotificationService::getInstance().NotificationService::notificationWidgets.append(new NotificationWidget(message, NotificationStatus::WARNING, QApplication::desktop()));
    NotificationService::getInstance().refreshPositions();
}

void NotificationService::error(const QString &message) {

    NotificationService::getInstance().NotificationService::notificationWidgets.append(new NotificationWidget(message, NotificationStatus::ERROR, QApplication::desktop()));
    NotificationService::getInstance().refreshPositions();
}

void NotificationService::refreshPositions() {

    int currentHeight = GuiManager::applicationHeight() - margin;
    for (const auto &notificationWidget : NotificationService::notificationWidgets) {
        notificationWidget->move(margin, currentHeight);
        notificationWidget->show();
        currentHeight -= spacing + notificationWidget->height();
    }
}
