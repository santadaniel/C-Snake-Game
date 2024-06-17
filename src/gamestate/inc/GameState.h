//
// Created by Dani on 2022. 11. 13..
//

#ifndef SNAKEGAME_GAMESTATE_H
#define SNAKEGAME_GAMESTATE_H

//include my headers
#include "player/inc/Player.h"

/// \brief Defines a struct that stores players and the food.
typedef struct GameState {
    Stage currentStage;
    Player* players;
    int numberOfPlayers;
    GameObject food;
} GameState;

/// Creating a player and food.
/// \return New instance of GameState.
GameState createOnePlayerGame();

/// Creating two players and food.
/// \return New instance of GameState.
GameState createTwoPlayerGame();

/// Updates players and food.
/// \param game current state of the game.
void updateGame(GameState* game);

/// Updates the food.
/// \param game current state of the game.
void updateFood(GameState* game);

/// Checks if the snake and an object are at the same place.
/// \param snake the current state of the snake.
/// \param coord the current state of the given object.
/// \return true if the two object are at the same coordinates, if not, false.
bool sameCoordObject(Snake* snake, Coord coord);

/// Frees the game.
/// \param game the current game.
void freeGame(GameState* game);

#endif //SNAKEGAME_GAMESTATE_H
