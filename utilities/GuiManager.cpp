#include "GuiManager.h"

QFont GuiManager::applicationFont() {
    return QFont("Helvetica", normalFontSize());
}

QString GuiManager::grayColor(int lightness) {

    const int levels = 20;

    if (lightness < 0 || lightness > 20) {
        return "#000000";
    }

    const int colorChannel = (int) (lightness * 255 / levels);
    return QString("#%1%1%1").arg(colorChannel, 2, 16, QChar('0'));
}
