#include "Label.h"

#include <QResizeEvent>

Label::Label(const QString &text, QWidget * parent) : QLabel(text, parent) {

    updateStyleSheet();
}

void Label::setFontSize(int t_fontSize) {

    this->fontSize = t_fontSize;
    updateStyleSheet();
}

void Label::setBold(bool bold) {

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
            QString("font-size: %1px; font-weight: %2; color: %3; background-color: %4; %5")
                    .arg(this->fontSize)
                    .arg(this->bold ? "bold" : "normal")
                    .arg(this->color)
                    .arg(this->backgroundColor)
                    .arg(generalStyle)
    );
}

void Label::setStyleSheet(const QString &styleSheet) {

    QWidget::setStyleSheet(styleSheet);
}

void Label::setBackgroundColor(const QString &backgroundColor) {

    this->backgroundColor = backgroundColor;
    updateStyleSheet();
}

void Label::resizeEvent(QResizeEvent * event) {

    QWidget::resizeEvent(event);
    elideText(event->size().width());
}

void Label::elideText(int availableWidth) {

    QFontMetrics fontMetrics(font());
    if (fontMetrics.width(text()) > availableWidth) {
        QString elidedText;
        QString labelText = text();
        int lengthReduction = 4;
        do {
            elidedText = labelText.mid(0, labelText.length() - lengthReduction++);
        } while (fontMetrics.width(elidedText + "...") > availableWidth);
        setText(elidedText + "...");
    }
}
