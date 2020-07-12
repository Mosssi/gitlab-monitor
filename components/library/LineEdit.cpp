#include "LineEdit.h"

#include "../../utilities/GuiManager.h"

LineEdit::LineEdit(QWidget * parent) : QLineEdit(parent) {

    setFixedHeight(GuiManager::pushButtonHeight() + 2);
    LineEdit::updateStyleSheet();
}

void LineEdit::updateStyleSheet() {

    setStyleSheet(
            QString("background-color: %1; font-size: %2px; border: 1px solid %3; border-radius: 2px;")
                    .arg(GuiManager::buttonColor()) // TODO: Define color
                    .arg(GuiManager::normalFontSize())
                    .arg(GuiManager::buttonHoverColor()) // TODO: Define color
    );
}
