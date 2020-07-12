#include "PushButton.h"

#include <QKeyEvent>
#include <QPainter>

#include "../../utilities/GuiManager.h"
#include "../../network/NetworkManager.h"


const int CONFIRM_DURATION = 3000;
const int CONFIRM_ANIMATION_DURATION = 150;

PushButton::PushButton(const IconType &icon, bool confirmRequired) :
        QWidget(nullptr), iconType(icon), confirmRequired(confirmRequired) {

    setFixedSize(GuiManager::pushButtonHeight(), GuiManager::pushButtonHeight());
    setFont(GuiManager::iconFont());
    setFocusPolicy(Qt::TabFocus);

    confirmAnimation = new QPropertyAnimation(this, "confirmingValue");
    confirmAnimation->setStartValue(0);
    confirmAnimation->setEndValue(1);
    confirmAnimation->setDuration(CONFIRM_ANIMATION_DURATION);

    unConfirmAnimation = new QPropertyAnimation(this, "confirmingValue");
    unConfirmAnimation->setStartValue(1);
    unConfirmAnimation->setEndValue(0);
    unConfirmAnimation->setDuration(CONFIRM_ANIMATION_DURATION);

    confirmTimer = new QTimer(this);
    confirmTimer->setSingleShot(true);
    confirmTimer->setInterval(CONFIRM_DURATION);
    connect(confirmTimer, &QTimer::timeout, [this]() {
        unConfirmAnimation->start();
    });
}

void PushButton::paintEvent(QPaintEvent * event) {

    QPainter painter(this);
    painter.setRenderHints(QPainter::HighQualityAntialiasing);

    QPainterPath circlePath;
    circlePath.addEllipse(this->rect());

    QString fillColor;
    if (pressed) {
        fillColor = GuiManager::buttonPressColor();
    } else if (hovered || confirmingValue > 0) {
        fillColor = GuiManager::buttonHoverColor();
    } else {
        fillColor = GuiManager::buttonColor();
    }

    QString textColor = GuiManager::textColor();

    painter.fillPath(circlePath, QBrush(QColor(fillColor)));

    if (confirmingValue != 0) {
        auto color = QColor(textColor);
        color.setAlphaF(confirmingValue);
        painter.setPen(color);
        int pixelSize = (int) ((2 - confirmingValue) * GuiManager::largeFontSize());
        if (pixelSize > 0) {
            auto font = painter.font();
            font.setPixelSize(pixelSize);
            painter.setFont(font);
        }
        painter.drawText(this->rect(), Qt::AlignCenter, getIconTypeString(IconType::QUESTION_MARK));
    }

    if (confirmingValue != 1) {
        auto color = QColor(textColor);
        color.setAlphaF(1.0 - confirmingValue);
        painter.setPen(color);
        int pixelSize = (int) ((1 - confirmingValue) * GuiManager::largeFontSize());
        if (pixelSize > 0) {
            auto font = painter.font();
            font.setPixelSize(pixelSize);
            painter.setFont(font);
        }
        painter.drawText(this->rect(), Qt::AlignCenter, getIconTypeString(iconType));
    }
}

void PushButton::mousePressEvent(QMouseEvent *) {

    pressed = true;
    update();
}

void PushButton::mouseReleaseEvent(QMouseEvent *) {

    pressed = false;
    if (confirmRequired) {
        if (confirmingValue > 0) {
            emit clicked();
            unConfirmAnimation->start();
            confirmTimer->stop();
        } else {
            confirmAnimation->start();
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
