#include "LoadableContentWidget.h"

#include <QtWidgets/QHBoxLayout>

#include "library/Label.h"
#include "library/LoadingWidget.h"
#include "library/ScrollArea.h"

LoadableContentWidget::LoadableContentWidget(QLayout * contentsLayout, QWidget * parent) : QStackedWidget(parent) {

    addWidget(contentStateWidget = new ScrollArea(contentsLayout));

    auto * loadingLayout = new QVBoxLayout(loadingStateWidget = new QFrame());
    loadingLayout->setAlignment(Qt::AlignCenter);
    loadingLayout->addWidget(new LoadingWidget(), 0, Qt::AlignCenter);
    addWidget(loadingStateWidget);

    auto * errorLayout = new QVBoxLayout(errorStateWidget = new QFrame());
    errorLayout->setAlignment(Qt::AlignCenter);
    errorLayout->addWidget(new Label("Error in fetching data ..."), 0, Qt::AlignCenter);
    addWidget(errorStateWidget);

    setState(LoadableContentState::CONTENT);
}

void LoadableContentWidget::setState(LoadableContentState state) {

    switch (state) {
        case LoadableContentState::LOADING:
            setCurrentWidget(loadingStateWidget);
            break;
        case LoadableContentState::CONTENT:
            setCurrentWidget(contentStateWidget);
            break;
        case LoadableContentState::ERROR:
            setCurrentWidget(errorStateWidget);
            break;
    }
}
