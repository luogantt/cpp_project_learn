cmake_minimum_required(VERSION 2.8)
project( camer )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( camer main.cpp )
target_link_libraries( camer ${OpenCV_LIBS} )

