#include "SystemTrayIcon.h"

#define ENABLED_ICON ":/images/icon.png"
#define DISABLED_ICON ":/images/gray-icon.png"

SystemTrayIcon &SystemTrayIcon::getInstance() {

    static SystemTrayIcon instance;
    return instance;
}

SystemTrayIcon::SystemTrayIcon() : QSystemTrayIcon() {

    connect(this, &QSystemTrayIcon::activated, this, &SystemTrayIcon::clicked);
    setEnabled(true);
    show();
}

void SystemTrayIcon::setEnabled(bool enabled) {

    setIcon(QIcon(enabled ? ENABLED_ICON : DISABLED_ICON));
}
