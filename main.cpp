#include <QApplication>
#include <QtGui/QFontDatabase>

#include "components/ApplicationWidget.h"
#include "utilities/GuiManager.h"



int main(int argc, char ** argv) {
    QApplication application(argc, argv);
    QApplication::setFont(GuiManager::applicationFont());
    QApplication::setOrganizationName("Mosssi");
    QApplication::setApplicationName("gitlab-monitor");
    QFontDatabase::addApplicationFont(":/fonts/gitlab-monitoring.ttf");

    ApplicationWidget widget;

    return QApplication::exec();
}
