cmake_minimum_required(VERSION 3.25)
project(2D_Engine)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

add_executable(2D_Engine
        main.cpp
        Circle.cpp
        CircleEventListener.cpp
        Engine.cpp
        Line.cpp
        LineEventListener.cpp
        Menu.cpp
        Player.cpp
        Rectangle.cpp
        RectangleEventListener.cpp
)

target_link_libraries(2D_Engine sfml-graphics)
