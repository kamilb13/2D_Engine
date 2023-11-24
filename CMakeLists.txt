cmake_minimum_required(VERSION 3.26)
project(2D_Engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(2D_Engine
        Engine.h
        main.cpp
        Engine.cpp
        Rectangle.cpp
        Rectangle.h
        Line.cpp
        Line.h
        RectangleEventListener.cpp
        RectangleEventListener.h
        Circle.cpp
        Circle.h
        LineEventListener.cpp
        LineEventListener.h
        Menu.cpp
        Menu.h
        CircleEventListener.cpp
        CircleEventListener.h
        Enemy.cpp
        Enemy.h
        Bullet.cpp
        Bullet.h
)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
