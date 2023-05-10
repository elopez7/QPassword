cmake_minimum_required(VERSION 3.23)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Qml Gui)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)

set(QML_IMPORT_PATH ${QT_QML_OUTPUT_DIRECTORY}
    CACHE STRING "Qt Creator password component import path"
    FORCE
)

qt_add_library(passwordModule STATIC)
qt6_add_qml_module(passwordModule
    URI "passwordModule"
    AUTO_RESOURCE_PREFIX
    VERSION 1.0
    PLUGIN_TARGET passwordModulePlugin
    IMPORT_PATH ${QT_QML_OUTPUT_DIRECTORY}
    SOURCES
        passwordgenerator.h
        passwordgenerator.cpp
)

target_include_directories(passwordModule
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(passwordModule
    PRIVATE Qt6::Core
    PRIVATE Qt6::Gui
)
