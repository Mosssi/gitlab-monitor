#ifndef GITLAB_DESKTOP_MONITOR_STYLEDWIDGET_H
#define GITLAB_DESKTOP_MONITOR_STYLEDWIDGET_H


class StyledWidget {
public:
    explicit StyledWidget();

private:
    virtual void updateStyleSheet() = 0;
};


#endif //GITLAB_DESKTOP_MONITOR_STYLEDWIDGET_H
