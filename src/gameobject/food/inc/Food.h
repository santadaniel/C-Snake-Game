//
// Created by Dani on 2022. 11. 08..
//

#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H

//include my headers
#include "gamestate/inc/GameState.h"


/// Creates a food with randomized coordinates.
/// \param snake the current state of the snake.
/// \return New instance of Food.
GameObject createFood(GameState* game);

#endif //SNAKEGAME_FOOD_H
