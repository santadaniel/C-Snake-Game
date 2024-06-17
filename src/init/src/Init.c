//
// Created by Dani on 2022. 11. 06..
//

//include my headers
#include "init/inc/Init.h"
#include "map/inc/Map.h"

#include "stdio.h"

Controller createController() {
    initSDL();

    TTF_Font* font = createFont();
    SDL_Window* window = createWindow();
    SDL_Renderer* renderer = createRenderer(window);
    Controller controller = {window, renderer, font};
    return controller;
}

TTF_Font* createFont() {
    TTF_Init();
    TTF_Font* font = TTF_OpenFont(
        "LiberationSerif-Regular.ttf",
        75
    );
    if (font == NULL) {
        printf("Font cannot be created");
        exit(1);
    }
    return font;
}

SDL_Window* createWindow() {
    Settings settings = getSettings();
    SDL_Window* window = SDL_CreateWindow("SnakeGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, settings.windowWidth, settings.windowHeight, 0);
    if (window == NULL) {
        printf("Window cannot be created");
        exit(1);
    }
    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        printf("Rendered cannot be created");
        exit(1);
    }
    return renderer;
}

void initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL cannot be initialized");
        exit(1);
    }
}
