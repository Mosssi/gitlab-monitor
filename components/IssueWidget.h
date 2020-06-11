#ifndef GITLAB_DESKTOP_MONITOR_ISSUEWIDGET_H
#define GITLAB_DESKTOP_MONITOR_ISSUEWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

#include "library/Label.h"
#include "../models/Issue.h"

class IssueWidget : public QFrame {
Q_OBJECT
public:
    explicit IssueWidget(int projectId, const Issue &issue, QWidget * parent = nullptr);

signals:
    void clicked();
    void closed();

private:
    void setupUi();
    void updateUi();
    void enterEvent(QEvent * event) override;
    void leaveEvent(QEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;

    Issue issue;
    int projectId;

    Label * nameLabel = nullptr;
    Label * iidLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_ISSUEWIDGET_H
