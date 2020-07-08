#ifndef GITLAB_DESKTOP_MONITOR_HOVERCLICKFRAME_H
#define GITLAB_DESKTOP_MONITOR_HOVERCLICKFRAME_H


#include "Frame.h"
#include "../../utilities/GuiManager.h"

class HoverClickFrame : public Frame {
Q_OBJECT
public:
    explicit HoverClickFrame(QWidget * parent, bool pressEnabled = true);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;
    void enterEvent(QEvent * event) override;
    void leaveEvent(QEvent * event) override;

private:
    const QString normalColor = GuiManager::whiteColor();
    const QString hoverColor = GuiManager::lighterColor();
    const QString pressColor = GuiManager::lightColor();

    bool pressEnabled;
};


#endif //GITLAB_DESKTOP_MONITOR_HOVERCLICKFRAME_H
