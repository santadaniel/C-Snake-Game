//
// Created by Dani on 2022. 11. 26..
//

#ifndef SNAKEGAME_LEADERBOARD_H
#define SNAKEGAME_LEADERBOARD_H

//include my headers
#include "menu/inc/Menu.h"

#include <stdbool.h>
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL2_gfxPrimitives.h"

/// \brief Defines a struct that stores a player's name and score.
typedef struct PlayerData {
    char name[20 + 1];
    int score;
} PlayerData;

/// \brief Defines a struct that stores an array of playerdatas
/// and a bool that check if the enter buttom is pressed or not.
typedef struct LeaderBoard {
    PlayerData playerData[10];
    bool isPressed;
} LeaderBoard;

/// \brief makes a rectangular on the screen where you can write your name.
bool input_text(char *dest, size_t hossz, SDL_Rect teglalap, SDL_Color hatter, SDL_Color szoveg, TTF_Font *font, SDL_Renderer *renderer);

/// Puts the given index on the screen.
/// \param controller the current controller.
/// \param i the index.
void putIndexOnLeaderBoard(Controller controller, int i);

/// Puts the given score on the screen.
/// \param controller the current controller.
/// \param score the player's score.
/// \param i the index of the score.
void putScoreOnLeaderBoard(Controller controller, int score, int i);

/// Puts the given name on the screen.
/// \param controller the current controller.
/// \param name the player's name.
/// \param i the index of the name.
void putNameOnLeaderBoard(Controller controller, char* name, int i);

/// Puts the given leaderboard on the screen.
/// \param controller the current controller.
/// \param leaderBoard the current leaderboard.
/// \param i the current index.
void putPlayerOnLeaderBoard(Controller controller, LeaderBoard leaderBoard, int i);

/// If clicked on the Leaderboard button, it opens it.
/// \param stage the current stage.
void startLeaderBoard(Stage* stage);

/// Opens the leaderboard, draws the names and scores on it.
/// \param controller the current controller.
/// \param game the current game.
/// \param leaderBoard the current leaderboard.
void openLeaderBoard(Controller controller, GameState* game, LeaderBoard leaderBoard);

/// Check if a player makes it on the leaderboard and if it does, it takes the name and puts
/// it and the score on the leaderboard.
/// \param controller the current controller.
/// \param game the current game.
/// \param leaderBoard the current leaderboard.
void checkLeaderBoard(Controller controller, GameState* game, LeaderBoard* leaderBoard);

/// Puts the current playerData using the placing on the leaderboard.
/// \param leaderBoard the current leaderboard.
/// \param placing the placing of the player.
void refactorLeaderBoard(LeaderBoard* leaderBoard, int placing);

/// Gives the current player's position on the leaderboard.
/// \param leaderBoard the current leaderboard.
/// \param score the player's score.
/// \return the player's placing.
int placingOnLeaderBoard(LeaderBoard* leaderBoard, int score);

#endif //SNAKEGAME_LEADERBOARD_H
