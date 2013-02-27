set(webpagetraverser_SRCS
    main.cpp
    webelement.cpp
    pagetraverser.cpp)

add_executable(webpagetraverser ${webpagetraverser_SRCS})

target_link_libraries(webpagetraverser ${QT_QTCORE_LIBRARY}
                                       ${QT_QTGUI_LIBRARY}
                                       ${QT_QTWEBKIT_LIBRARY}
                                       ${QJSON_LIBRARIES})

install(TARGETS webpagetraverser RUNTIME DESTINATION bin)