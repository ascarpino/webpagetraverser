project(WebPageTraverser)

cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

# Set version
set(WebPageTraverser_VERSION_MAJOR 1)
set(WebPageTraverser_VERSION_MINOR 4)
set(WebPageTraverser_VERSION_STRING "${WebPageTraverser_VERSION_MAJOR}.${WebPageTraverser_VERSION_MINOR}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5WebKit REQUIRED)
find_package(Qt5WebKitWidgets REQUIRED)

add_subdirectory(src)
