#ifndef GITLAB_DESKTOP_MONITOR_PUSHBUTTON_H
#define GITLAB_DESKTOP_MONITOR_PUSHBUTTON_H

#include <QTimer>
#include <QtCore/QPropertyAnimation>
#include <QtWidgets/QWidget>

#include "IconType.h"

class PushButton : public QWidget {
Q_OBJECT
Q_PROPERTY(double confirmingValue READ getConfirmingValue WRITE setConfirmingValue)
public:
    explicit PushButton(const IconType &icon, bool confirmRequired = false);
    ~PushButton() override = default;
    void setConfirmingValue(double value) { confirmingValue = value; update(); }
    [[nodiscard]] double getConfirmingValue() const { return confirmingValue; }
    void setLoading(bool loading) { this->loading = loading; update(); }
    [[nodiscard]] bool getLoading() const { return loading; }

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
    double confirmingValue = 0;
    bool loading = false;
    int arcPosition = 0;

    QTimer * confirmTimer = nullptr;
    QTimer * loadingTimer = nullptr;

    QPropertyAnimation * confirmAnimation = nullptr;
    QPropertyAnimation * unConfirmAnimation = nullptr;
};


#endif //GITLAB_DESKTOP_MONITOR_PUSHBUTTON_H
