#ifndef GITLAB_DESKTOP_MONITOR_ISSUEWIDGET_H
#define GITLAB_DESKTOP_MONITOR_ISSUEWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

#include "library/Label.h"
#include "../models/Issue.h"

class IssueWidget : public QFrame {
Q_OBJECT
public:
    explicit IssueWidget(const Issue &issue, QWidget * parent = nullptr);
    void setIssue(const Issue &issue); // TOCONSIDER: what about setModel for all?

signals:
    void clicked();

private:
    void setupUi();
    void updateUi();
    void enterEvent(QEvent * event) override;
    void leaveEvent(QEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;

    Issue issue;

    Label * nameLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_ISSUEWIDGET_H
