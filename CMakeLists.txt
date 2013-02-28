project(webpagetraverser)

cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt4 REQUIRED)
find_package(QJSON REQUIRED)

include_directories(${QT_INCLUDES}
                    ${QJSON_INCLUDE_DIR})

add_subdirectory(src)
