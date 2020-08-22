#ifndef GITLAB_DESKTOP_MONITOR_ISSUESLISTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_ISSUESLISTWIDGET_H

#include <QtWidgets/QVBoxLayout>

#include "IssueInputWindow.h"
#include "LoadableContentWidget.h"
#include "library/Frame.h"
#include "library/Label.h"

class IssuesListWidget : public Frame {
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
    void requestIssueCreation(const QString &issueTitle);
    void updateStyleSheet() override;

    int projectId = 0;

    QVBoxLayout * scrollLayout = nullptr;
    Label * projectNameLabel = nullptr;
    LoadableContentWidget * contentWidget = nullptr;
    Frame * headerFrame = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_ISSUESLISTWIDGET_H
