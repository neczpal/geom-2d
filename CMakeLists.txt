cmake_minimum_required(VERSION 3.3)
project(Geom-2D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp
        src/Drawable.h
        src/Transformable.h
        src/Area.h
        src/Shape.h
        src/Line.h
        src/Line.cpp
        src/Point.h
        src/Point.cpp
        src/Segment.h
        src/Segment.cpp
        src/Circle.h
        src/Circle.cpp
        src/MyPolygon.h
        src/MyPolygon.cpp
        src/Triangle.h
        src/Triangle.cpp
        src/Rect.h
        src/Rect.cpp src/Drawable.cpp) #

add_executable(Geom-2D ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

if (GLUT_FOUND)
    include_directories(${GLUT_INCLUDE_DIRS} )
endif()

if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS} )
endif()

target_link_libraries(Geom-2D ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})
