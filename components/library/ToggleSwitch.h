#ifndef GITLAB_DESKTOP_MONITOR_TOGGLESWITCH_H
#define GITLAB_DESKTOP_MONITOR_TOGGLESWITCH_H

#include <QtWidgets/QWidget>

#include "StyledWidget.h"

class ToggleSwitch : public QWidget, private StyledWidget {
Q_OBJECT
Q_PROPERTY(double switchPosition READ getSwitchPosition WRITE setSwitchPosition)
public:
    explicit ToggleSwitch(bool checked = false, QWidget * parent = nullptr);
    void setChecked(bool checked);
    [[nodiscard]] bool isChecked() const;
    void setSwitchPosition(double switchPosition);
    [[nodiscard]] double getSwitchPosition() const { return switchPosition; }

signals:
    void clicked();

private:
    void paintEvent(QPaintEvent * event) override;
    void updateStyleSheet() override;
    void mouseReleaseEvent(QMouseEvent * event) override;

    bool checked = false;
    double switchPosition = 0;
};


#endif //GITLAB_DESKTOP_MONITOR_TOGGLESWITCH_H
