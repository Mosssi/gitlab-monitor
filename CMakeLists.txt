cmake_minimum_required(VERSION 3.16)
project(gitlab_desktop_monitor)

set(CMAKE_PREFIX_PATH /opt/Qt5.9.1/5.9.1/gcc_64/lib/cmake)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

add_executable(
        gitlab_desktop_monitor
        resources/resources.qrc
        main.cpp
        components/ApplicationWidget.cpp
        components/ApplicationWidget.h
        components/SystemTrayIcon.cpp components/SystemTrayIcon.h network/NetworkManager.cpp network/NetworkManager.h models/User.cpp models/User.h utilities/Configuration.cpp utilities/Configuration.h network/ServiceMediator.cpp network/ServiceMediator.h network/ResponseStatus.h models/BaseModel.cpp models/BaseModel.h)

target_link_libraries(gitlab_desktop_monitor Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network)