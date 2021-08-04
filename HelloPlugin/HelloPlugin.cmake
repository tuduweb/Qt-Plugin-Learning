add_definitions(-DNODE_EDITOR_SHARED -DNODE_EDITOR_EXPORTS)
if(HELLOPLUGIN_PROVIDER STREQUAL "module")
    set(HELLOPLUGIN_DIR ${CMAKE_SOURCE_DIR})
    set(HELLOPLUGIN_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/HelloPlugin.cpp
    )

    set(HELLOPLUGIN_HEADERS
        ${QVPLUGIN_INTERFACE_HEADERS}
        ${CMAKE_CURRENT_LIST_DIR}/HelloPlugin.h
    )

    set(HELLOPLUGIN_LIBRARY obc_helloPlugin)

    add_library(${HELLOPLUGIN_LIBRARY} STATIC
        ${HELLOPLUGIN_HEADERS}
        ${HELLOPLUGIN_SOURCES}
    )

    target_link_libraries(${HELLOPLUGIN_LIBRARY} PUBLIC
        ${QV_QT_LIBNAME}::Widgets
        ${QV_QT_LIBNAME}::Core
        ${QV_QT_LIBNAME}::Gui
    )

else()
    message("HelloPlugin not in")
endif()