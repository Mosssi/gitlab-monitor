#include "ToggleSwitch.h"

#include <QPainter>
#include <QtCore/QPropertyAnimation>

#include "../../utilities/GuiManager.h"

ToggleSwitch::ToggleSwitch(bool checked, QWidget * parent) : QWidget(parent), StyledWidget(), checked(checked) {

    switchPosition = checked ? 1 : 0;
    setFixedSize(GuiManager::toggleSwitchWidth(), GuiManager::toggleSwitchHeight());
}

void ToggleSwitch::paintEvent(QPaintEvent *) {

    QPainter painter(this);
    painter.setRenderHints(QPainter::HighQualityAntialiasing);

    int w = GuiManager::toggleSwitchWidth();
    int h = GuiManager::toggleSwitchHeight();

    int p = 2; // padding

    QPainterPath rail;
    rail.addRoundRect(p, p, w - 2 * p, h - 2 * p, 100);
    painter.fillPath(rail, QBrush(QColor(checked ? GuiManager::getTheme().switchOnBackgroundColor() : GuiManager::getTheme().switchOffBackgroundColor())));

    QPainterPath circle;
    circle.addEllipse(QPointF(h / 2 + switchPosition * (w - h), h / 2), h / 2, h / 2);
    painter.fillPath(circle, QBrush(QColor(checked ? GuiManager::getTheme().switchOnColor() : GuiManager::getTheme().switchOffColor())));
}

void ToggleSwitch::setSwitchPosition(double switchPosition) {

    this->switchPosition = switchPosition;
    update();
}

void ToggleSwitch::setChecked(bool checked) {

    this->checked = checked;

    auto * toggleAnimation = new QPropertyAnimation(this, "switchPosition");
    toggleAnimation->setStartValue(checked ? 0 : 1);
    toggleAnimation->setEndValue(checked ? 1 : 0);
    toggleAnimation->setDuration(100);
    toggleAnimation->setEasingCurve(QEasingCurve::OutQuad);
    toggleAnimation->start();
}

bool ToggleSwitch::isChecked() const {

    return checked;
}

void ToggleSwitch::updateStyleSheet() {

    update();
}
