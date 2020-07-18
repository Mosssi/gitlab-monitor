#include "HeaderWidget.h"

#include <QtWidgets/QVBoxLayout>

#include "../network/NetworkManager.h"
#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "library/Label.h"
#include "library/PushButton.h"
#include "library/LineEdit.h"


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

    setFixedHeight(GuiManager::applicationHeight());

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
        GuiManager::getApplicationWindow()->showConfiguration();
    });

    topContentLayout->addLayout(topLayout);

    auto * descriptionLabel = new Label("Welcome to state-of-the-art monitoring technology");
    descriptionLabel->setFontSize(GuiManager::smallFontSize());
    descriptionLabel->setColor(TextColor::TERTIARY);
    topContentLayout->addWidget(descriptionLabel);

    topContentLayout->addStretch();

    auto * serverAddressInput = new LineEdit();
    serverAddressInput->setText("https://gitlab.com");
    topContentLayout->addWidget(new Label("Server Address:"));
    topContentLayout->addWidget(serverAddressInput);

    auto * tokenInput = new LineEdit();
    tokenInput->setText("BEqfZheThA3cR9bpLMF-");
    topContentLayout->addWidget(new Label("Token:"));
    topContentLayout->addWidget(tokenInput);

    auto * saveServerConfigsButton = new PushButton(IconType::DONE);
    connect(saveServerConfigsButton, &PushButton::clicked, [this, serverAddressInput, tokenInput]() {
        Configuration::getInstance().setServerAddress(serverAddressInput->text());
        Configuration::getInstance().setToken(tokenInput->text());

        DataStore::getInstance().initialize();
    });
    topContentLayout->addWidget(saveServerConfigsButton);

    topContentLayout->addStretch();
}

void HeaderWidget::updateStyleSheet() {

    setBackgroundColor(GuiManager::getTheme().mainHeaderColor());
    borderFrame->setBackgroundColor(GuiManager::getTheme().headerBorderColor());
}
