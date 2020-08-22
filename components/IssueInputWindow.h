#ifndef GITLAB_DESKTOP_MONITOR_ISSUEINPUTWINDOW_H
#define GITLAB_DESKTOP_MONITOR_ISSUEINPUTWINDOW_H

#include "library/LineEdit.h"
#include "library/Modal.h"
#include "library/ModalToggle.h"
#include "library/PushButton.h"

class IssueInputWindow : public Modal {
Q_OBJECT
public:
    explicit IssueInputWindow(QWidget * parent = nullptr);
    void clearInput();
    void setLoading(bool loading);

signals:
    void submitted(const QString &issueTitle);

private:
    void setupUi();

    LineEdit * issueTitleInput = nullptr;
    PushButton * createButton = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_ISSUEINPUTWINDOW_H
