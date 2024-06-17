//
// Created by Dani on 2022. 11. 23..
//

#ifndef SNAKEGAME_END_H
#define SNAKEGAME_END_H

//include my headers
#include "gamestate/inc/GameState.h"
#include "map/inc/Map.h"
#include "map/inc/Edge.h"
#include "menu/inc/Menu.h"
#include "menu/inc/LeaderBoard.h"


/// Checks if the snake hit itself.
/// \param snake the current snake.
void sameCoordSnakeSelf(GameState* game);

/// Checks if the Snakes hit each other in case of a multiplayer game.
/// \param game the current game.
void sameCoordSnakes(GameState* game);

/// Checks if the snake(s) hit the wall or not.
/// \param game the current game.
void sameCoordWall(GameState* game);

/// Checks all the above.
/// \param game the current game.
void checkCoordSnakes(GameState* game);

/// It ends the game and gives the option to get back to the menu.
/// \param controller the current controller.
/// \param game the current game.
/// \param leaderBoard the current leaderboard.
void caseOfEnding(Controller controller, GameState* game, LeaderBoard* leaderBoard);

/// Creates a button that take the player back to the menu.
/// \param controller the current controller.
/// \param game the current game.
void backToMenu(Controller controller, GameState* game);

/// In case of a singleplayer game it writes the score on the screen and checks if the player
/// have made it on the leaderboard.
/// \param controller the current controller.
/// \param game the current game.
void caseOfOnePlayer(Controller controller, GameState* game);

/// In case of a multiplayer game it writes the winner on the
/// screen and.
/// \param controller the current controller.
/// \param game the current game.
void caseOfTwoPlayer(Controller controller, GameState* game);

/// Puts the parameters inside a playerData struct.
/// \param name the name of the current player
/// \param score the score of the current game.
/// \return the current player's data.
PlayerData toPlayerData(char* name, int score);

#endif //SNAKEGAME_END_H
