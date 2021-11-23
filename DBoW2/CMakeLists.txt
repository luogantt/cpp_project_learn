cmake_minimum_required(VERSION 3.0)
project(DBoW2)
include(ExternalProject)

#有时希望在编译代码时只编译一些指定的源码，可以使用cmake的option命令
#https://blog.csdn.net/whahu1989/article/details/82078563#t8
option(BUILD_DBoW2   "Build DBoW2"            ON)
option(BUILD_Demo    "Build demo application" ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


#头文件位置
set(HDRS
  include/DBoW2/BowVector.h           include/DBoW2/FBrief.h
  include/DBoW2/QueryResults.h        include/DBoW2/TemplatedDatabase.h   include/DBoW2/FORB.h
  include/DBoW2/DBoW2.h               include/DBoW2/FClass.h              include/DBoW2/FeatureVector.h
  include/DBoW2/ScoringObject.h       include/DBoW2/TemplatedVocabulary.h)
#核心代码位置
set(SRCS 
  src/BowVector.cpp     src/FBrief.cpp        src/FORB.cpp
  src/FeatureVector.cpp src/QueryResults.cpp  src/ScoringObject.cpp)

message("hello")
message(${CMAKE_CURRENT_BINARY_DIR})


set(DEPENDENCY_DIR ${CMAKE_CURRENT_BINARY_DIR}/dependencies)

message(${DEPENDENCY_DIR})
set(DEPENDENCY_INSTALL_DIR ${DEPENDENCY_DIR}/install)

find_package(OpenCV REQUIRED)

message("-------------------opencv--------------------------")
message(${OpenCV_INCLUDE_DIRS})

#include_directories。该命令是用来向工程添加多个指定头文件的搜索路径，路径之间用空格分隔
include_directories(${OpenCV_INCLUDE_DIRS})

if(BUILD_DBoW2)
  ## 动态库
  set(LIB_SHARED "SHARED")
  if(WIN32)
  #静态库
    set(LIB_SHARED "STATIC")
  endif(WIN32)
  # add_library: 生成动态库或静态库(第1个参数指定库的名字；第2个参数决定是动态还是静态，如果没有就默认静态；第3个参数指定生成库的源文件)
  # PROJECT_NAME cmake 内置的关键字，就是工程名称 
  add_library(${PROJECT_NAME} ${LIB_SHARED} ${SRCS})

  #target_include_directories（）的影响范围可以自定义。如加关键子PRIVATE或这PUBLIC。
  #一般引用库路径使用这个命令，作为外部依赖项引入进来，target是自己项目生成的lib。
  #(CMake的几种Include)https://blog.csdn.net/fb_help/article/details/81382746
  target_include_directories(${PROJECT_NAME} PUBLIC include/DBoW2/ include/)
  #target_link_libraries: 把目标文件与库文件进行链接
  target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
　#set_target_properties: 设置最终生成的库的名称，还有其它功能，如设置库的版本号等等
  set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
  message("---编译了BUILD_DBoW2的动态库和静态库---")
endif(BUILD_DBoW2)

if(BUILD_Demo)
  message("---编译了demo---")
  add_executable(demo demo/demo.cpp)
  target_link_libraries(demo ${PROJECT_NAME} ${OpenCV_LIBS})
  set_target_properties(demo PROPERTIES CXX_STANDARD 11)
  file(COPY demo/images DESTINATION ${CMAKE_BINARY_DIR}/)
endif(BUILD_Demo)

configure_file(src/DBoW2.cmake.in
  "${PROJECT_BINARY_DIR}/DBoW2Config.cmake" @ONLY)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
if(BUILD_DBoW2)
  install(DIRECTORY include/DBoW2 DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
endif()
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/DBoW2Config.cmake"
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME})
install(FILES "${PROJECT_BINARY_DIR}/DBoW2Config.cmake" 
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake/DBoW2/)
install(DIRECTORY ${DEPENDENCY_INSTALL_DIR}/ DESTINATION ${CMAKE_INSTALL_PREFIX} OPTIONAL)

