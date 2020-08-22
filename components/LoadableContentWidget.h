#ifndef GITLAB_DESKTOP_MONITOR_LOADABLECONTENTWIDGET_H
#define GITLAB_DESKTOP_MONITOR_LOADABLECONTENTWIDGET_H

#include <QtWidgets/QFrame>
#include <QtWidgets/QStackedWidget>

enum class LoadableContentState {
    LOADING,
    CONTENT,
    ERROR,
};

class LoadableContentWidget : public QStackedWidget {
public:
    explicit LoadableContentWidget(QLayout * contentsLayout, QWidget * parent = nullptr);
    void setState(LoadableContentState state);

private:
    QFrame * loadingStateWidget = nullptr;
    QFrame * contentStateWidget = nullptr;
    QFrame * errorStateWidget = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_LOADABLECONTENTWIDGET_H
