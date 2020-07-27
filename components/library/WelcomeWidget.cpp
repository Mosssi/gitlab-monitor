#include "WelcomeWidget.h"
#include "Label.h"
#include "../../utilities/GuiManager.h"
#include "LineEdit.h"
#include "PushButton.h"
#include "../../utilities/DataStore.h"

#include <QtWidgets/QVBoxLayout>

WelcomeWidget::WelcomeWidget(QWidget * parent) : Frame(parent) {

    setupUi();
}

void WelcomeWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);

    auto * logoLabel = new Label();
    const QPixmap pixmap(":/images/gitlab-icon.png");
    logoLabel->setPixmap(pixmap.scaledToHeight(GuiManager::logoHeight() * 2, Qt::SmoothTransformation));

    mainLayout->addStretch(1);
    mainLayout->addWidget(logoLabel, 0, Qt::AlignCenter);

    auto * serverAddressInput = new LineEdit();
    serverAddressInput->setText("https://gitlab.com");
    mainLayout->addWidget(new Label("Server Address:", GuiManager::smallFontSize(), TextColor::SECONDARY));
    mainLayout->addWidget(serverAddressInput);

    auto * tokenInput = new LineEdit();
    tokenInput->setText("BEqfZheThA3cR9bpLMF-");
    mainLayout->addWidget(new Label("Token:", GuiManager::smallFontSize(), TextColor::SECONDARY));
    mainLayout->addWidget(tokenInput);

    auto * saveServerConfigsButton = new PushButton(IconType::DONE);
    connect(saveServerConfigsButton, &PushButton::clicked, [this, serverAddressInput, tokenInput, saveServerConfigsButton]() {
        saveServerConfigsButton->setLoading(true);
        Configuration::getInstance().setServerAddress(serverAddressInput->text());
        Configuration::getInstance().setToken(tokenInput->text());

        DataStore::getInstance().initialize();
    });
    mainLayout->addWidget(saveServerConfigsButton);

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
}
