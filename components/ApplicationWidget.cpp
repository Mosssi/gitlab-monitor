#include "ApplicationWidget.h"

#include <QApplication>
#include <QScreen>
#include <QtWidgets/QVBoxLayout>
#include <QDesktopWidget>

#include "../models/Project.h"
#include "../models/User.h"
#include "../network/ServiceMediator.h"
#include "../utilities/Configuration.h"
#include "../utilities/DataStore.h"
#include "../utilities/GuiManager.h"
#include "BodyWidget.h"
#include "HeaderWidget.h"
#include "SystemTrayIcon.h"

ApplicationWidget::ApplicationWidget(QWidget * parent) : QWidget(parent) {

    setupTrayIcon();
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
    setFixedSize(GuiManager::applicationWidth(), GuiManager::applicationHeight());
    setStyleSheet(QString("background-color: %1; color: %2;").arg(GuiManager::lightColor()).arg(GuiManager::darkGrayColor()));
    setupUi();

    Configuration::getInstance().setToken("BEqfZheThA3cR9bpLMF-");

    DataStore::getInstance().initialize();

    GuiManager::setApplicationWindow(this);

    contextMenu = new ContextMenu();
    contextMenu->setVisible(false);

    connect(contextMenu, &ContextMenu::openClicked, [this]() {
        contextMenu->setVisible(false);
        showApplication();
    });

    connect(contextMenu, &ContextMenu::exitClicked, [this]() {
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
        contextMenu->move(calculateShowPoint(GuiManager::contextMenuButtonWidth(), GuiManager::contextMenuButtonHeight() * 2, false)); // TODO: Fix number 2
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

    mainLayout->addWidget(new HeaderWidget());
    mainLayout->addWidget(new BodyWidget());
}
