cmake_minimum_required(VERSION 3.26)
project(2D_Engine)

set(CMAKE_CXX_STANDARD 17)

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
        Player.cpp
        Player.h
        BitmapRectangle.cpp
        BitmapRectangle.h
        BitmapRectangleEventListener.cpp
        BitmapRectangleEventListener.h
        Collision.cpp
        Collision.h
)

if (WIN32)
    include(FetchContent)
    set(BUILD_SHARED_LIBS OFF)
    FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
    FETCHCONTENT_MAKEAVAILABLE(SFML)
endif (WIN32)

if (UNIX)
    find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
    include_directories(${SFML_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
endif (UNIX)

