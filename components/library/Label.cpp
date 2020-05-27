#include "Label.h"

Label::Label(const QString &text, QWidget * parent) : QLabel(text, parent) {

    updateStyleSheet();
}

void Label::setFontSize(int t_fontSize) {

    this->fontSize = t_fontSize;
    updateStyleSheet();
}

[[maybe_unused]] void Label::setBold(bool bold) {

    this->bold = bold;
    updateStyleSheet();
}

void Label::setColor(const QString &color) {

    this->color = color;
    updateStyleSheet();
}

[[maybe_unused]] void Label::setGeneralStyle(const QString &generalStyle) {

    this->generalStyle = generalStyle;
    updateStyleSheet();
}

void Label::updateStyleSheet() {

    this->setStyleSheet(
            QString("font-size: %1px; font-weight: %2; color: %3; %4")
                    .arg(this->fontSize)
                    .arg(this->bold ? "bold" : "normal")
                    .arg(this->color)
                    .arg(generalStyle)
    );
}

void Label::setStyleSheet(const QString &styleSheet) {

    QWidget::setStyleSheet(styleSheet);
}
