//
// Created by Dani on 2022. 11. 06..
//

#ifndef SNAKEGAME_MAP_H
#define SNAKEGAME_MAP_H

//include my headers
#include "init/inc/Init.h"
#include "gameobject/object/inc/GameObject.h"
#include "gamestate/inc/GameState.h"

/// \brief Defines a struct that stores the width, the height of the window and the size of one square on the map.
typedef struct Settings {
    int windowWidth;
    int windowHeight;
    int sizeOfSquare;
} Settings;

/// Gets the current settings.
/// \return the currents settings.
Settings getSettings();

/// Draws the map on the screen.
/// \param renderer draws on screen.
void drawMap(SDL_Renderer* renderer);

/// Draws an object on the screen.
/// \param renderer draws on screen.
/// \param object the current state of the object.
void drawObject(SDL_Renderer* renderer, GameObject object);

/// Draws a snake on the screen.
/// \param renderer draws on screen.
/// \param snake the current state of the snake.
void drawSnake(SDL_Renderer* renderer, Snake* snake);

/// Puts a new USEREVENT to the event queue.
/// \param ms update speed in milliseconds.
/// \param param optional parameter (unused here).
/// \return updating speed.
Uint32 drawCallback(Uint32 ms, void *param);

/// Draws the whole game at once.
/// \param renderer draws on screen.
/// \param game the current state of the game.
void drawGame(Controller controller, GameState* game);

#endif //SNAKEGAME_MAP_H
