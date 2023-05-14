set(HEADER_LIST
        ../../include/MapGenerator/MapGenerator.h
        ../../include/MapGenerator/RoomGenerator.h
        )

set(SOURCE_LIST
        MapGenerator.cpp
        RoomGenerator.cpp)

add_library(MapGenerator ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(MapGenerator PUBLIC ../../include)