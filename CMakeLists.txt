cmake_minimum_required(VERSION 3.5)

project(micromouse_qt_project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        maze.h
        maze.cpp
        cell.h
        cell.cpp
        mouse.h
        mouse.cpp
        algorythm.h
        algorythm.cpp
        righthandrule.h
        righthandrule.cpp
        lefthandrule.h
        lefthandrule.cpp
        directions.h
        directions.cpp
        controller.h
        controller.cpp
        sensor.h
        frontsensor.h
        frontsensor.cpp
        rightsensor.h
        rightsensor.cpp
        leftsensor.h
        leftsensor.cpp
        drive.h
        drive.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(micromouse_qt_project
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET micromouse_qt_project APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(micromouse_qt_project SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(micromouse_qt_project
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(micromouse_qt_project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(micromouse_qt_project PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS micromouse_qt_project
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(micromouse_qt_project)
endif()
