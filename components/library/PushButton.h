#ifndef GITLAB_DESKTOP_MONITOR_PUSHBUTTON_H
#define GITLAB_DESKTOP_MONITOR_PUSHBUTTON_H


#include <QtWidgets/QWidget>
#include <QTimer>

#include "IconType.h"

class PushButton : public QWidget {
Q_OBJECT
public:
    explicit PushButton(const IconType &icon, bool confirmRequired = false);
    ~PushButton() override;

signals:
    void clicked();

private:
    void paintEvent(QPaintEvent * event) override;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;
    void enterEvent(QEvent * event) override;
    void leaveEvent(QEvent * event) override;
    void keyPressEvent(QKeyEvent * event) override;
    void keyReleaseEvent(QKeyEvent * event) override;

    IconType iconType = IconType::EMPTY;
    const bool confirmRequired = false;

    bool hovered = false;
    bool pressed = false;
    bool confirming = false;

    QTimer * confirmTimer = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_PUSHBUTTON_H
