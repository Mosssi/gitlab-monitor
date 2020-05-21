#ifndef GITLAB_DESKTOP_MONITOR_NETWORKRESPONSE_H
#define GITLAB_DESKTOP_MONITOR_NETWORKRESPONSE_H

#include "ResponseStatus.h"

template <class T>
class NetworkResponse {
public:
    [[nodiscard]] static NetworkResponse<T> ok(T entity);
    [[nodiscard]] static NetworkResponse<T> error();

    T entity;
    ResponseStatus status;
};

template<class T>
NetworkResponse<T> NetworkResponse<T>::ok(T entity) {

    NetworkResponse<T> response;
    response.status = ResponseStatus::SUCCESSFUL;
    response.entity = entity;
    return NetworkResponse(response);
}

template<class T>
NetworkResponse<T> NetworkResponse<T>::error() {

    NetworkResponse<T> response;
    response.status = ResponseStatus::UNSUCCESSFUL;
    return NetworkResponse(response);
}


#endif //GITLAB_DESKTOP_MONITOR_NETWORKRESPONSE_H
