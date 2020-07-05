#ifndef GITLAB_DESKTOP_MONITOR_CONTEXTMENUBUTTON_H
#define GITLAB_DESKTOP_MONITOR_CONTEXTMENUBUTTON_H


#include "library/Label.h"

class ContextMenuButton : public Label {
Q_OBJECT
public:
    explicit ContextMenuButton(const QString &text, QWidget * parent = nullptr);

signals:
    void clicked();

private:
    void mouseReleaseEvent(QMouseEvent *) override;
    void enterEvent(QEvent * event) override;
    void leaveEvent(QEvent * event) override;

    QString text;
};


#endif //GITLAB_DESKTOP_MONITOR_CONTEXTMENUBUTTON_H
