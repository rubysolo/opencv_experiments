cmake_minimum_required(VERSION 2.8)
set(project_name dewarp)
project( ${project_name} )

set(tmp ${BUILD_SHARED_LIBS})
set(BUILD_SHARED_LIBS ON)
FIND_PACKAGE( OpenCV REQUIRED )
set(BUILD_SHARED_LIBS ${tmp})

add_executable(${project_name} dewarp.cpp)

target_link_libraries( ${project_name} ${OpenCV_LIBS} )
