#include "BaseModel.h"

BaseModel::BaseModel(const QJsonObject &jsonObject) {

    empty = false;
    id = jsonObject.value("id").toInt();
}
