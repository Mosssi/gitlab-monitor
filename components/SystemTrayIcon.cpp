#include "SystemTrayIcon.h"

SystemTrayIcon::SystemTrayIcon(QObject * parent) : QSystemTrayIcon(parent) {

    connect(this, &QSystemTrayIcon::activated, this, &SystemTrayIcon::clicked);

    setIcon(QIcon(":/icon.png"));
    show();
}
