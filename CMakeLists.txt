cmake_minimum_required(VERSION 3.3)
project(Geom-2D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(LIB_SOURCE_FILES
        lib/inc/Drawable.h
        lib/inc/Transformable.h
        lib/inc/Area.h
        lib/inc/Shape.h
        lib/inc/Line.h
        lib/src/Line.cpp
        lib/inc/Point.h
        lib/src/Point.cpp
        lib/inc/Segment.h
        lib/src/Segment.cpp
        lib/inc/Circle.h
        lib/src/Circle.cpp
        lib/inc/MyPolygon.h
        lib/src/MyPolygon.cpp
        lib/inc/Triangle.h
        lib/src/Triangle.cpp
        lib/inc/Rect.h
        lib/src/Rect.cpp lib/src/Drawable.cpp)

set (TESTPROGRAM_SOURCE_FILES
        test/main.cpp)

add_library(Geom-2D ${LIB_SOURCE_FILES})

add_executable(Geom-2D-TestProgram ${TESTPROGRAM_SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

if (GLUT_FOUND)
    include_directories(${GLUT_INCLUDE_DIRS} )
endif()

if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS} )
endif()

target_link_libraries(Geom-2D-TestProgram Geom-2D ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})
