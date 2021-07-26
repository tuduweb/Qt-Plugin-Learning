cmake_minimum_required(VERSION 3.10.0)
project(PluginInterface VERSION 2)

#include(GNUInstallDirs)

#[[
add_library(<name> [STATIC | SHARED | MODULE]
            [EXCLUDE_FROM_ALL]
            source1 [source2 ...])
<name> ：库的名字，直接写名字即可，不要写lib，会自动加上前缀。
]]

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})


file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
message(STATUS "hello world ${HEADERS}")
message(STATUS "hi ${PROJECT_NAME}")

#variable
SET(USER_KEY "Hello World")
MESSAGE( STATUS "this var key = ${USER_KEY}.")


set(PLUGIN_INTERFACE_HEADERS
    #${QVPLUGIN_HTTP_TO_SOCKS_FILES}
    #${CMAKE_CURRENT_LIST_DIR}/PluginBase.hpp
    ${CMAKE_CURRENT_LIST_DIR}/PluginInterface.h)
set(PLUGIN_INTERFACE_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR})

message( STATUS "PLUGIN_INTERFACE_HEADERS = ${PLUGIN_INTERFACE_HEADERS}")
message( STATUS "PLUGIN_INTERFACE_INCLUDE_DIR = ${PLUGIN_INTERFACE_INCLUDE_DIR}")

if(NOT QV_QT_LIBNAME)
    set(QV_QT_LIBNAME Qt5)
endif()

# target_link_libraries(${PLUGIN_INTERFACE_HEADERS}
#     ${QV_QT_LIBNAME}::Core
#     ${QV_QT_LIBNAME}::Gui
#     ${QV_QT_LIBNAME}::Widgets)