#ifndef GITLAB_DESKTOP_MONITOR_PROJECTSLISTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_PROJECTSLISTWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QVBoxLayout>

#include "LoadableContentWidget.h"


class ProjectsListWidget : public QFrame {
Q_OBJECT
public:
    explicit ProjectsListWidget(QWidget * parent = nullptr);

signals:
    void projectSelected(int projectId, QString projectName);

private:
    void setupUi();
    void updateUi();
    void emptyScrollLayout();

    // TODO: Better names?!
    QVBoxLayout * scrollLayout = nullptr;
    LoadableContentWidget * contentWidget = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECTSLISTWIDGET_H
