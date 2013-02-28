set(webpagetraverser_SRCS
    main.cpp
    webelement.cpp
    pagetraverser.cpp)

add_executable(WebPageTraverser ${webpagetraverser_SRCS})

target_link_libraries(WebPageTraverser ${QT_QTCORE_LIBRARY}
                                       ${QT_QTGUI_LIBRARY}
                                       ${QT_QTWEBKIT_LIBRARY}
                                       ${QJSON_LIBRARIES})

install(TARGETS WebPageTraverser RUNTIME DESTINATION bin)
