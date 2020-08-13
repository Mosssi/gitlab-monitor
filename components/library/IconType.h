#ifndef GITLAB_DESKTOP_MONITOR_ICONTYPE_H
#define GITLAB_DESKTOP_MONITOR_ICONTYPE_H

#include <QtCore/QString>

enum class IconType {
    EMPTY,
    BACK,
    NEW,
    DONE,
    RELOAD,
    QUESTION_MARK,
    SETTINGS,
};

QString getIconTypeString(const IconType &iconType);


#endif //GITLAB_DESKTOP_MONITOR_ICONTYPE_H
