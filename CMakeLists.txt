project(webpagetraverser)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_AUTOMOC ON)

find_package(Qt4 REQUIRED)
find_package(QJSON REQUIRED)

include_directories(${QT_INCLUDES}
                    ${QJSON_INCLUDE_DIR}
                    ${CMAKE_CURRENT_BINARY_DIR}/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/src
                    ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(src)