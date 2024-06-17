//
// Created by Dani on 2022. 11. 20..
//

#ifndef SNAKEGAME_MENU_H
#define SNAKEGAME_MENU_H

//include my headers
#include "init/inc/Init.h"
#include "gameobject/object/inc/GameObject.h"
#include "gamestate/inc/GameState.h"

/// \brief Defines a struct that stores a rectangular, a sentence and the color of the sentence.
typedef struct Text {
    SDL_Rect rect;
    char* sentence;
    SDL_Color color;
} Text;

/// Draws the background of the menu.
/// \param controller the current controller.
void drawMenuBackGround(Controller controller);

/// Creates a rectangular behind the button (for looks only).
/// \param controller the current controller.
/// \param rect the size of the rectangular behind the button.
void drawButtonBackGround(Controller controller, SDL_Rect rect);

/// Draws a rectangular with the given color.
/// \param controller the current controller.
/// \param color the color of the rectangular.
/// \param rect the size of the rectangular.
void drawBackGround(Controller controller, SDL_Color color, SDL_Rect rect);

/// Creates the option buttons on their backgrounds.
/// \param controller the current controller.
void createOptions(Controller controller);

/// Creates a text.
/// \param text the text that needs to be created.
/// \param controller the current controller.
void createText(Text text, Controller controller);

/// Draws the menu, the title of the game and the buttons on the menu.
/// \param controller the current controller.
void createMenu(Controller controller);

/// Creates the Title of The Game.
/// \param controller the current controller.
void createTitle(Controller controller);

/// Creates a button using the given parameters.
/// \param controller the current controller.
/// \param text the text that needs to be created.
/// \param rect the rectangular where the text will be.
void createButton(Controller controller, char* text, SDL_Rect rect);

/// Checks if the button is pressed or not.
/// \return yes if the button is pressed, no if it is not pressed.
bool menuEndGame();

/// If the singleplayer of the multiplayer button is pressed, it starts the game.
/// \param game the game that will be created.
void menuStartGame(GameState* game);

#endif //SNAKEGAME_MENU_H
