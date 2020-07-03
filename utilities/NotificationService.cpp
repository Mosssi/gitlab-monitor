#include "NotificationService.h"

#include <QtCore/QPropertyAnimation>
#include <QTimer>

#include "GuiManager.h"

int const interval = 5000;

NotificationService &NotificationService::getInstance() {

    static NotificationService instance;
    return instance;
}

void NotificationService::info(const QString &message) {

    NotificationService::getInstance().addNotification(message, NotificationStatus::INFO);
}

void NotificationService::error(const QString &message) {

    NotificationService::getInstance().addNotification(message, NotificationStatus::ERROR);
}

void NotificationService::refreshPositions() {

    int currentHeight = baseHeight;
    for (const auto &notificationWidget : NotificationService::notificationWidgets) {
        currentHeight -= spacing + notificationWidget->height();
        notificationWidget->move(margin, currentHeight);
    }
}

void NotificationService::addNotification(const QString &message, NotificationStatus status) {

    auto * notificationWidget = new NotificationWidget(message, status, GuiManager::applicationWidth() - 2 * margin, GuiManager::getApplicationWindow());
    QTimer::singleShot(interval, [this, notificationWidget]() {
        notificationWidget->hide();
        refreshPositions();
    });

    QObject::connect(notificationWidget, &NotificationWidget::gotHidden, [notificationWidget, this]() {
        notificationWidget->deleteLater();
        notificationWidgets.removeOne(notificationWidget);

        auto * baseHeightAnimation = new QPropertyAnimation(this, "baseHeight");
        baseHeightAnimation->setStartValue(baseHeight - notificationWidget->height());
        baseHeightAnimation->setEndValue(GuiManager::applicationHeight() - margin + spacing);
        baseHeightAnimation->setDuration(500);
        baseHeightAnimation->setEasingCurve(QEasingCurve::OutExpo);
        baseHeightAnimation->start();
    });

    NotificationService::getInstance().NotificationService::notificationWidgets.append(notificationWidget);
    NotificationService::getInstance().refreshPositions();
}
