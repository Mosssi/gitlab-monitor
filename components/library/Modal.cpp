#include "Modal.h"

#include "../../utilities/GuiManager.h"
#include "Label.h"

Modal::Modal(const QString &title, QWidget * parent) : Frame(parent), title(title) {

    setBackgroundColor("#44000000");
    setFixedSize(GuiManager::applicationWidth(), GuiManager::applicationHeight());
    setupUi();
}

void Modal::setupUi() {

    auto * mainWidget = new Frame(this);
    mainWidget->setFixedSize(GuiManager::configurationWindowWidth(), GuiManager::configurationWindowHeight());
    mainWidget->setBackgroundColor(GuiManager::whiteColor());
    mainWidget->setGeneralStyle("border-radius: 6px;");
    mainWidget->move(
            (GuiManager::applicationWidth() - GuiManager::configurationWindowWidth()) / 2,
            (GuiManager::applicationHeight() - GuiManager::configurationWindowHeight()) / 2
    );

    auto * layout = new QVBoxLayout(mainWidget);
    layout->setContentsMargins(0, 0, 0, 0);

    auto * titleFrame = new Frame();
    auto * titleLayout = new QHBoxLayout(titleFrame);
    titleFrame->setBackgroundColor(GuiManager::darkLightColor());
    titleFrame->setGeneralStyle("border-bottom-left-radius: 0; border-bottom-right-radius: 0;");
    titleFrame->setFixedHeight(GuiManager::bodyHeaderHeight());
    auto titleLabel = new Label(title);
    titleLabel->setColor(GuiManager::lightGrayColor());
    titleLayout->addWidget(titleLabel, 0, Qt::AlignVCenter | Qt::AlignLeft);

    layout->addWidget(titleFrame);

    mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(5, 5, 5, 5);
    layout->addLayout(mainLayout);
}
