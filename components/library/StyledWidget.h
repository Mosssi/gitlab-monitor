#ifndef GITLAB_DESKTOP_MONITOR_STYLEDWIDGET_H
#define GITLAB_DESKTOP_MONITOR_STYLEDWIDGET_H


#include <QtCore/QArgument>

class StyledWidget {
public:
    explicit StyledWidget();
    ~StyledWidget();

private:
    virtual void updateStyleSheet() = 0;

    QMetaObject::Connection connection;
};


#endif //GITLAB_DESKTOP_MONITOR_STYLEDWIDGET_H
