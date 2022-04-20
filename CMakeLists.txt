cmake_minimum_required(VERSION 3.21)
project(myolingo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(myolingo
        main.cpp
        model.cpp
        view.cpp
        abstract_controller.cpp
        controller.cpp
        app.cpp
        Tasks/abstract_task.cpp
        Tasks/pick_an_option_task.cpp
        constants.h
        )

target_link_libraries(myolingo
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

