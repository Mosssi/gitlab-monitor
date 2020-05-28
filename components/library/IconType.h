#ifndef GITLAB_DESKTOP_MONITOR_ICONTYPE_H
#define GITLAB_DESKTOP_MONITOR_ICONTYPE_H

#include <QtCore/QString>

enum class IconType {
    BACK,
    DONE,
    CLOSE,
    NEW,
};

QString getIconTypeString(const IconType &iconType);


#endif //GITLAB_DESKTOP_MONITOR_ICONTYPE_H
