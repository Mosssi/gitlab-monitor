#include "WelcomeWidget.h"

#include <QtWidgets/QVBoxLayout>
#include <QKeyEvent>

#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "../utilities/NotificationService.h"
#include "library/Label.h"

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
    serverAddressInput = new LineEdit();
    serverAddressInput->setText("https://gitlab.com");
    mainLayout->addWidget(new Label("SERVER ADDRESS:", GuiManager::smallFontSize(), TextColor::TERTIARY));
    mainLayout->addWidget(serverAddressInput);
    connect(serverAddressInput, &LineEdit::textChanged, [this]() {
        serverAddressInput->setHasError(false);
    });

    mainLayout->addSpacing(10);
    tokenInput = new LineEdit();
    mainLayout->addWidget(new Label("TOKEN:", GuiManager::smallFontSize(), TextColor::TERTIARY));
    mainLayout->addWidget(tokenInput);
    connect(tokenInput, &LineEdit::textChanged, [this]() {
        tokenInput->setHasError(false);
    });

    saveServerConfigsButton = new PushButton(IconType::DONE);
    connect(saveServerConfigsButton, &PushButton::clicked, this, &WelcomeWidget::validateServerAndToken);

    mainLayout->addSpacing(10);
    mainLayout->addWidget(saveServerConfigsButton, 0, Qt::AlignCenter);

    connect(&DataStore::getInstance(), &DataStore::userReceived, [this]() {
        saveServerConfigsButton->setLoading(false);
        // TODO: Fix here
        if (!Configuration::getInstance().getValidCredentials()) {
            Configuration::getInstance().setValidCredentials(true);
            emit serverAndTokenValidated();
        }
    });

    connect(&DataStore::getInstance(), &DataStore::userReceiveFailed, [this](ResponseStatus status) {
        NotificationService::connectionError(status);
        saveServerConfigsButton->setLoading(false);
        if (!Configuration::getInstance().getValidCredentials()) {
            Configuration::getInstance().setServerAddress("");
            Configuration::getInstance().setToken("");
            Configuration::getInstance().setValidCredentials(false);
        }
    });

    mainLayout->addStretch(3);
}

void WelcomeWidget::keyReleaseEvent(QKeyEvent * event) {

    if (event->key() == Qt::Key_Return) {
        validateServerAndToken();
    }
    QWidget::keyPressEvent(event);
}

void WelcomeWidget::validateServerAndToken() {

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
}
