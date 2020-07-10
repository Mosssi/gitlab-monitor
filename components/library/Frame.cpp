#include "Frame.h"
#include "../../utilities/Configuration.h"

#include <QDebug>

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

    qDebug() << "here we are" << Configuration::getInstance().getDarkTheme();
}
