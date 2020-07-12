#include "HeaderWidget.h"

#include <QtWidgets/QVBoxLayout>

#include "../network/NetworkManager.h"
#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "library/Label.h"
#include "library/PushButton.h"


HeaderWidget::HeaderWidget(QWidget * parent) : Frame(parent) {

    setupUi();
    HeaderWidget::updateStyleSheet();

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

void HeaderWidget::updateStyleSheet() {

    setBackgroundColor(GuiManager::backgroundColor());
    setGeneralStyle(QString("border-bottom: 2px solid %1").arg(GuiManager::lightOrangeColor()));
    userWelcomeLabel->setColor(GuiManager::secondaryTextColor());
}
