add_executable(UltraGungeon main.cpp)

target_link_libraries(UltraGungeon PRIVATE
        MapGenerator
        BasicObjects
        Entities
        Model
        Interface
        Helpers
        )
set(qt_dll_path "D:/Qt/6.5.0/mingw_64/bin")
set(qt_dll_list
        "${qt_dll_path}/Qt6Core.dll"
        "${qt_dll_path}/Qt6Gui.dll"
        "${qt_dll_path}/Qt6Widgets.dll")
file(COPY ${qt_dll_list} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})