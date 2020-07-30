#include "WelcomeWidget.h"

#include <QtWidgets/QVBoxLayout>

#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "library/Label.h"
#include "library/LineEdit.h"
#include "library/PushButton.h"

WelcomeWidget::WelcomeWidget(QWidget * parent) : Frame(parent) {

    setupUi();
}

void WelcomeWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(30, 10, 30, 10);

    auto * logoLabel = new Label();
    const QPixmap pixmap(":/images/gitlab-icon.png");
    logoLabel->setPixmap(pixmap.scaledToHeight(GuiManager::logoHeight() * 2, Qt::SmoothTransformation));

    mainLayout->addStretch(1);
    mainLayout->addWidget(logoLabel, 0, Qt::AlignCenter);

    mainLayout->addSpacing(10);
    auto * serverAddressInput = new LineEdit();
    serverAddressInput->setText("https://gitlab.com");
    mainLayout->addWidget(new Label("SERVER ADDRESS:", GuiManager::smallFontSize(), TextColor::TERTIARY));
    mainLayout->addWidget(serverAddressInput);

    mainLayout->addSpacing(10);
    auto * tokenInput = new LineEdit();
    tokenInput->setText("BEqfZheThA3cR9bpLMF-");
    mainLayout->addWidget(new Label("TOKEN:", GuiManager::smallFontSize(), TextColor::TERTIARY));
    mainLayout->addWidget(tokenInput);

    auto * saveServerConfigsButton = new PushButton(IconType::DONE);
    connect(saveServerConfigsButton, &PushButton::clicked, [this, serverAddressInput, tokenInput, saveServerConfigsButton]() {
        saveServerConfigsButton->setLoading(true);
        Configuration::getInstance().setServerAddress(serverAddressInput->text());
        Configuration::getInstance().setToken(tokenInput->text());

        DataStore::getInstance().initialize();
    });
    mainLayout->addSpacing(10);
    mainLayout->addWidget(saveServerConfigsButton, 0, Qt::AlignCenter);

    connect(&DataStore::getInstance(), &DataStore::userReceived, [this, saveServerConfigsButton]() {
        saveServerConfigsButton->setLoading(false);
        emit serverAndTokenValidated();
    });

    connect(&DataStore::getInstance(), &DataStore::userReceiveFailed, [saveServerConfigsButton]() {
        saveServerConfigsButton->setLoading(false);
        Configuration::getInstance().setServerAddress("");
        Configuration::getInstance().setToken("");
    });

    mainLayout->addStretch(3);
    mainLayout->addWidget(new Label("© Copyright for Mohsen Esmaeili", GuiManager::smallFontSize(), TextColor::TERTIARY), 0, Qt::AlignCenter);
}
