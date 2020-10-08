#include "ApplicationWidget.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QScreen>

#include "../constants.h"
#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "../utilities/LogService.h"
#include "HeaderWidget.h"
#include "ModalManager.h"
#include "SystemTrayIcon.h"
#include "WelcomeWidget.h"

ApplicationWidget::ApplicationWidget(QWidget * parent) : Frame(parent) {

    setupTrayIcon();
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    setFixedSize(GuiManager::applicationWidth(), GuiManager::applicationHeight());
    setWindowTitle(APP_PRESENTATION);
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

    connect(contextMenu, &ContextMenu::exitClicked, []() {
        QApplication::exit(0);
    });
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

    auto * contentWidget = new QWidget();
    auto * contentLayout = new QVBoxLayout(contentWidget);
    contentLayout->setContentsMargins(0, 0, 0, 0);
    contentLayout->setSpacing(0);
    contentLayout->addWidget(new HeaderWidget());
    contentLayout->addWidget(bodyWidget = new BodyWidget());

    auto * welcomeWidget = new WelcomeWidget();
    stackedWidget->addWidget(welcomeWidget);
    stackedWidget->addWidget(contentWidget);

    if (!Configuration::getInstance().getServerAddress().isEmpty() &&
        !Configuration::getInstance().getToken().isEmpty() &&
        Configuration::getInstance().getValidConfigs()) {
        showContents();
    }

    connect(welcomeWidget, &WelcomeWidget::serverAndTokenValidated, this, &ApplicationWidget::showContents);
}

void ApplicationWidget::updateStyleSheet() {

    setBackgroundColor(GuiManager::getTheme().backgroundColor());
}

void ApplicationWidget::logout() {

    DataStore::getInstance().clear();
    Configuration::getInstance().setServerAddress("");
    Configuration::getInstance().setToken("");
    Configuration::getInstance().setValidConfigs(false);
    stackedWidget->setCurrentIndex(0);
}

void ApplicationWidget::closeEvent(QCloseEvent * event) {

    QWidget::closeEvent(event);
    ModalManager::getInstance().hideIssueInputWindow();
    ModalManager::getInstance().hideConfigurationWindow();
}

void ApplicationWidget::keyPressEvent(QKeyEvent * event) {

    if (event->key() != Qt::Key_Escape) {
        QWidget::keyPressEvent(event);
        return;
    }

    if (ModalManager::getInstance().getConfigurationWindow()->isVisible()) {
        ModalManager::getInstance().hideConfigurationWindow();
    } else if (ModalManager::getInstance().getIssueInputWindow()->isVisible()) {
        ModalManager::getInstance().hideIssueInputWindow();
    } else if (bodyWidget->isIssuesListVisible()) {
        bodyWidget->showProjectList();
    } else {
        QWidget::keyPressEvent(event);
    }
}

void ApplicationWidget::showContents() {

    DataStore::getInstance().initialize();
    stackedWidget->setCurrentIndex(1);
}
