project(webpagetraverser)

cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5WebKit REQUIRED)
find_package(Qt5WebKitWidgets REQUIRED)

include_directories(${Qt5Core_INCLUDE_DIRS}
                    ${Qt5Widgets_INCLUDE_DIRS}
                    ${Qt5WebKit_INCLUDE_DIRS}
                    ${Qt5WebKitWidgets_INCLUDE_DIRS})

add_subdirectory(src)
