//
// Created by Dani on 2022. 11. 12..
//

#ifndef SNAKEGAME_EVENTHANDLER_H
#define SNAKEGAME_EVENTHANDLER_H

//include my headers
#include "player/inc/Player.h"

/// Checks if the Snake(s) is/are alive or not, it also updates and draws the game.
/// \param controller the current controller.
/// \param game the current game.
void caseUserEvent(Controller controller, GameState* game);

/// Checks which button is pressed and changes the direction with it.
/// \param player the current state of the player.
void keyboardEvent(GameState* game);

#endif //SNAKEGAME_EVENTHANDLER_H
