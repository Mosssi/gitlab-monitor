#include "ApplicationWidget.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QtWidgets/QVBoxLayout>
#include <QKeyEvent>

#include "../models/Project.h"
#include "../models/User.h"
#include "../network/ServiceMediator.h"
#include "../utilities/GuiManager.h"
#include "BodyWidget.h"
#include "HeaderWidget.h"
#include "SystemTrayIcon.h"
#include "../utilities/LogService.h"
#include "WelcomeWidget.h"

ApplicationWidget::ApplicationWidget(QWidget * parent) : Frame(parent) {

    setupTrayIcon();
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    setFixedSize(GuiManager::applicationWidth(), GuiManager::applicationHeight());
    setWindowTitle("GitLab Monitor");
    ApplicationWidget::updateStyleSheet();

    LogService::getInstance().initializeService(true, false);
    GuiManager::setApplicationWindow(this);

    setupUi();

    contextMenu = new ContextMenu();
    contextMenu->setVisible(false);

    connect(contextMenu, &ContextMenu::openClicked, [this]() {
        contextMenu->setVisible(false);
        showApplication();
    });

    connect(contextMenu, &ContextMenu::exitClicked, [this]() {
        QApplication::exit(0);
    });

    configurationWindow = new ConfigurationWindow(this);
    configurationWindow->hide();
    configurationWindow->move(0, 0);
    connect(configurationWindow, &ConfigurationWindow::closed, this, &ApplicationWidget::hideConfiguration);
}

void ApplicationWidget::setupTrayIcon() {

    systemTrayIcon = new SystemTrayIcon();
    systemTrayIcon->setParent(this);

    auto calculateShowPoint = [this](int width, int height, bool middle) -> QPoint {
        const QPoint &cursorPosition = QCursor::pos();
        const int availableHeight = QApplication::primaryScreen()->availableGeometry().height();
        const int availableWidth = QApplication::desktop()->size().width();
        int x = qMin(cursorPosition.x() - (middle ? width / 2 : 0), availableWidth - width);
        int y = QApplication::primaryScreen()->availableGeometry().y();
        if (cursorPosition.y() > availableHeight / 2) {
            y = availableHeight - height;
        }
        return QPoint(x, y);
    };

    showApplication = [this, calculateShowPoint]() {
        move(calculateShowPoint(GuiManager::applicationWidth(), GuiManager::applicationHeight(), true));
        if (contextMenu->isVisible()) {
            contextMenu->setVisible(false);
        } else {
            this->setVisible(!this->isVisible());
        }
    };

    connect(systemTrayIcon, &SystemTrayIcon::clicked, showApplication);

    connect(systemTrayIcon, &SystemTrayIcon::rightClicked, [this, calculateShowPoint]() {
        contextMenu->move(
                calculateShowPoint(GuiManager::contextMenuButtonWidth(), GuiManager::contextMenuButtonHeight() * 2, false)  // TODO: Fix number 2
        );
        if (isVisible()) {
            setVisible(false);
        }
        contextMenu->setVisible(!contextMenu->isVisible());
    });
}

void ApplicationWidget::setupUi() {

    auto * mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    stackedWidget = new QStackedWidget();
    mainLayout->addWidget(stackedWidget);

    auto * goodbyeWidget = new QWidget();
    auto * goodbyeLayout = new QVBoxLayout(goodbyeWidget);
    goodbyeLayout->setContentsMargins(0, 0, 0, 0);
    goodbyeLayout->setSpacing(0);
    goodbyeLayout->addWidget(new HeaderWidget());
    goodbyeLayout->addWidget(new BodyWidget());

    auto * welcomeWidget = new WelcomeWidget();
    stackedWidget->addWidget(welcomeWidget);
    stackedWidget->addWidget(goodbyeWidget);

    if (!Configuration::getInstance().getServerAddress().isEmpty() && !Configuration::getInstance().getToken().isEmpty()) {
        stackedWidget->setCurrentWidget(goodbyeWidget);
    }
    
    connect(welcomeWidget, &WelcomeWidget::serverAndTokenValidated, [this, goodbyeWidget]() {
        stackedWidget->setCurrentWidget(goodbyeWidget);
    });
}

void ApplicationWidget::showConfiguration() {

    configurationWindow->show();
}

void ApplicationWidget::hideConfiguration() {

    configurationWindow->hide();
}

void ApplicationWidget::updateStyleSheet() {

    setBackgroundColor(GuiManager::getTheme().backgroundColor());
}

void ApplicationWidget::logout() {

    Configuration::getInstance().setServerAddress("");
    Configuration::getInstance().setToken("");
    stackedWidget->setCurrentIndex(0);
}

void ApplicationWidget::closeEvent(QCloseEvent * event) {

    QWidget::closeEvent(event);
    hideConfiguration();
}

void ApplicationWidget::keyPressEvent(QKeyEvent * event) {

    if (configurationWindow->isVisible() && event->key() == Qt::Key_Escape) {
        hideConfiguration();
    } else {
        QWidget::keyPressEvent(event);
    }
}
