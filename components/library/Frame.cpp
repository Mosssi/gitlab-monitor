#include "Frame.h"

#include <QDebug>

#include "../../utilities/Configuration.h"

Frame::Frame(QWidget * parent) : QFrame(parent), StyledWidget() {

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

    setStyleSheet(
            QString(".QFrame {background-color: %1; %2}")
                    .arg(backgroundColor)
                    .arg(generalStyle)
    );
}
