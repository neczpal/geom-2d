cmake_minimum_required(VERSION 3.3)
project(GH_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        Drawable.h
        Transformable.h
        Area.h
        Shape.h
        Line.h
        Line.cpp
        Point.h
        Point.cpp
        Segment.h
        Segment.cpp
        Circle.h
        Circle.cpp
        MyPolygon.h
        MyPolygon.cpp
        Triangle.h
        Triangle.cpp
        Rect.h
        Rect.cpp Drawable.cpp) #

add_executable(GH_2 ${SOURCE_FILES})

target_link_libraries(GH_2 libopengl32.a libglu32.a libfreeglut.a)
