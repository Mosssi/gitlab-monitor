#include "PushButton.h"

#include <QKeyEvent>
#include <QPainter>

#include "../../utilities/GuiManager.h"


const int CONFIRM_DURATION = 3000;

PushButton::PushButton(const IconType &icon, bool confirmRequired) : QWidget(nullptr), iconType(icon), confirmRequired(confirmRequired) {

    setFixedSize(GuiManager::pushButtonHeight(), GuiManager::pushButtonHeight());
    setFont(GuiManager::iconFont());
    setFocusPolicy(Qt::TabFocus);

    confirmTimer = new QTimer(this);
    confirmTimer->setSingleShot(true);
    confirmTimer->setInterval(CONFIRM_DURATION);
    connect(confirmTimer, &QTimer::timeout, [this]() {
        confirming = false;
        update();
    });
}

PushButton::~PushButton() {

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
            confirmTimer->start();
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

void PushButton::keyPressEvent(QKeyEvent * event) {

    QWidget::keyPressEvent(event);
    if (event->key() == Qt::Key_Space) {
        mousePressEvent(nullptr);
    }
}

void PushButton::keyReleaseEvent(QKeyEvent * event) {

    QWidget::keyReleaseEvent(event);
    if (event->key() == Qt::Key_Space) {
        mouseReleaseEvent(nullptr);
    }
}
