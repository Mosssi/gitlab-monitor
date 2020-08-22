#ifndef GITLAB_DESKTOP_MONITOR_LINEEDIT_H
#define GITLAB_DESKTOP_MONITOR_LINEEDIT_H

#include <QtWidgets/QLineEdit>

#include "StyledWidget.h"

class LineEdit : public QLineEdit, StyledWidget {
public:
    explicit LineEdit(QWidget * parent = nullptr);
    void setHasError(bool hasError);

private:
    void updateStyleSheet() override;

    bool hasError = false;
};


#endif //GITLAB_DESKTOP_MONITOR_LINEEDIT_H
