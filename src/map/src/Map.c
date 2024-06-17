//
// Created by Dani on 2022. 11. 06..
//

//include my headers
#include "map/inc/Map.h"
#include "menu/inc/Menu.h"
#include "stdio.h"

Settings getSettings() {
    int windowWidth = 750;
    int windowHeight = 750;
    int numberOfSquares = 15;
    int sizeOfSquares = windowHeight / numberOfSquares;

    Settings settings = {windowWidth, windowHeight, sizeOfSquares};
    return settings;
}

void drawMap(SDL_Renderer* renderer) {
    Settings settings = getSettings();
    for (int x = 0; x < settings.windowWidth; ++x) {
        for (int y = 0; y < settings.windowHeight; ++y) {
            if (x / settings.sizeOfSquare % 2 == 0 && y / settings.sizeOfSquare % 2 == 0)
                pixelRGBA(renderer, x, y, 170, 215, 81, 220);
            if (x / settings.sizeOfSquare % 2 != 0 && y / settings.sizeOfSquare % 2 != 0)
                pixelRGBA(renderer, x, y, 170, 215, 81, 220);
            if (x / settings.sizeOfSquare % 2 != 0 && y / settings.sizeOfSquare % 2 == 0)
                pixelRGBA(renderer, x, y, 162, 209, 73, 190);
            if (x / settings.sizeOfSquare % 2 == 0 && y / settings.sizeOfSquare % 2 != 0)
                pixelRGBA(renderer, x, y, 162, 209, 73, 190);
        }
    }
}

void drawObject(SDL_Renderer* renderer, GameObject object) {
    Settings settings = getSettings();
    int x = object.coord.x * settings.sizeOfSquare + settings.sizeOfSquare / 2;
    int y = object.coord.y * settings.sizeOfSquare + settings.sizeOfSquare / 2;
    SDL_Color color = object.color;
    filledCircleRGBA(renderer, x, y, object.r, color.r, color.g, color.b, color.a);
}

void drawSnake(SDL_Renderer* renderer, Snake* snake) {
    for (Snake* i = snake; i != NULL; i = i->next) {
        drawObject(renderer, i->snakeTrait);
    }
}

Uint32 drawCallback(Uint32 ms, void *param) {
    SDL_Event event;
    event.type = SDL_USEREVENT;
    SDL_PushEvent(&event);
    return ms;
}

void drawGame(Controller controller, GameState* game) {
    SDL_Renderer* renderer = controller.renderer;
    char score[14];
    sprintf(score, "Points: %d", game->players->snake->length * 100 - 300);
    Text points = {(SDL_Rect) {10, 10, 140, 40},
                   score,
                   (SDL_Color) {255, 255, 0, 255}
    };
    drawMap(renderer);
    drawObject(renderer, game->food);
    for (int i = 0; i < game->numberOfPlayers; ++i)
      drawSnake(renderer, game->players[i].snake);
    if (game->numberOfPlayers == 1 && game->players->snake->length != 3) {
            createText(points, controller);
    }
}
