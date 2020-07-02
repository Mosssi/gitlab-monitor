#ifndef GITLAB_DESKTOP_MONITOR_NOTIFICATIONWIDGET_H
#define GITLAB_DESKTOP_MONITOR_NOTIFICATIONWIDGET_H

#include <QtWidgets/QLabel>

enum class NotificationStatus {
    INFO,
    WARNING,
    ERROR,
};

// TODO: Find a better location for this class
class NotificationWidget : public QLabel {
private:
    friend class NotificationService;
    NotificationWidget(const QString &text, NotificationStatus status, QWidget * parent = nullptr);

    QString text = "";
    NotificationStatus status = NotificationStatus::INFO;
};


#endif //GITLAB_DESKTOP_MONITOR_NOTIFICATIONWIDGET_H
