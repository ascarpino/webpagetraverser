set(webpagetraverser_SRCS
    customwebpage.cpp
    main.cpp
    pagetraverser.cpp
    webelement.cpp)

configure_file(webpagetraverser.h.in ${CMAKE_CURRENT_BINARY_DIR}/webpagetraverser.h)

add_executable(WebPageTraverser ${webpagetraverser_SRCS})

qt5_use_modules(WebPageTraverser Core Widgets WebKit WebKitWidgets)

install(TARGETS WebPageTraverser RUNTIME DESTINATION bin)
