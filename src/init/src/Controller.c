//
// Created by Dani on 2022. 11. 12..
//

//include my headers
#include "init/inc/Controller.h"

void destroyController(Controller controller) {
    SDL_DestroyRenderer(controller.renderer);
    SDL_DestroyWindow(controller.window);
    TTF_CloseFont(controller.font);
}
