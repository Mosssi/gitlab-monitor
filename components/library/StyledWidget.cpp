#include "StyledWidget.h"
#include "../../utilities/Configuration.h"

StyledWidget::StyledWidget() {

    QObject::connect(
            &Configuration::getInstance(), &Configuration::darkThemeChanged,
            [this]() { updateStyleSheet(); }
    );
}
