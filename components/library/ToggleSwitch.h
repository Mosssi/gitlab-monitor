#ifndef GITLAB_DESKTOP_MONITOR_TOGGLESWITCH_H
#define GITLAB_DESKTOP_MONITOR_TOGGLESWITCH_H

#include <QtWidgets/QWidget>

#include "StyledWidget.h"

class ToggleSwitch : public QWidget, private StyledWidget {
Q_OBJECT
Q_PROPERTY(double switchPosition READ getSwitchPosition WRITE setSwitchPosition)
Q_PROPERTY(double pressureValue READ getPressureValue WRITE setPressureValue)
public:
    explicit ToggleSwitch(QWidget * parent = nullptr);
    void setChecked(bool checked);
    [[nodiscard]] bool getChecked() const;
    void setSwitchPosition(double switchPosition);
    [[nodiscard]] double getSwitchPosition() const { return switchPosition; }
    void setPressureValue(double pressureValue);
    [[nodiscard]] double getPressureValue() const { return pressureValue; }
    void toggleState();

signals:
    void toggled(bool checked);

private:
    void paintEvent(QPaintEvent * event) override;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;
    void updateStyleSheet() override;

    bool checked = false;
    double switchPosition = 0;
    double pressureValue = 0;
};


#endif //GITLAB_DESKTOP_MONITOR_TOGGLESWITCH_H
