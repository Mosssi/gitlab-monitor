#ifndef GITLAB_DESKTOP_MONITOR_LABEL_H
#define GITLAB_DESKTOP_MONITOR_LABEL_H


#include <QtWidgets/QLabel>

#include "../../utilities/GuiManager.h"

class Label : public QLabel {
public:
    explicit Label(const QString &text = "", QWidget * parent = nullptr);
    void setFontSize(int fontSize);
    void setBold(bool bold);
    void setColor(const QString &color);
    void setGeneralStyle(const QString &generalStyle);

private:
    void updateStyleSheet();
    void setStyleSheet(const QString &styleSheet);

    int fontSize = GuiManager::normalFontSize();
    bool bold = false;
    QString color = GuiManager::darkGrayColor();
    QString generalStyle = "";
};


#endif //GITLAB_DESKTOP_MONITOR_LABEL_H
