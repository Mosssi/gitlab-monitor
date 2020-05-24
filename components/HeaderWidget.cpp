#include "HeaderWidget.h"

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>

#include "../utilities/GuiManager.h"
#include "../utilities/DataStore.h"


HeaderWidget::HeaderWidget(QWidget * parent) : QFrame(parent) {

    setupUi();

    connect(&DataStore::getInstance(), &DataStore::userReceived, [this](const User &user) {
        userWelcomeLabel->setText(QString("Welcome, %1!").arg(user.username));
    });
}

void HeaderWidget::setupUi() {

    setFixedHeight(GuiManager::headerHeight());
    setStyleSheet(QString("background-color: %1; color: %2;").arg(GuiManager::purpleColor()).arg(GuiManager::lightColor()));

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    auto * topFrame = new QFrame();
    topFrame->setStyleSheet(QString("background-color: %1; color: %2; font-size: %3px;").arg(GuiManager::lightPurpleColor()).arg(GuiManager::darkGrayColor()).arg(GuiManager::smallFontSize()));
    topFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    auto * topLayout = new QHBoxLayout(topFrame);
    topLayout->setContentsMargins(10, 5, 10, 5);
    topLayout->addWidget(userWelcomeLabel = new QLabel(), 0, Qt::AlignRight);

    mainLayout->addWidget(topFrame);

    auto * bottomLayout = new QHBoxLayout();
    bottomLayout->setContentsMargins(10, 10, 10, 10);
    bottomLayout->addWidget(new QLabel("GITLAB DESKTOP MONITOR"));

    mainLayout->addLayout(bottomLayout);
}
