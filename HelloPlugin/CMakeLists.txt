cmake_minimum_required(VERSION 3.10.0)
project(HelloPlugin VERSION 2)

set(HELLOPLUGIN_PLUGIN_TARGET Plugin-HelloPlugin)
set(PLUGIN_INTERFACE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/PluginInterface)


set(HELLOPLUGIN_PLUGIN_SOURCES
    #${PLUGIN_UI_SOURCE}
    #${CMAKE_CURRENT_LIST_DIR}/../common/CommonTypes.hpp
    ${CMAKE_CURRENT_LIST_DIR}/HelloPlugin.h
    ${CMAKE_CURRENT_LIST_DIR}/HelloPlugin.cpp
    ${QVPLUGIN_INTERFACE_HEADERS}
    #${QVGUIPLUGIN_INTERFACE_HEADERS}
    )

# 生成库 MODULE,在使用 dyld 的系统有效,如果不支持 dyld,则被当作 SHARED 对待。
add_library(${HELLOPLUGIN_PLUGIN_TARGET} MODULE
    #${CMAKE_CURRENT_LIST_DIR}/resx.qrc
    ${HELLOPLUGIN_PLUGIN_SOURCES}
    )

#添加头文件目录
target_include_directories(${HELLOPLUGIN_PLUGIN_TARGET} PRIVATE ${PLUGIN_INTERFACE_INCLUDE_DIR})

if(NOT QV_QT_LIBNAME)
    set(QV_QT_LIBNAME Qt5)
endif()

target_link_libraries(${HELLOPLUGIN_PLUGIN_TARGET}
    ${QV_QT_LIBNAME}::Core
    ${QV_QT_LIBNAME}::Gui
    ${QV_QT_LIBNAME}::Widgets)