set(HEADER_LIST
        ../../include/Helpers/Helpers.h
        )

set(SOURCE_LIST
        Helpers.cpp)

add_library(Helpers ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(Helpers PUBLIC ../../include)



set(CMAKE_PREFIX_PATH D:/Qt/6.5.0/mingw_64/lib/cmake)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
target_link_libraries(Helpers PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets)