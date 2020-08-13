#include "IconType.h"

QString getIconTypeString(const IconType &iconType) {

    switch (iconType) {
        case IconType::EMPTY:
            return "";
        case IconType::BACK:
            return "a";
        case IconType::NEW:
            return "b";
        case IconType::DONE:
            return "c";
        case IconType::RELOAD:
            return "d";
        case IconType::QUESTION_MARK:
            return "e";
        case IconType::SETTINGS:
            return "f";
    }
}
