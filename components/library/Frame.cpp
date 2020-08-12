#include "Frame.h"

Frame::Frame(QWidget * parent) : QFrame(parent), StyledWidget() {

    Frame::updateStyleSheet();
}

void Frame::setBackgroundColor(const QString &backgroundColor) {

    this->backgroundColor = backgroundColor;
    Frame::updateStyleSheet();
}

void Frame::setGeneralStyle(const QString &generalStyle) {

    this->generalStyle = generalStyle;
    Frame::updateStyleSheet();
}

void Frame::updateStyleSheet() {

    setStyleSheet(
            QString("background-color: %1; %2")
                    .arg(backgroundColor)
                    .arg(generalStyle)
    );
}

void Frame::resizeEvent(QResizeEvent * event) {

    QWidget::resizeEvent(event);
    emit resized();
}
