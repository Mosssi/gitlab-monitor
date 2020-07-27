//#include "KeyStore.h"
//
//#include "LogService.h"
//
//void KeyStore::storeKey(const QString &name, const QString &value) {
//    const char * payload = value.toStdString().c_str();
//    key_serial_t key = add_key("user", name.toStdString().c_str(), payload, sizeof(payload), KEY_SPEC_SESSION_KEYRING);
//    if (key == -1) {
//        qDebug() << "error";
//    }
//}
//
//QString KeyStore::getKey(const QString &name) {
////    request_key("user", name.toStdString().c_str(), )
//}
