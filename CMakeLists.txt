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
        abstract_controller.cpp
        app.cpp
        constants.h
        controller.cpp
        main.cpp
        menu.cpp
        model.cpp
        scores.cpp
        Tasks/abstract_task.cpp
        Tasks/pick_an_option_task.cpp
        Tasks/task_widget.cpp
        view.cpp
        )

target_link_libraries(myolingo
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

