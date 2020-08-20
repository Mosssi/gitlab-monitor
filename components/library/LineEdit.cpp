#include "LineEdit.h"

#include "../../utilities/GuiManager.h"

LineEdit::LineEdit(QWidget * parent) : QLineEdit(parent), StyledWidget() {

    setFixedHeight(GuiManager::pushButtonHeight() + 2);
    LineEdit::updateStyleSheet();
}

void LineEdit::setHasError(bool hasError) {

    this->hasError = hasError;
    LineEdit::updateStyleSheet();
}

void LineEdit::updateStyleSheet() {

    setStyleSheet(
            QString("background-color: %1; font-size: %2px; color: %3; border-radius: 2px; padding-left: 3px; padding-right: 3px; %4;")
                    .arg(GuiManager::getTheme().lineEditBackgroundColor())
                    .arg(GuiManager::normalFontSize())
                    .arg(GuiManager::getTheme().textColor())
                    .arg(hasError ? "border: 1px solid " + GuiManager::getTheme().lineEditErrorBackgroundColor() : "")
    );
}
