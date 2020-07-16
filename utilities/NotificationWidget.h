#ifndef GITLAB_DESKTOP_MONITOR_NOTIFICATIONWIDGET_H
#define GITLAB_DESKTOP_MONITOR_NOTIFICATIONWIDGET_H

#include "../components/library/Label.h"

enum class NotificationStatus {
    INFO,
    ERROR,
};

// TODO: Find a better location for this class
class NotificationWidget : public Label {
Q_OBJECT
Q_PROPERTY(int currentWidth READ getCurrentWidth WRITE setCurrentWidth)
private:
    friend class NotificationService;

    NotificationWidget(const QString &text, NotificationStatus status, int availableWidth, QWidget * parent = nullptr);
    void show();
    void hide();
    [[nodiscard]] int getCurrentWidth() const;
    void setCurrentWidth(int currentWidth);
    void updateStyleSheet() override;

    QString text;
    NotificationStatus status;

    int currentWidth = 0;
    int maxWidth;
    const int availableWidth;

signals:
    void gotHidden();
};


#endif //GITLAB_DESKTOP_MONITOR_NOTIFICATIONWIDGET_H
