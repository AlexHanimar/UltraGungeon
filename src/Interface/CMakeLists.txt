set(HEADER_LIST
        ../../include/Interface/MainWindow.h
        ../../include/Interface/Renderer.h)

set(SOURCE_LIST
        MainWindow.cpp
        Renderer.cpp
        )

add_library(Interface ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(Interface PUBLIC ../../include)


target_link_libraries(Interface PRIVATE Model)


set(CMAKE_PREFIX_PATH D:/Qt/6.5.0/mingw_64/lib/cmake)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
target_link_libraries(Interface PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets)