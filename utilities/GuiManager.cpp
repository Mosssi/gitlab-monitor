#include "GuiManager.h"

QFont GuiManager::applicationFont() {
    return QFont("Ubuntu", normalFontSize());
}

QString GuiManager::grayColor(int lightness) {

    if (lightness < 0 || lightness > 10) {
        return "#000000";
    }

    int colorChannel = (int) (lightness * 25.5);
    return QString("#%1%1%1").arg(colorChannel, 2, 16, QChar('0'));
}
