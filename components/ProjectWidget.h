#ifndef GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

#include "../models/Project.h"
#include "library/Label.h"

class ProjectWidget : public QFrame {
public:
    explicit ProjectWidget(int projectId, bool oddRow, QWidget * parent = nullptr);

private:
    void setupUi();
    void updateUi();
    void toggleProjectStar();
    void enterEvent(QEvent * event) override;
    void leaveEvent(QEvent * event) override;

    int projectId;
    bool oddRow;

    Label * nameLabel = nullptr;
    Label * descriptionLabel = nullptr;
    Label * openIssuesCountLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H
