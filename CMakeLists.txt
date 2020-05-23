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

add_executable( gitlab_desktop_monitor
        components/ApplicationWidget.cpp
        components/ApplicationWidget.h
        components/BodyWidget.cpp
        components/BodyWidget.h
        components/HeaderWidget.cpp
        components/HeaderWidget.h
        components/ProjectWidget.cpp
        components/ProjectWidget.h
        components/SystemTrayIcon.cpp
        components/SystemTrayIcon.h
        main.cpp
        models/BaseModel.cpp
        models/BaseModel.h
        models/Project.cpp
        models/Project.h
        models/User.cpp
        models/User.h
        network/NetworkManager.cpp
        network/NetworkManager.h
        network/ResponseStatus.h
        network/ServiceMediator.cpp
        network/ServiceMediator.h
        resources/resources.qrc
        utilities/Configuration.cpp
        utilities/Configuration.h
        utilities/DataStore.cpp
        utilities/DataStore.h
        utilities/GuiManager.cpp
        utilities/GuiManager.h
        components/ScrollArea.cpp
        components/ScrollArea.h
        components/ScrollBar.cpp
        components/ScrollBar.h
)

target_link_libraries(gitlab_desktop_monitor Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network)