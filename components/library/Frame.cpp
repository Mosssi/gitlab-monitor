#include "Frame.h"

Frame::Frame(QWidget * parent) : QFrame(parent) {

}

void Frame::setBackgroundColor(const QString &backgroundColor) {

    this->backgroundColor = backgroundColor;
    updateStyleSheet();
}

void Frame::setGeneralStyle(const QString &generalStyle) {

    this->generalStyle = generalStyle;
    updateStyleSheet();
}

void Frame::updateStyleSheet() {

    this->setStyleSheet(
            QString("background-color: %1; %2")
                    .arg(backgroundColor)
                    .arg(generalStyle)
    );
}
