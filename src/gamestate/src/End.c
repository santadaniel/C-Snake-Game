//
// Created by Dani on 2022. 11. 23..
//

//include my headers
#include "gamestate/inc/End.h"
#include "stdio.h"
#include "menu/inc/LeaderBoard.h"

typedef struct SDL_EVENT SDL_EVENT;

void sameCoordSnakeSelf(GameState* game) {
    for (int i = 0; i < game->numberOfPlayers; ++i) {
        if (sameCoordObject(game->players[i].snake->next, game->players[i].snake->snakeTrait.coord)) {
            game->players[i].snake->isAlive = false;
        }
    }
}

void sameCoordSnakes(GameState* game) {
    Player* players = game->players;

    bool isCollideFirst = sameCoordObject(players[0].snake, players[1].snake->snakeTrait.coord);
    if (isCollideFirst) {
        players[0].snake->isAlive = false;
    }

    bool isCollideSecond = sameCoordObject(players[1].snake, players[0].snake->snakeTrait.coord);
    if (isCollideSecond) {
        players[1].snake->isAlive = false;
    }
}

void sameCoordWall(GameState* game) {
    Settings settings = getSettings();
    int numberOfSquares = settings.windowHeight/settings.sizeOfSquare;
    Coord* edge =  getMapEdge();

    for (int i = 0; i < game->numberOfPlayers; ++i) {
        for (int j = 0; j < 4 * numberOfSquares; ++j) {
            if (sameCoordObject(game->players[i].snake, edge[j])) {
                game->players[i].snake->isAlive = false;
                break;
            }
        }
    }
    free(edge);
}

void checkCoordSnakes(GameState* game) {
    sameCoordSnakeSelf(game);
    sameCoordWall(game);
    if (game->numberOfPlayers == 2) {
        sameCoordSnakes(game);
    }
}

void caseOfEnding(Controller controller, GameState* game, LeaderBoard* leaderBoard) {
    if (game->numberOfPlayers == 1) {
        caseOfOnePlayer(controller, game);
        if (!leaderBoard->isPressed) {
            checkLeaderBoard(controller, game, leaderBoard);
            leaderBoard->isPressed = true;
        }
    }
    if (game->numberOfPlayers == 2) {
        caseOfTwoPlayer(controller, game);
    }
    backToMenu(controller, game);
}

void backToMenu(Controller controller, GameState* game) {
    SDL_Rect backGround = {225, 560, 300, 65};
    int x, y;
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    drawButtonBackGround(controller, backGround);
    createButton(controller, "Back to menu", backGround);
    if (buttons == SDL_BUTTON_LEFT) {
        if (225 <= x && x <= 525) {
            if (560 <= y && y <= 625) {
                if (game->currentStage == END) {
                    freeGame(game);
                }
                game->currentStage = MENU;
                return;
            }
        }
    }
}

void caseOfOnePlayer(Controller controller, GameState* game) {
    char score[22];
    sprintf(score, "Your score is : %d", game->players->snake->length * 100 - 300);
    Text text = {(SDL_Rect) {200, 345, 350, 60},
                 score,
                 (SDL_Color) {255, 255, 255, 255}
    };
    createText(text, controller);
    SDL_RenderPresent(controller.renderer);
}

void caseOfTwoPlayer(Controller controller, GameState* game) {
    Player* players = game->players;
    Text text;
    text.rect = (SDL_Rect) {150, 345, 450, 60};
    text.color = (SDL_Color) {0, 0, 0, 255};
    if (players[0].snake->isAlive) {
        text.sentence = "Blue player is the winner";
    }
    if (players[1].snake->isAlive) {
        text.sentence = "Yellow player is the winner";
    }
    if (!players[1].snake->isAlive && !players[0].snake->isAlive) {
        text.sentence = "It's a draw, there is no winner";
    }
    createText(text, controller);
    SDL_RenderPresent(controller.renderer);
}

PlayerData toPlayerData(char* name, int score) {
    PlayerData playerData;
    strcpy(playerData.name, name);
    playerData.score = score;
    return playerData;
}
