#ifndef GITLAB_DESKTOP_MONITOR_ISSUESLISTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_ISSUESLISTWIDGET_H


#include <QFrame>
#include <QtWidgets/QVBoxLayout>

#include "library/Label.h"
#include "IssueInputWidget.h"

class IssuesListWidget : public QFrame {
Q_OBJECT
public:
    explicit IssuesListWidget(QWidget * parent = nullptr);
    void setProjectId(int projectId);

signals:
    void backClicked(); // TOCONSIDER: What about a universal template for naming signals?!

private:
    void setupUi();
    void updateUi();
    void emptyScrollLayout();

    int projectId = 0;

    IssueInputWidget * issueInputWidget = nullptr;
    QVBoxLayout * scrollLayout = nullptr;
    Label * projectNameLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_ISSUESLISTWIDGET_H
