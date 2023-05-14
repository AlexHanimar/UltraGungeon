set(HEADER_LIST
        ../../include/Entities/Wall.h
        ../../include/Entities/Door.h
        ../../include/Entities/MovableEntity.h
#        ../../include/Entities/NonPlayerEntity.h
#        ../../include/Entities/Projectile.h
#        ../../include/Entities/AbstractEnemy.h
#        ../../include/Entities/Hitbox.h
        )

set(SOURCE_LIST
        Wall.cpp
        Door.cpp
        MovableEntity.cpp
#        NonPlayerEntity.cpp
#        Projectile.cpp
#        AbstractEnemy.cpp
#        Hitbox.cpp
        )

add_library(Entities ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(Entities PUBLIC ../../include)


target_link_libraries(Entities PRIVATE BasicObjects Helpers)


set(CMAKE_PREFIX_PATH D:/Qt/6.5.0/mingw_64/lib/cmake)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
target_link_libraries(Entities PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets)