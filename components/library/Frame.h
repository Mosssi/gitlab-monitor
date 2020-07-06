#ifndef GITLAB_DESKTOP_MONITOR_FRAME_H
#define GITLAB_DESKTOP_MONITOR_FRAME_H


#include <QtWidgets/QFrame>

class Frame : public QFrame {
public:
    explicit Frame(QWidget * parent = nullptr);
    void setBackgroundColor(const QString &color);
};


#endif //GITLAB_DESKTOP_MONITOR_FRAME_H
