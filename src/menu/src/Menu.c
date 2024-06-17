//
// Created by Dani on 2022. 11. 20..
//

//include my headers
#include "menu/inc/Menu.h"
#include "map/inc/Map.h"
#include "menu/inc/LeaderBoard.h"

void createMenu(Controller controller) {
    drawMenuBackGround(controller);
    createTitle(controller);
    createOptions(controller);
    SDL_RenderPresent(controller.renderer);
}

void drawMenuBackGround(Controller controller) {
    Settings settings = getSettings();
    SDL_Rect rect = {0, 0, settings.windowWidth, settings.windowHeight};
    SDL_Color color = {162, 209, 73, 190};
    drawBackGround(controller, color, rect);
}

void drawButtonBackGround(Controller controller, SDL_Rect rect) {
    SDL_Color color = {50,205,50, 250};
    drawBackGround(controller, color, rect);
}

void drawBackGround(Controller controller, SDL_Color color, SDL_Rect rect) {
    SDL_SetRenderDrawColor(controller.renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(controller.renderer, &rect);
}

void createOptions(Controller controller) {
    SDL_Rect rects[4] = {{200, 175, 350, 85},
                         {200, 325, 350, 85},
                         {200, 475, 350, 85},
                         {315, 625, 120, 75}
                         };
    char* options[4] = {"Singleplayer","Multiplayer","Leaderboard","Quit"};
    for (int i = 0; i < 4; ++i) {
        drawButtonBackGround(controller, rects[i]);
        createButton(controller, options[i], rects[i]);
    }
}

void createText(Text text, Controller controller) {
    SDL_Surface* surface = TTF_RenderText_Blended(controller.font,
                                                  text.sentence,
                                                  text.color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(controller.renderer, surface);
    SDL_RenderCopy(controller.renderer, texture, NULL, &text.rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void createTitle(Controller controller) {
    Text title;
    title.rect = (SDL_Rect) {175, 40, 400, 100};
    title.sentence = "Snake Game";
    title.color = (SDL_Color) {255, 0, 0, 255};
    createText(title, controller);
}

void createButton(Controller controller, char* text, SDL_Rect rect) {
    Text button;
    button.rect = rect;
    button.sentence = text;
    button.color = (SDL_Color) {255, 0, 0, 255};
    createText(button, controller);
}

bool menuEndGame() {
    int x, y;
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    if (buttons == SDL_BUTTON_LEFT) {
        if (315 <= x && x <= 435) {
            if (625 <= y && y <= 700) {
                return true;
            }
        }
    }
    return false;
}

void menuStartGame(GameState* game) {
    int x, y;
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    if (buttons == SDL_BUTTON_LEFT)
        if (200 <= x && x <= 550) {
            if (175 <= y && y <= 260) {
                *game = createOnePlayerGame();
                game->currentStage = PLAY;
                return;
            }
            if (325 <= y && y <= 410) {
                *game = createTwoPlayerGame();
                game->currentStage = PLAY;
                return;
            }
        }
}
