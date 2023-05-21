add_executable(UltraGungeon main.cpp)

target_link_libraries(UltraGungeon PRIVATE
        MapGenerator
        BasicObjects
        Entities
        Model
        Interface
        Helpers
        )

find_file(qt_dll_list
        NAMES Qt6Core.dll Qt6Gui.dll Qt6Widgets.dll
        PATHS C:/Qt/6.5.0/mingw_64/bin D:/Qt/6.5.0/mingw_64/bin
        )
file(COPY ${qt_dll_list} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})