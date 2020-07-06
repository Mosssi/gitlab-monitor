#include "Frame.h"

Frame::Frame(QWidget * parent) : QFrame(parent) {

}

void Frame::setBackgroundColor(const QString &color) {

    setStyleSheet("background-color: " + color + ";");
}
