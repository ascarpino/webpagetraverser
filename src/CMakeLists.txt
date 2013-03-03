set(webpagetraverser_SRCS
    main.cpp
    webelement.cpp
    pagetraverser.cpp)

add_executable(WebPageTraverser ${webpagetraverser_SRCS})

target_link_libraries(WebPageTraverser ${Qt5Core_LIBRARIES}
                                       ${Qt5Widgets_LIBRARIES}
                                       ${Qt5WebKit_LIBRARIES}
                                       ${Qt5WebKitWidgets_LIBRARIES})

install(TARGETS WebPageTraverser RUNTIME DESTINATION bin)
