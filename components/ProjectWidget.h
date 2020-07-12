#ifndef GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H


#include "../models/Project.h"
#include "library/Label.h"
#include "library/HoverClickFrame.h"

class ProjectWidget : public HoverClickFrame {
Q_OBJECT
public:
    explicit ProjectWidget(int projectId, QWidget * parent = nullptr);

private:
    void setupUi();
    void updateUi();
    void updateStyleSheet() override;

    int projectId;

    Label * nameLabel = nullptr;
    Label * descriptionLabel = nullptr;
    Label * openIssuesCountLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H
