#include "PushButton.h"

#include <QPainter>
#include <QTimer>

#include "../../utilities/GuiManager.h"


const int CONFIRM_DURATION = 3000;

PushButton::PushButton(const IconType &icon, bool confirmRequired) : QWidget(nullptr), iconType(icon), confirmRequired(confirmRequired) {

    setFixedSize(GuiManager::pushButtonHeight(), GuiManager::pushButtonHeight());
    setFont(GuiManager::iconFont());
}

void PushButton::paintEvent(QPaintEvent * event) {

    QPainter painter(this);
    painter.setRenderHints(QPainter::HighQualityAntialiasing);

    QPainterPath circlePath;
    circlePath.addEllipse(this->rect());

    QString fillColor;
    if (confirming) {
        if (pressed) {
            fillColor = GuiManager::lightPurpleColor();
        } else if (hovered) {
            fillColor = GuiManager::purpleColor();
        } else {
            fillColor = GuiManager::lightPurpleColor();
        }
    } else {
        if (pressed) {
            fillColor = GuiManager::lightColor();
        } else if (hovered) {
            fillColor = GuiManager::darkerLightColor();
        } else {
            fillColor = GuiManager::darkLightColor();
        }
    }

    QString textColor = GuiManager::grayColor();
    if (confirming) {
        textColor = GuiManager::lightColor();
    }

    painter.fillPath(circlePath, QBrush(QColor(fillColor)));
    painter.setPen(QPen(QColor(textColor)));
    painter.drawText(this->rect(), Qt::AlignCenter, confirming ? "?" : getIconTypeString(iconType));
}

void PushButton::mousePressEvent(QMouseEvent *) {

    pressed = true;
    update();
}

void PushButton::mouseReleaseEvent(QMouseEvent *) {

    pressed = false;
    if (confirmRequired) {
        if (confirming) {
            emit clicked();
        }
        confirming = !confirming;
        if (confirming) {
            QTimer::singleShot(CONFIRM_DURATION, [this]() {
                confirming = false;
                update();
            });
        }
    } else {
        emit clicked();
    }
    update();
}

void PushButton::enterEvent(QEvent *) {

    hovered = true;
    update();
}

void PushButton::leaveEvent(QEvent *) {

    hovered = false;
    update();
}
