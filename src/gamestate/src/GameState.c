//
// Created by Dani on 2022. 11. 13..
//

//include my headers
#include "gamestate/inc/GameState.h"
#include "gameobject/food/inc/Food.h"
#include "map/inc/Map.h"

GameState createOnePlayerGame() {
    Player* players = (Player*) malloc(sizeof (Player));
    players[0] = createPlayerOneA();
    return (GameState) {
        MENU,
        players,
        1,
        createGameObject(getSettings().sizeOfSquare / 2 - 10, (Coord) {5, 2}, getColorRed())
    };
}

GameState createTwoPlayerGame() {
    Player* players = (Player*) malloc(2 * sizeof (Player));
    players[0] = createPlayerOneB();
    players[1] = createPlayerTwo();
    return (GameState) {
        MENU,
        players,
        2,
        createGameObject(getSettings().sizeOfSquare / 2 - 10, (Coord) {7, 7}, getColorRed())
    };
}

void updateGame(GameState* game) {
    for (int i = 0; i < game->numberOfPlayers; ++i) {
        updatePlayer(game->players[i]);
    }
    updateFood(game);
}

void updateFood(GameState* game) {
    for (int i = 0; i < game->numberOfPlayers; ++i) {
        if (sameCoordObject(game->players[i].snake, game->food.coord)) {
            game->food = createFood(game);
            growSnake(game->players[i].snake);
        }
    }
}

bool sameCoordObject(Snake* snake, Coord coord) {
    for (Snake* i = snake; i != NULL; i = i->next) {
        if (i->snakeTrait.coord.x == coord.x && i->snakeTrait.coord.y == coord.y)
            return true;
    }
    return false;
}

void freeGame(GameState* game) {
    for (int i = 0; i < game->numberOfPlayers; ++i) {
        freeSnake(game->players[i].snake);
    }
    free(game->players);
}
