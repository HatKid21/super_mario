target_sources(${PROJECT_NAME} PRIVATE
    qt_mario.cpp
    qt_mario.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
