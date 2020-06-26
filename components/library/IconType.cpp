#include "IconType.h"

QString getIconTypeString(const IconType &iconType) {

    switch (iconType) {
        case IconType::EMPTY:
            return "";
        case IconType::BACK:
            return "a";
        case IconType::DONE:
            return "d";
        case IconType::CLOSE:
            return "b";
        case IconType::NEW:
            return "c";
        case IconType::QUESTION_MARK:
            return "f";
        case IconType::RELOAD:
            return "e";
    }
}
