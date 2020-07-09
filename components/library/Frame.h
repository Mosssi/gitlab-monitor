#ifndef GITLAB_DESKTOP_MONITOR_FRAME_H
#define GITLAB_DESKTOP_MONITOR_FRAME_H


#include <QtWidgets/QFrame>

class Frame : public QFrame {
public:
    explicit Frame(QWidget * parent = nullptr);
    void setBackgroundColor(const QString &backgroundColor);
    void setGeneralStyle(const QString &generalStyle);

private:
    void updateStyleSheet();

    QString backgroundColor = "";
    QString generalStyle = "";
};


#endif //GITLAB_DESKTOP_MONITOR_FRAME_H
