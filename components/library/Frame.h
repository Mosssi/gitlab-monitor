#ifndef GITLAB_DESKTOP_MONITOR_FRAME_H
#define GITLAB_DESKTOP_MONITOR_FRAME_H

#include <QtWidgets/QFrame>

#include "StyledWidget.h"

class Frame : public QFrame, private StyledWidget {
Q_OBJECT
public:
    explicit Frame(QWidget * parent = nullptr);
    void setBackgroundColor(const QString &backgroundColor);
    void setGeneralStyle(const QString &generalStyle);

signals:
    void resized();

private:
    void resizeEvent(QResizeEvent * event) override;
    void updateStyleSheet() override;

    QString backgroundColor = "";
    QString generalStyle = "";
};


#endif //GITLAB_DESKTOP_MONITOR_FRAME_H
