#include <QApplication>
#include <QDebug>

#include "components/ApplicationWidget.h"
#include "utilities/GuiManager.h"

int main(int argc, char ** argv) {
    QApplication application(argc, argv);
    QApplication::setFont(GuiManager::applicationFont());

    ApplicationWidget widget;

    return QApplication::exec();
}
