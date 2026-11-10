target_sources(${PROJECT_NAME} PRIVATE
    qt_mario.hpp
    qt_mario.cpp
    
    qt_box.cpp
    qt_box.hpp

    qt_ship.cpp
    qt_ship.hpp

    qt_enemy.cpp
    qt_enemy.hpp

    qt_money.cpp
    qt_money.hpp

    qt_full_box.cpp
    qt_full_box.hpp

    qt_flying_enemy.cpp
    qt_flying_enemy.hpp

    qt_jumping_enemy.cpp
    qt_jumping_enemy.hpp

    qt_floating_platform.cpp
    qt_floating_platform.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
