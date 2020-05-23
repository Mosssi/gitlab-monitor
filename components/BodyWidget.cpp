#include "BodyWidget.h"

#include <QtWidgets/QScrollArea>
#include <QDebug>

#include "../models/Project.h"
#include "../utilities/DataStore.h"
#include "ProjectWidget.h"

BodyWidget::BodyWidget(QWidget * parent) : QFrame(parent) {

    setupUi();

    connect(&DataStore::getInstance(), &DataStore::projectsReceived, this, &BodyWidget::updateUi);
}

void BodyWidget::setupUi() {

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    auto * scrollWidget = new QWidget();
    scrollLayout = new QVBoxLayout(scrollWidget);
    scrollLayout->setContentsMargins(0, 0, 0, 0);
    scrollLayout->setSpacing(0);
    auto * scrollArea = new QScrollArea();
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    mainLayout->addWidget(scrollArea);
}

void BodyWidget::updateUi() {

    const QList<Project> projects = DataStore::getInstance().getProjects();

    for (int i = 0; i < projects.length(); i++) {
        scrollLayout->addWidget(new ProjectWidget(projects.at(i).id, i % 2));
    }
}
