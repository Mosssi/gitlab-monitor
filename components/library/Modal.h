#ifndef GITLAB_DESKTOP_MONITOR_MODAL_H
#define GITLAB_DESKTOP_MONITOR_MODAL_H


#include <QtWidgets/QVBoxLayout>

#include "Frame.h"
#include "Label.h"

class Modal : public Frame {
Q_OBJECT
public:
    explicit Modal(const QString &title, QWidget * parent);

signals:
    void closed();

protected:
    QVBoxLayout * mainLayout = nullptr;

private:
    void setupUi();
    void updateStyleSheet() override;
    void mouseReleaseEvent(QMouseEvent * event) override;

    QString title;
    Frame * mainWidget = nullptr;
    Frame * titleFrame = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_MODAL_H
