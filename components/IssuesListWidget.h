#ifndef GITLAB_DESKTOP_MONITOR_ISSUESLISTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_ISSUESLISTWIDGET_H


#include <QFrame>
#include <QtWidgets/QVBoxLayout>

#include "library/Label.h"
#include "IssueInputWidget.h"
#include "LoadableContentWidget.h"

class IssuesListWidget : public QFrame {
Q_OBJECT
public:
    explicit IssuesListWidget(QWidget * parent = nullptr);
    void setProjectId(int projectId);
    void setProjectName(const QString &projectName);
    void refreshList(bool forceLoading = false);

signals:
    void backClicked(); // TOCONSIDER: What about a universal template for naming signals?!

private:
    void setupUi();
    void updateUi();
    void emptyScrollLayout();
    void showIssueInputWidget();
    void hideIssueInputWidget();
    void requestIssueCreation(const QString &issueTitle);

    int projectId = 0;

    IssueInputWidget * issueInputWidget = nullptr;
    QVBoxLayout * scrollLayout = nullptr;
    Label * projectNameLabel = nullptr;
    LoadableContentWidget * contentWidget = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_ISSUESLISTWIDGET_H
