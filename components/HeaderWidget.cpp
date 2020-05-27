#include "HeaderWidget.h"

#include <QtWidgets/QVBoxLayout>

#include "../utilities/DataStore.h"
#include "library/Label.h"


HeaderWidget::HeaderWidget(QWidget * parent) : QFrame(parent) {

    setupUi();
    setStyleSheet(".QFrame {border-bottom: 2px solid " + GuiManager::darkLightColor() + ";}");

    connect(&DataStore::getInstance(), &DataStore::userReceived, [this](const User &user) {
        userWelcomeLabel->setText(QString("Welcome, %1!").arg(user.username));
    });
}

void HeaderWidget::setupUi() {

    setFixedHeight(GuiManager::headerHeight());
    setStyleSheet(QString("background-color: %1;").arg(GuiManager::lightColor()));

    auto * mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 10, 10);

    userWelcomeLabel = new Label();
    userWelcomeLabel->setFontSize(GuiManager::smallFontSize());
    userWelcomeLabel->setColor(GuiManager::lightGrayColor());

    auto * logoLabel = new Label();
    const QPixmap pixmap(":/gitlab-logo-gray-rgb.png");
    logoLabel->setPixmap(pixmap.scaledToHeight(GuiManager::logoHeight(), Qt::SmoothTransformation));

    mainLayout->addWidget(logoLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(userWelcomeLabel);
}
