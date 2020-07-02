#include "NotificationWidget.h"

NotificationWidget::NotificationWidget(const QString &text, NotificationStatus status, QWidget * parent) : Label(text, parent), text(text), status(status) {

    setColor(GuiManager::lightColor());
    setBackgroundColor(GuiManager::grayColor());
    setFontSize(GuiManager::smallFontSize());

    setFixedHeight(GuiManager::smallFontSize() + 10);

    QFont font;
    font.setPixelSize(GuiManager::smallFontSize());
    QFontMetrics fontMetrics(font);
    setFixedWidth(fontMetrics.width(text) + 10);

    setAlignment(Qt::AlignCenter);
}
