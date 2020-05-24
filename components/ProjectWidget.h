#ifndef GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H


#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

#include "../models/Project.h"

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

    QLabel * nameLabel = nullptr;
    QLabel * descriptionLabel = nullptr;
    QPushButton * starButton = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_PROJECTWIDGET_H
