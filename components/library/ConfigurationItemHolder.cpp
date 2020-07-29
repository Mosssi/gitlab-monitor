#include "ConfigurationItemHolder.h"

ConfigurationItemHolder::ConfigurationItemHolder(QWidget * parent) : HoverClickFrame(parent) {

    setFixedHeight(GuiManager::configurationItemHeight());
}
