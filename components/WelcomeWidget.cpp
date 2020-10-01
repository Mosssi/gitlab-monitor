#include "WelcomeWidget.h"

#include <QtWidgets/QVBoxLayout>

#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "../utilities/NotificationService.h"
#include "library/Label.h"
#include "library/LineEdit.h"
#include "library/PushButton.h"

WelcomeWidget::WelcomeWidget(QWidget * parent) : Frame(parent) {

    setupUi();
}

void WelcomeWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(30, 10, 30, 10);
    mainLayout->setSpacing(3);

    auto * logoLabel = new Label();
    const QPixmap pixmap(":/images/gitlab-icon.png");
    logoLabel->setPixmap(pixmap.scaledToHeight(GuiManager::logoHeight() * 2, Qt::SmoothTransformation));

    mainLayout->addStretch(1);
    mainLayout->addWidget(logoLabel, 0, Qt::AlignCenter);

    mainLayout->addSpacing(20);
    auto * serverAddressInput = new LineEdit();
    serverAddressInput->setText("https://gitlab.com");
    mainLayout->addWidget(new Label("SERVER ADDRESS:", GuiManager::smallFontSize(), TextColor::TERTIARY));
    mainLayout->addWidget(serverAddressInput);
    connect(serverAddressInput, &LineEdit::textChanged, [serverAddressInput]() {
        serverAddressInput->setHasError(false);
    });

    mainLayout->addSpacing(10);
    auto * tokenInput = new LineEdit();
    mainLayout->addWidget(new Label("TOKEN:", GuiManager::smallFontSize(), TextColor::TERTIARY));
    mainLayout->addWidget(tokenInput);
    connect(tokenInput, &LineEdit::textChanged, [tokenInput]() {
        tokenInput->setHasError(false);
    });

    auto * saveServerConfigsButton = new PushButton(IconType::DONE);
    connect(saveServerConfigsButton, &PushButton::clicked, [serverAddressInput, tokenInput, saveServerConfigsButton]() {

        if (serverAddressInput->text().isEmpty()) {
            serverAddressInput->setFocus();
            serverAddressInput->setHasError(true);
            return;
        }

        if (tokenInput->text().isEmpty()) {
            tokenInput->setFocus();
            tokenInput->setHasError(true);
            return;
        }

        saveServerConfigsButton->setLoading(true);
        Configuration::getInstance().setServerAddress(serverAddressInput->text() + "/api/v4");
        Configuration::getInstance().setToken(tokenInput->text());

        DataStore::getInstance().initialize();
    });
    mainLayout->addSpacing(10);
    mainLayout->addWidget(saveServerConfigsButton, 0, Qt::AlignCenter);

    connect(&DataStore::getInstance(), &DataStore::userReceived, [this, saveServerConfigsButton]() {
        saveServerConfigsButton->setLoading(false);
        emit serverAndTokenValidated();
    });

    connect(&DataStore::getInstance(), &DataStore::userReceiveFailed, [saveServerConfigsButton](ResponseStatus status) {
        NotificationService::connectionError(status);
        saveServerConfigsButton->setLoading(false);
        Configuration::getInstance().setServerAddress("");
        Configuration::getInstance().setToken("");
    });

    mainLayout->addStretch(3);
}
