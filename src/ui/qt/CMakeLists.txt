add_subdirectory(ui_objects)

target_sources(${PROJECT_NAME} PRIVATE
    game_window.cpp
    game_window.hpp

    qt_keyboard.cpp
    qt_keyboard.hpp

    qt_ui_object.hpp
    qt_ui_obj_rect_adapter.hpp
    qt_ui_obj_rect_adapter.cpp

    qt_game_map.cpp
    qt_game_map.hpp

    qt_ui_factory.cpp
    qt_ui_factory.hpp

  resources/sprites.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}"
)
