#ifndef GITLAB_DESKTOP_MONITOR_ISSUEINPUTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_ISSUEINPUTWIDGET_H


#include <QtWidgets/QFrame>

#include "library/LineEdit.h"

class IssueInputWidget : public QFrame {
public:
    explicit IssueInputWidget();
    void setProjectId(int projectId);
    void clearInput();

private:
    void setupUi();

    int projectId = 0;

    LineEdit * issueTitleInput = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_ISSUEINPUTWIDGET_H
