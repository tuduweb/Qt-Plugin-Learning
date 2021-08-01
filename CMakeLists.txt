# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.10.1)

project(obc)


# 包含子项目。
#add_subdirectory ("CMakeProject")
#add_subdirectory("PluginSystem")

#??
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)
# IF (WIN32)
# set(Qt5_DIR  "C:/Qt/5.15.0/msvc2019_64/lib/cmake/Qt5")
# ELSEIF (APPLE)
# set(Qt5_DIR  "/opt/homebrew/opt/qt5/lib/cmake/qt5")
# ENDIF ()
#?????????

set(QV_QT_LIBNAME Qt5)
set(QV_QT_MAJOR_VERSION 5)
set(QV_QT_MINOR_VERSION 11)

find_package(${QV_QT_LIBNAME} ${QV_QT_MAJOR_VERSION}.${QV_QT_MINOR_VERSION} COMPONENTS Core Network REQUIRED)
list(APPEND OBC_QT_LIBS ${QV_QT_LIBNAME}::Core ${QV_QT_LIBNAME}::Network)

find_package(${QV_QT_LIBNAME} ${QV_QT_MAJOR_VERSION}.${QV_QT_MINOR_VERSION} COMPONENTS Widgets Svg Gui REQUIRED)
list(APPEND OBC_QT_LIBS
    ${QV_QT_LIBNAME}::Widgets
    ${QV_QT_LIBNAME}::Svg
    ${QV_QT_LIBNAME}::Gui)
set(_QV2RAY_HAS_GUI_INTERNAL_ ON)

#在代码中加入 OBC_NO...宏定义
add_definitions(-DOBC_NO_SINGLEAPPLICATON)

message("QT_LIBS ${OBC_QT_LIBS}")

#baselib sources
include(PluginInterface/PluginInterface.cmake)

add_library(obc_baselib STATIC
    ${PLUGIN_INTERFACE_HEADERS}
)

target_link_libraries(obc_baselib
    ${OBC_QT_LIBS}
)

target_include_directories(obc_baselib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(OBC_FULL_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/PluginSystem/main.cpp
)

set(GUI_TYPE WIN32)
#加上这个WIN32 就没有了控制台输出..#WIN32 So the console window does not open on Windows
#加上后找的是WinMain qt库里是默认有这个玩意的 所以不会出现找不到库的情况..?
add_executable(obc ${GUI_TYPE} ${OBC_FULL_SOURCES})

## 在win32环境下 加上调试框
#set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")#自己加的 打开调试框

target_include_directories(obc PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/PluginSystem
)

target_link_libraries(obc PUBLIC
    obc_baselib
)