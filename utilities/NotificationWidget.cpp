#include "NotificationWidget.h"

#include <QtCore/QPropertyAnimation>

#include "GuiManager.h"

const int animationDuration = 500;
const int padding = 5;

NotificationWidget::NotificationWidget(const QString &text, NotificationStatus status, int availableWidth, QWidget * parent)
        : Label(text, parent), text(text), status(status), availableWidth(availableWidth) {

    setColor(GuiManager::backgroundColor()); // TODO: Define color
    setFontSize(GuiManager::smallFontSize());
    switch (status) {
        case NotificationStatus::INFO:
            setBackgroundColor(GuiManager::textColor()); // TODO: Define color
            break;
        case NotificationStatus::ERROR:
            setBackgroundColor(GuiManager::redOrangeColor());
            break;
    }

    setFixedHeight(GuiManager::smallFontSize() + 2 * padding);

    QFont font;
    font.setPixelSize(GuiManager::smallFontSize());
    QFontMetrics fontMetrics(font);

    maxWidth = fontMetrics.width(text) + 2 * padding;
    if (maxWidth > availableWidth) {
        QString elidedText;
        int lengthReduction = 4;
        do {
            elidedText = text.mid(0, text.length() - lengthReduction++);
        } while (fontMetrics.width(elidedText + "...") + 2 * padding > availableWidth);
        setText(elidedText + "...");
        maxWidth = fontMetrics.width(elidedText + "...") + 2 * padding;
    }

    setAlignment(Qt::AlignCenter);
    show();
}

void NotificationWidget::show() {

    QWidget::show();

    auto * showAnimation = new QPropertyAnimation(this, "currentWidth");
    showAnimation->setStartValue(0);
    showAnimation->setEndValue(maxWidth);
    showAnimation->setDuration(animationDuration);
    showAnimation->setEasingCurve(QEasingCurve::InOutExpo);
    showAnimation->start();
}

void NotificationWidget::hide() {

    auto * hideAnimation = new QPropertyAnimation(this, "currentWidth");
    hideAnimation->setStartValue(maxWidth);
    hideAnimation->setEndValue(0);
    hideAnimation->setDuration(animationDuration);
    hideAnimation->setEasingCurve(QEasingCurve::InOutExpo);
    hideAnimation->start();

    connect(hideAnimation, &QPropertyAnimation::finished, this, &NotificationWidget::gotHidden);
}

int NotificationWidget::getCurrentWidth() const {

    return this->currentWidth;
}

void NotificationWidget::setCurrentWidth(int currentWidth) {

    this->currentWidth = currentWidth;
    setFixedWidth(currentWidth);
}
