set(HEADER_LIST
        ../../include/Model/Model.h
        ../../include/Model/EntityWrapper.h)

set(SOURCE_LIST
        Model.cpp
        EntityWrapper.cpp)

add_library(Model ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(Model PUBLIC ../../include)


target_link_libraries(Model PRIVATE Entities)


set(CMAKE_PREFIX_PATH "C:/Qt/6.5.0/mingw_64/lib/cmake;D:/Qt/6.5.0/mingw_64/lib/cmake")
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
target_link_libraries(Model PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets)