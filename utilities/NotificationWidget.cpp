#include "NotificationWidget.h"

NotificationWidget::NotificationWidget(const QString &text, NotificationStatus status, QWidget * parent) : QLabel(text, parent), text(text), status(status) {

}
