#include "IconType.h"

QString getIconTypeString(const IconType &iconType) {

    switch (iconType) {
        case IconType::BACK:
            return "a";
        case IconType::DONE:
            return "j";
        case IconType::CLOSE:
            return "h";
        case IconType::NEW:
            return "i";
    }
}
