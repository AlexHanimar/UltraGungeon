set(HEADER_LIST
        ../../include/Entities/Wall.h
        ../../include/Entities/Door.h
        ../../include/Entities/MovableEntity.h
        ../../include/Entities/PlayerEntity.h
        ../../include/Entities/Projectile.h
        ../../include/Entities/Teams.h
        ../../include/Entities/AbstractEnemy.h
        ../../include/Entities/EnemyFilth.h
        ../../include/Entities/EnemyAndre.h
        ../../include/Entities/Trigger.h
        ../../include/Entities/Hitscan.h
        )

set(SOURCE_LIST
        Wall.cpp
        Door.cpp
        MovableEntity.cpp
        PlayerEntity.cpp
        Projectile.cpp
        AbstractEnemy.cpp
        EnemyFilth.cpp
        EnemyAndre.cpp
        Trigger.cpp
        Hitscan.cpp
        )

add_library(Entities ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(Entities PUBLIC ../../include)


target_link_libraries(Entities PRIVATE BasicObjects Helpers)


set(CMAKE_PREFIX_PATH "C:/Qt/6.5.0/mingw_64/lib/cmake;D:/Qt/6.5.0/mingw_64/lib/cmake")
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
target_link_libraries(Entities PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets)