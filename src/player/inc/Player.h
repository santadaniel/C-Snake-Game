//
// Created by Dani on 2022. 11. 12..
//

#ifndef SNAKEGAME_PLAYER_H
#define SNAKEGAME_PLAYER_H

//include my headers
#include "gameobject/snake/inc/Snake.h"
#include "init/inc/Init.h"

/// \brief Defines a struct that stores the pressed buttons, a snake and a direction.
typedef struct Player {
    Uint8 buttons[4];
    Snake* snake;
    Direction dir;
} Player;

/// In case of a singleplayer game creates a player.
/// \return the created player.
Player createPlayerOneA();

/// In case of a multiplayer game creates Player One.
/// \return the created player.
Player createPlayerOneB();

/// In case of a multiplayer game creates Player Two.
/// \return the created player.
Player createPlayerTwo();

/// Moves the snake depending on the inputs given by the player.
/// \param player the current state of the player.
void updatePlayer(Player player);

#endif //SNAKEGAME_PLAYER_H
