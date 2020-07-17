#include "Label.h"

#include <QResizeEvent>

#include "../../utilities/GuiManager.h"

Label::Label(const QString &text, bool elided, QWidget * parent) : QLabel(text, parent), StyledWidget(), fontSize(GuiManager::normalFontSize()), elided(elided) {

    Label::updateStyleSheet();
}

void Label::setFontSize(int t_fontSize) {

    this->fontSize = t_fontSize;
    Label::updateStyleSheet();
}

void Label::setBold(bool bold) {

    this->bold = bold;
    Label::updateStyleSheet();
}

void Label::setColor(const TextColor &color) {

    this->color = color;
    Label::updateStyleSheet();
}

void Label::setGeneralStyle(const QString &generalStyle) {

    this->generalStyle = generalStyle;
    Label::updateStyleSheet();
}

void Label::updateStyleSheet() {

    QString textColor = GuiManager::getTheme().textColor();
    switch (color) {
        case TextColor::SECONDARY:
            textColor = GuiManager::getTheme().secondaryTextColor();
            break;
        case TextColor::TERTIARY:
            textColor = GuiManager::getTheme().tertiaryTextColor();
            break;
        case TextColor::TITLE:
            textColor = GuiManager::getTheme().titleColor();
            break;
        case TextColor::INFO_NOTIFICATION:
            textColor = GuiManager::getTheme().infoNotificationTextColor();
            break;
        case TextColor::ERROR_NOTIFICATION:
            textColor = GuiManager::getTheme().errorNotificationColor();
            break;
        case TextColor::PRIMARY:
        default:
            break;
    }

    setStyleSheet(
            QString("font-size: %1px; font-weight: %2; color: %3; background-color: %4; %5")
                    .arg(this->fontSize)
                    .arg(this->bold ? "bold" : "normal")
                    .arg(textColor)
                    .arg(this->backgroundColor)
                    .arg(generalStyle)
    );
}

void Label::setStyleSheet(const QString &styleSheet) {

    QWidget::setStyleSheet(styleSheet);
}

void Label::setBackgroundColor(const QString &backgroundColor) {

    this->backgroundColor = backgroundColor;
    Label::updateStyleSheet();
}

void Label::resizeEvent(QResizeEvent * event) {

    QWidget::resizeEvent(event);
    elideText(event->size().width());
}

void Label::elideText(int availableWidth) {

    if (!elided) {
        return;
    }

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
