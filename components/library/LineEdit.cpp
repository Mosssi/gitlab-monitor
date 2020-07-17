#include "LineEdit.h"

#include "../../utilities/GuiManager.h"

LineEdit::LineEdit(QWidget * parent) : QLineEdit(parent), StyledWidget() {

    setFixedHeight(GuiManager::pushButtonHeight() + 2);
    LineEdit::updateStyleSheet();
}

void LineEdit::updateStyleSheet() {

    setStyleSheet(
            QString("background-color: %1; font-size: %2px; color: %3; border-radius: 2px;")
                    .arg(GuiManager::getTheme().buttonColor()) // TODO: Define color
                    .arg(GuiManager::normalFontSize())
                    .arg(GuiManager::getTheme().textColor())
    );
}
