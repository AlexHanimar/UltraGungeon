cmake_minimum_required(VERSION 3.25)
project(UltraGungeon)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

add_subdirectory(src/MapGenerator)
add_subdirectory(src/BasicObjects)
add_subdirectory(src/Entities)
add_subdirectory(src/Model)
add_subdirectory(src/Interface)
add_subdirectory(src/Helpers)

add_subdirectory(app)

