#include "Modal.h"

#include "../../utilities/GuiManager.h"

Modal::Modal(const QString &title, QWidget * parent) : Frame(parent), title(title) {

    setFixedSize(GuiManager::applicationWidth(), GuiManager::applicationHeight());
    setupUi();
    Modal::updateStyleSheet();
}

void Modal::setupUi() {

    mainWidget = new Frame(this);
    mainWidget->setFixedWidth(GuiManager::configurationWindowWidth());
    mainWidget->setGeneralStyle("border-radius: 6px;");
    mainWidget->move(
            (GuiManager::applicationWidth() - GuiManager::configurationWindowWidth()) / 2,
            (GuiManager::applicationHeight() - GuiManager::configurationWindowHeight()) / 2
    );

    auto * layout = new QVBoxLayout(mainWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    titleFrame = new Frame();
    auto * titleLayout = new QHBoxLayout(titleFrame);
    titleFrame->setGeneralStyle("border-bottom-left-radius: 0; border-bottom-right-radius: 0;");
    titleFrame->setFixedHeight(GuiManager::bodyHeaderHeight());
    auto * titleLabel = new Label(title);
    titleLabel->setColor(TextColor::TITLE);
    titleLayout->addWidget(titleLabel, 0, Qt::AlignVCenter | Qt::AlignLeft);

    layout->addWidget(titleFrame);

    mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(5);
    layout->addLayout(mainLayout);
}

void Modal::updateStyleSheet() {

    setBackgroundColor("#44000000");
    mainWidget->setBackgroundColor(GuiManager::getTheme().backgroundColor());
    titleFrame->setBackgroundColor(GuiManager::getTheme().headerColor());
}

void Modal::mouseReleaseEvent(QMouseEvent * event) {

    if (!mainWidget->underMouse()) {
        emit closed();
    }
}
