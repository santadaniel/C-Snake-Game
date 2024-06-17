//
// Created by Dani on 2022. 11. 06..
//

#ifndef SNAKEGAME_CONTROLLER_H
#define SNAKEGAME_CONTROLLER_H

//SDl includes
#include "SDL2/SDL.h"
#include "SDL2/SDL2_gfxPrimitives.h"
#include "SDL2/SDL_ttf.h"

/// \brief Defines a struct that stores a window and a renderer and a font.
typedef struct Controller {
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
} Controller;

/// \brief Defines an enum that stores the current stage.
typedef enum Stage {
    MENU,
    PLAY,
    END,
    LEADERBOARD
} Stage;

/// Destroys the window and the renderer.
/// \param controller the current controller.
void destroyController(Controller controller);

#endif //SNAKEGAME_CONTROLLER_H
