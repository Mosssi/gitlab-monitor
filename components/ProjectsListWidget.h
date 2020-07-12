#ifndef GITLAB_DESKTOP_MONITOR_PROJECTSLISTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_PROJECTSLISTWIDGET_H


#include <QtWidgets/QVBoxLayout>

#include "LoadableContentWidget.h"
#include "library/Frame.h"
#include "library/Label.h"


class ProjectsListWidget : public Frame {
Q_OBJECT
public:
    explicit ProjectsListWidget(QWidget * parent = nullptr);

signals:
    void projectSelected(int projectId, QString projectName);

private:
    void setupUi();
    void updateUi();
    void emptyScrollLayout();
    void updateStyleSheet() override;

    // TODO: Better names?!
    QVBoxLayout * scrollLayout = nullptr;
    LoadableContentWidget * contentWidget = nullptr;
    Frame * topFrame;
    Label * starredIssuesLabel;
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECTSLISTWIDGET_H
