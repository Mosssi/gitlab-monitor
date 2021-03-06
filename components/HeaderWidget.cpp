#include "HeaderWidget.h"

#include <QtWidgets/QVBoxLayout>

#include "../network/NetworkManager.h"
#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "ModalManager.h"
#include "library/Label.h"
#include "library/PushButton.h"

HeaderWidget::HeaderWidget(QWidget * parent) : Frame(parent) {

    setupUi();
    HeaderWidget::updateStyleSheet();

    connect(&DataStore::getInstance(), &DataStore::userReceived, [this]() {
        QString username = DataStore::getInstance().getUser().username;
        userWelcomeLabel->setText(QString("Welcome, %1!").arg(username));
    });
}

void HeaderWidget::setupUi() {

    setFixedHeight(GuiManager::headerHeight());

    borderFrame = new Frame();
    borderFrame->setFixedHeight(2);

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    auto * topContentLayout = new QVBoxLayout();
    topContentLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->addLayout(topContentLayout);
    mainLayout->addWidget(borderFrame);

    auto * topLayout = new QHBoxLayout();

    userWelcomeLabel = new Label();
    userWelcomeLabel->setColor(TextColor::SECONDARY);
    userWelcomeLabel->setFontSize(GuiManager::smallFontSize());

    auto * logoLabel = new Label();
    const QPixmap pixmap(":/images/header-image.png");
    logoLabel->setPixmap(pixmap.scaledToHeight(GuiManager::logoHeight(), Qt::SmoothTransformation));

    topLayout->addWidget(logoLabel);
    topLayout->addStretch();
    topLayout->addWidget(userWelcomeLabel);
    auto * configurationButton = new PushButton(IconType::SETTINGS);
    topLayout->addWidget(configurationButton);
    connect(configurationButton, &PushButton::clicked, [this]() {
        ModalManager::getInstance().showConfigurationWindow();
    });

    topContentLayout->addLayout(topLayout);
}

void HeaderWidget::updateStyleSheet() {

    setBackgroundColor(GuiManager::getTheme().mainHeaderColor());
    borderFrame->setBackgroundColor(GuiManager::getTheme().headerBorderColor());
}
