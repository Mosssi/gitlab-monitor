#ifndef GITLAB_DESKTOP_MONITOR_ICONTYPE_H
#define GITLAB_DESKTOP_MONITOR_ICONTYPE_H

#include <QtCore/QString>

enum class IconType {
    EMPTY,
    BACK,
    DONE,
    CLOSE,
    NEW,
    QUESTION_MARK,
};

QString getIconTypeString(const IconType &iconType);


#endif //GITLAB_DESKTOP_MONITOR_ICONTYPE_H
