#ifndef GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

#include "../models/Project.h"
#include "library/Label.h"

class ProjectWidget : public QFrame {
Q_OBJECT
public:
    explicit ProjectWidget(int projectId, QWidget * parent = nullptr);

signals:
    void clicked();

private:
    void setupUi();
    void updateUi();
    void enterEvent(QEvent * event) override;
    void leaveEvent(QEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;

    int projectId;

    Label * nameLabel = nullptr;
    Label * descriptionLabel = nullptr;
    Label * openIssuesCountLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H
