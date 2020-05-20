#include <QApplication>
#include "components/ApplicationWidget.h"

int main(int argc, char ** argv) {
    QApplication application(argc, argv);

    ApplicationWidget widget;
    widget.show();

    return QApplication::exec();
}
