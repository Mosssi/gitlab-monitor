#include "HeaderWidget.h"

#include <QtWidgets/QVBoxLayout>

#include "../utilities/DataStore.h"
#include "library/Label.h"
#include "library/PushButton.h"
#include "../network/NetworkManager.h"


HeaderWidget::HeaderWidget(QWidget * parent) : QFrame(parent) {

    setStyleSheet(".QFrame {border-bottom: 2px solid " + GuiManager::lightOrangeColor() + ";}");

    setupUi();

    connect(&DataStore::getInstance(), &DataStore::userReceived, [this]() {
        QString username = DataStore::getInstance().getUser().username;
        QStringList specialNames = {"Bayati", "bayati"};
        userWelcomeLabel->setText(QString("Welcome, %1%2!")
                                          .arg(specialNames.contains(username) ? "Agha " : "")
                                          .arg(username));
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
    auto * configurationButton = new PushButton(IconType::EMPTY);
    mainLayout->addWidget(configurationButton);
    connect(configurationButton, &PushButton::clicked, [this]() {
        GuiManager::getApplicationWindow()->showConfiguration();
    });
}
