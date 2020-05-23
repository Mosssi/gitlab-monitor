#ifndef GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>

#include "../models/Project.h"

class ProjectWidget : public QFrame {
public:
    explicit ProjectWidget(int projectId, bool oddRow, QWidget * parent = nullptr);

private:
    void setupUi();

    int projectId;
    bool oddRow;

    QHBoxLayout * mainLayout = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H
