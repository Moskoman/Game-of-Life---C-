cmake_minimum_required (VERSION 2.6)
project (GoL)

add_definitions(-std=c++11)

find_package(sdl2 REQUIRED)

include_directories(
  include/
  ${SDL2_INCLUDE_DIRS}
)

add_executable(GoL
    main.cpp
    GraphicsManager.h
    GraphicsManager.cpp
    GameEngine.h
    GameEngine.cpp
    OriginalStrategy.h
    DerivationStrategy.h
    DerivationStrategy.cpp
    OriginalStrategy.cpp
    HighLife.h
    HighLife.cpp
    DayNight.h
    DayNight.cpp
    Maze.h
    Maze.cpp
    Replicator.h
    Replicator.cpp
    Cell.h
    Cell.cpp
    InputHandler.h
    InputHandler.cpp
    StateManager.h
    StateManager.cpp
    State.h
    State.cpp
    Menu.h
    Menu.cpp
    GridSizeSelector.h
    GridSizeSelector.cpp
    Game.h
    Game.cpp
    )
target_link_libraries(GoL SDL2 SDL2_image SDL2_mixer SDL2_ttf)
