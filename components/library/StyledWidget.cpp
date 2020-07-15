#include "StyledWidget.h"

#include "../../utilities/Configuration.h"

StyledWidget::StyledWidget() {

    connection = QObject::connect(
            &Configuration::getInstance(), &Configuration::themeChanged,
            [this]() { updateStyleSheet(); }
    );
}

StyledWidget::~StyledWidget() {
    QObject::disconnect(connection);
}
