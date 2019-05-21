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

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

if (GLUT_FOUND)
    include_directories(${GLUT_INCLUDE_DIRS} )
endif()

if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS} )
endif()

target_link_libraries(GH_2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})
