//
// Created by Dani on 2022. 11. 12..
//

//include my headers
#include "map/inc/Map.h"
#include "eventhandler/inc/EventHandler.h"
#include "gamestate/inc/End.h"

void caseUserEvent(Controller controller, GameState* game) {
    SDL_Renderer* renderer = controller.renderer;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    checkCoordSnakes(game);
    drawGame(controller, game);
    bool isAllAlive = true;
    for (int i = 0; i < game->numberOfPlayers; ++i) {
        if (!game->players[i].snake->isAlive) {
            isAllAlive = false;
            break;
        }
    }
    if (isAllAlive) {
        updateGame(game);
    }
    else
        game->currentStage = END;
    SDL_RenderPresent(renderer);
}

void keyboardEvent(GameState* game) {
    const Uint8* keyboard = SDL_GetKeyboardState(NULL);
    for (int i = 0; i < game->numberOfPlayers; ++i) {
        if (keyboard[game->players[i].buttons[0]] && game->players[i].dir != DOWN) {
            game->players[i].dir = UP;
        }
        if (keyboard[game->players[i].buttons[1]] && game->players[i].dir != RIGHT) {
            game->players[i].dir = LEFT;
        }
        if (keyboard[game->players[i].buttons[2]] && game->players[i].dir != UP) {
            game->players[i].dir = DOWN;
        }
        if (keyboard[game->players[i].buttons[3]] && game->players[i].dir != LEFT) {
            game->players[i].dir = RIGHT;
        }
    }
}
