#ifndef GITLAB_DESKTOP_MONITOR_LABEL_H
#define GITLAB_DESKTOP_MONITOR_LABEL_H


#include <QtWidgets/QLabel>

#include "StyledWidget.h"

class Label : public QLabel, private StyledWidget {
public:
    explicit Label(const QString &text = "", QWidget * parent = nullptr);
    [[maybe_unused]] void setFontSize(int fontSize);
    [[maybe_unused]] void setBold(bool bold);
    [[maybe_unused]] void setColor(const QString &color);
    [[maybe_unused]] void setBackgroundColor(const QString &backgroundColor);
    [[maybe_unused]] void setGeneralStyle(const QString &generalStyle);

protected:
    void resizeEvent(QResizeEvent * event) override;

private:
    void updateStyleSheet() override;
    void setStyleSheet(const QString &styleSheet);
    void elideText(int availableWidth);

    int fontSize;
    bool bold = false;
    QString color = "";
    QString backgroundColor = "none";
    QString generalStyle = "";
};


#endif //GITLAB_DESKTOP_MONITOR_LABEL_H
