#include "ResizeAwareWidget.h"

ResizeAwareWidget::ResizeAwareWidget(QWidget * parent) : QWidget(parent) {

}

void ResizeAwareWidget::resizeEvent(QResizeEvent * event) {

    QWidget::resizeEvent(event);
    emit resized();
}
