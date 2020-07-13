#include "LoadingWidget.h"

#include <QPainter>

#include "../../utilities/GuiManager.h"

const double arcRadius = 0.8;
const int arcWidth = 2;
const int arcLength = 100;

LoadingWidget::LoadingWidget(QWidget * parent) : QWidget(parent) {

    setFixedSize(GuiManager::loadingWidgetHeight(), GuiManager::loadingWidgetHeight());

    timer = new QTimer(this);
    timer->setInterval(25);
    connect(timer, &QTimer::timeout, [this]() {
        arcPosition += 10;
        update();
    });
    timer->start();
}

void LoadingWidget::paintEvent(QPaintEvent * event) {

    QPainter painter(this);
    painter.setRenderHints(QPainter::HighQualityAntialiasing);
    painter.translate(GuiManager::loadingWidgetHeight() * 0.5, GuiManager::loadingWidgetHeight() * 0.5);

    QRect arcRect(
            -(int) (GuiManager::loadingWidgetHeight() * arcRadius * 0.5),
            -(int) (GuiManager::loadingWidgetHeight() * arcRadius * 0.5),
            (int) (GuiManager::loadingWidgetHeight() * arcRadius),
            (int) (GuiManager::loadingWidgetHeight() * arcRadius)
    );

    auto pen = painter.pen();
    pen.setWidth(arcWidth);
    pen.setColor(GuiManager::tertiaryTextColor());
    painter.setPen(pen);
    painter.drawEllipse(arcRect);

    pen.setColor(GuiManager::redOrangeColor()); // TODO: Better to define separate color
    painter.setPen(pen);
    painter.drawArc(arcRect, arcPosition * 16, arcLength * 16);
}
