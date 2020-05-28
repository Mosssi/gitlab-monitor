#include "PushButton.h"
#include "../../utilities/GuiManager.h"

PushButton::PushButton(const IconType &icon, QWidget * parent) : QPushButton(getIconTypeString(icon), parent) {

    setFixedSize(GuiManager::pushButtonHeight(), GuiManager::pushButtonHeight());
    setFont(GuiManager::iconFont());
    setStyleSheet(
            QString(
                    ".QPushButton {background-color: %1; border-radius: %2px; color: %3; font-size: %4px;}"
                    ".QPushButton::hover {background-color: %5;}"
            )
                    .arg("#22000000") // TODO: Find a better way
                    .arg(GuiManager::pushButtonHeight() / 2)
                    .arg(GuiManager::grayColor())
                    .arg(GuiManager::smallFontSize())
                    .arg("#33000000")
    );
}
