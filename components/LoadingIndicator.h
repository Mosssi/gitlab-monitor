#ifndef GITLAB_DESKTOP_MONITOR_LOADINGINDICATOR_H
#define GITLAB_DESKTOP_MONITOR_LOADINGINDICATOR_H


#include <QFrame>

class LoadingIndicator : public QFrame {
public:
    static LoadingIndicator &getInstance();
    void startLoading();
    void stopLoading();

private:
    explicit LoadingIndicator(QWidget * parent = nullptr);
    void setupUi();
};


#endif //GITLAB_DESKTOP_MONITOR_LOADINGINDICATOR_H
