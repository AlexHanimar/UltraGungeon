set(HEADER_LIST
        ../../include/BasicObjects/GameObject.h
        ../../include/BasicObjects/AbstractHitbox.h
        ../../include/BasicObjects/AbstractEntity.h
        )

set(SOURCE_LIST
        GameObject.cpp
        AbstractHitbox.cpp
        AbstractEntity.cpp
        )

add_library(BasicObjects ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(BasicObjects PUBLIC ../../include)



set(CMAKE_PREFIX_PATH D:/Qt/6.5.0/mingw_64/lib/cmake)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
target_link_libraries(BasicObjects PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets)