cmake_minimum_required(VERSION 3.23)
project(SnakeGame C)

set(CMAKE_C_STANDARD 99)

include_directories(include)
include_directories(src)
link_directories(lib)

add_executable(SnakeGame
        src/main.c

        # SDL2gfx source files #
        include/SDL2/SDL2_framerate.c
        include/SDL2/SDL2_gfxPrimitives.c
        include/SDL2/SDL2_imageFilter.c
        include/SDL2/SDL2_rotozoom.c
        src/gameobject/snake/inc/Snake.h src/gameobject/snake/src/Snake.c
        src/map/src/Map.c src/map/inc/Map.h src/init/inc/Init.h src/init/src/Init.c src/init/inc/Controller.h src/gameobject/object/inc/GameObject.h src/gameobject/object/src/GameObject.c src/gameobject/food/inc/Food.h src/gameobject/food/src/Food.c src/eventhandler/src/EventHandler.c src/eventhandler/inc/EventHandler.h src/init/src/Controller.c src/player/src/Player.c src/player/inc/Player.h src/gamestate/inc/GameState.h src/gamestate/src/GameState.c src/map/inc/Edge.h src/map/src/Edge.c src/menu/inc/Menu.h src/menu/src/Menu.c src/gamestate/inc/End.h src/gamestate/src/End.c src/menu/src/LeaderBoard.c src/menu/inc/LeaderBoard.h src/menu/src/File.c src/menu/inc/File.h)
target_link_libraries(SnakeGame -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf)