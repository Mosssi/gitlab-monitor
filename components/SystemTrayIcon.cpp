#include "SystemTrayIcon.h"

#include <QDebug>

#define ENABLED_ICON ":/images/icon.png"
#define DISABLED_ICON ":/images/gray-icon.png"


SystemTrayIcon::SystemTrayIcon() : QSystemTrayIcon(nullptr) {

    connect(this, &QSystemTrayIcon::activated, [this](QSystemTrayIcon::ActivationReason reason) {
        switch (reason) {
            case Trigger:
            case DoubleClick:
            case MiddleClick:
                emit clicked();
                break;
            case Context:
                emit rightClicked();
            case Unknown:
            default:
                break;
        }
    });
    setEnabled(true);
    show();
}

void SystemTrayIcon::setEnabled(bool enabled) {

    setIcon(QIcon(enabled ? ENABLED_ICON : DISABLED_ICON));
}
