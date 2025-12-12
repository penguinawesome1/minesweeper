cmake_minimum_required(VERSION 3.20)
project(minesweeper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MINESWEEPER_SOURCES
    src/main.cpp
    src/managers/AssetManager.cpp
    src/config/builder/ConfigBuilder.cpp
    src/core/helpers/helpers.cpp
    src/core/collision.cpp
    src/welcome/Welcome.cpp
    src/welcome/components/ui_builder.cpp
    src/welcome/components/TextManager.cpp
    src/game/Game.cpp
    src/game/components/ui_builder.cpp
    src/game/components/TimerManager.cpp
    src/game/components/FlagManager.cpp
    src/game/components/Buttons.cpp
    src/game/components/Board.cpp
    src/game/helpers/helpers.cpp
    src/game/helpers/user_input.cpp
    src/game/helpers/renderer.cpp
    src/leaderboard/Leaderboard.cpp
    src/leaderboard/components/ui_builder.cpp
    src/leaderboard/io/file_io.cpp
)

add_executable(minesweeper ${MINESWEEPER_SOURCES})

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

target_link_libraries(minesweeper PRIVATE
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)