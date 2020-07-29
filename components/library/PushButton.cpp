#include "PushButton.h"

#include <QKeyEvent>
#include <QPainter>

#include "../../utilities/GuiManager.h"
#include "../../network/NetworkManager.h"


const int CONFIRM_DURATION = 3000;
const int CONFIRM_ANIMATION_DURATION = 150;

const double arcRadius = 0.8;
const int arcWidth = 2;
const int arcLength = 100;

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

    loadingTimer = new QTimer(this);
    loadingTimer->setInterval(25);
    connect(loadingTimer, &QTimer::timeout, [this]() {
        arcPosition += 10;
        update();
    });
}

void PushButton::paintEvent(QPaintEvent * event) {

    QPainter painter(this);
    painter.setRenderHints(QPainter::HighQualityAntialiasing);

    QPainterPath circlePath;
    circlePath.addEllipse(this->rect());

    QString fillColor;
    if (loading) {
        fillColor = GuiManager::getTheme().buttonColor();
    } else if (pressed) {
        fillColor = GuiManager::getTheme().buttonPressColor();
    } else if (hovered || confirmingValue > 0) {
        fillColor = GuiManager::getTheme().buttonHoverColor();
    } else {
        fillColor = GuiManager::getTheme().buttonColor();
    }

    painter.fillPath(circlePath, QBrush(QColor(fillColor)));

    if (loading) {
        if (!loadingTimer->isActive()) {
            loadingTimer->start();
        }
        auto pen = painter.pen();
        pen.setWidth(arcWidth);
        pen.setColor(GuiManager::getTheme().loadingColor());
        painter.setPen(pen);
        painter.drawArc(
                QRectF(rect().left() + arcWidth, rect().top() + arcWidth, rect().width() - 2 * arcWidth, rect().height() - 2 * arcWidth),
                arcPosition * 16,
                arcLength * 16
        );
    } else {
        if (loadingTimer->isActive()) {
            loadingTimer->stop();
        }
        QString textColor = GuiManager::getTheme().textColor();
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
