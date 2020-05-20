#include "ApplicationWidget.h"

#include <QPaintEngine>
#include <QDebug>

ApplicationWidget::ApplicationWidget(QWidget * parent) : QWidget(parent) {

    setupTrayIcon();

    setWindowFlags(Qt::FramelessWindowHint);
}

void ApplicationWidget::setupTrayIcon() {

    systemTrayIcon = new SystemTrayIcon(this);
    connect(systemTrayIcon, &SystemTrayIcon::clicked, [this]() {
        this->setVisible(!this->isVisible());
    });
}
