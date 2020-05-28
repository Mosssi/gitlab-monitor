#ifndef GITLAB_DESKTOP_MONITOR_PROJECTSLISTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_PROJECTSLISTWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QVBoxLayout>


class ProjectsListWidget : public QFrame {
Q_OBJECT
public:
    explicit ProjectsListWidget(QWidget * parent = nullptr);

signals:
    void projectSelected(int projectId);

private:
    void setupUi();
    void updateUi();

    QVBoxLayout * scrollLayout = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECTSLISTWIDGET_H
