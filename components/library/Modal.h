#ifndef GITLAB_DESKTOP_MONITOR_MODAL_H
#define GITLAB_DESKTOP_MONITOR_MODAL_H


#include <QtWidgets/QVBoxLayout>

#include "Frame.h"

class Modal : public Frame {
public:
    explicit Modal(const QString &title, QWidget * parent);

protected:
    QVBoxLayout * mainLayout = nullptr;

private:
    void setupUi();

    QString title;
};


#endif //GITLAB_DESKTOP_MONITOR_MODAL_H
