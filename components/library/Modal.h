#ifndef GITLAB_DESKTOP_MONITOR_MODAL_H
#define GITLAB_DESKTOP_MONITOR_MODAL_H


#include <QtWidgets/QVBoxLayout>

#include "Frame.h"
#include "Label.h"

class Modal : public Frame {
public:
    explicit Modal(const QString &title, QWidget * parent);

protected:
    QVBoxLayout * mainLayout = nullptr;

private:
    void setupUi();
    void updateStyleSheet() override;

    QString title;
    Frame * mainWidget = nullptr;
    Frame * titleFrame = nullptr;
    Label * titleLabel = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_MODAL_H
