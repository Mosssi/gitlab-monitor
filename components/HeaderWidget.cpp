#include "HeaderWidget.h"

#include <QtWidgets/QVBoxLayout>

#include "../utilities/DataStore.h"
#include "library/Label.h"


HeaderWidget::HeaderWidget(QWidget * parent) : QFrame(parent) {

    setStyleSheet(".QFrame {border-bottom: 2px solid " + GuiManager::lightOrangeColor() + ";}");

    setupUi();

    connect(&DataStore::getInstance(), &DataStore::userReceived, [this](const User &user) {
        userWelcomeLabel->setText(QString("Welcome, %1!").arg(user.username));
    });
}

void HeaderWidget::setupUi() {

    setFixedHeight(GuiManager::headerHeight());

    auto * mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 10, 10);

    userWelcomeLabel = new Label();
    userWelcomeLabel->setFontSize(GuiManager::smallFontSize());
    userWelcomeLabel->setColor(GuiManager::lightGrayColor());

    auto * logoLabel = new Label();
    const QPixmap pixmap(":/images/gitlab-logo-gray-rgb.png");
    logoLabel->setPixmap(pixmap.scaledToHeight(GuiManager::logoHeight(), Qt::SmoothTransformation));

    mainLayout->addWidget(logoLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(userWelcomeLabel);
}
