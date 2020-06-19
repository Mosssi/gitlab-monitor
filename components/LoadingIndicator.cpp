#include "LoadingIndicator.h"

#include <QtWidgets/QHBoxLayout>

#include "../utilities/GuiManager.h"
#include "library/LoadingWidget.h"

LoadingIndicator &LoadingIndicator::getInstance() {

    static LoadingIndicator instance;
    return instance;
}

LoadingIndicator::LoadingIndicator(QWidget * parent) : QFrame(parent) {

    setFixedSize(GuiManager::loadingIndicatorWidth(), GuiManager::loadingIndicatorHeight());
    setStyleSheet("QWidget {background-color: none;} QFrame {background-color: #CCCCCCCC; border-radius: 5px;}");
    move(
            (GuiManager::applicationWidth() - GuiManager::loadingIndicatorWidth()) / 2,
            (GuiManager::applicationHeight() - GuiManager::loadingIndicatorHeight()) / 2
    );

    setupUi();
}

void LoadingIndicator::setupUi() {

    auto * mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(new LoadingWidget(), 0, Qt::AlignCenter);
}

void LoadingIndicator::startLoading() {

    setVisible(true);
}

void LoadingIndicator::stopLoading() {

    setVisible(false);
}
