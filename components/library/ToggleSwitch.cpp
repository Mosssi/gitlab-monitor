#include "ToggleSwitch.h"

#include <QPainter>
#include <QtCore/QPropertyAnimation>

#include "../../utilities/GuiManager.h"

ToggleSwitch::ToggleSwitch(QWidget * parent) : QWidget(parent), StyledWidget() {

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
    circle.addEllipse(QPointF(h / 2 + switchPosition * (w - h), h / 2), h / 2 - pressureValue, h / 2 - pressureValue);
    painter.fillPath(circle, QBrush(QColor(checked ? GuiManager::getTheme().switchOnColor() : GuiManager::getTheme().switchOffColor())));
}

void ToggleSwitch::mousePressEvent(QMouseEvent * event) {

    auto * pressAnimation = new QPropertyAnimation(this, "pressureValue");
    pressAnimation->setStartValue(0);
    pressAnimation->setEndValue(1);
    pressAnimation->setDuration(100);
    pressAnimation->setEasingCurve(QEasingCurve::Linear);
    pressAnimation->start();
}

void ToggleSwitch::mouseReleaseEvent(QMouseEvent * event) {

    auto * unPressAnimation = new QPropertyAnimation(this, "pressureValue");
    unPressAnimation->setStartValue(1);
    unPressAnimation->setEndValue(0);
    unPressAnimation->setDuration(100);
    unPressAnimation->setEasingCurve(QEasingCurve::Linear);
    unPressAnimation->start();

    toggleState();
}

void ToggleSwitch::toggleState() {

    checked = !checked;
    emit toggled(checked);

    auto * toggleAnimation = new QPropertyAnimation(this, "switchPosition");
    toggleAnimation->setStartValue(checked ? 0 : 1);
    toggleAnimation->setEndValue(checked ? 1 : 0);
    toggleAnimation->setDuration(100);
    toggleAnimation->setEasingCurve(QEasingCurve::OutQuad);
    toggleAnimation->start();
}

void ToggleSwitch::setSwitchPosition(double switchPosition) {

    this->switchPosition = switchPosition;
    update();
}

void ToggleSwitch::setPressureValue(double pressureValue) {

    this->pressureValue = pressureValue;
    update();
}

void ToggleSwitch::setChecked(bool checked) {

    this->checked = checked;
}

bool ToggleSwitch::getChecked() const {

    return checked;
}

void ToggleSwitch::updateStyleSheet() {

    update();
}
