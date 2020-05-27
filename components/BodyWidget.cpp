#include "BodyWidget.h"

#include "../models/Project.h"
#include "../utilities/DataStore.h"
#include "ProjectWidget.h"
#include "library/ScrollArea.h"

BodyWidget::BodyWidget(QWidget * parent) : QFrame(parent) {

    setupUi();
    setStyleSheet("background-color: #ffffff;");

    connect(&DataStore::getInstance(), &DataStore::projectsReceived, this, &BodyWidget::updateUi);
}

void BodyWidget::setupUi() {

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    scrollLayout = new QVBoxLayout();
    scrollLayout->setContentsMargins(0, 0, 0, 0);
    scrollLayout->setSpacing(0);
    scrollLayout->setAlignment(Qt::AlignTop);

    mainLayout->addWidget(new ScrollArea(scrollLayout));
}

void BodyWidget::updateUi() {

    const QList<Project> projects = DataStore::getInstance().getProjects();

    for (int i = 0; i < projects.length(); i++) {
        scrollLayout->addWidget(new ProjectWidget(projects.at(i).id, i % 2));
    }
}
