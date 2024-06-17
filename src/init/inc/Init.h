//
// Created by Dani on 2022. 11. 06..
//

#ifndef SNAKEGAME_INIT_H
#define SNAKEGAME_INIT_H

//include my headers
#include "init/inc/Controller.h"

/// Creates a controller.
/// \return the current controller.
Controller createController();

/// Creates a window.
/// \return the current window.
SDL_Window* createWindow();

/// Creates a renderer.
/// \return the current renderer.
SDL_Renderer* createRenderer(SDL_Window* window);

/// Creates a font.
/// \return the current font.
TTF_Font* createFont();

/// \brief Initialize the SDL.
void initSDL();

#endif //SNAKEGAME_INIT_H
