set(webpagetraverser_SRCS
    main.cpp
    webelement.cpp
    pagetraverser.cpp)

add_executable(WebPageTraverser ${webpagetraverser_SRCS})

qt5_use_modules(WebPageTraverser Core Widgets WebKit WebKitWidgets)

install(TARGETS WebPageTraverser RUNTIME DESTINATION bin)
