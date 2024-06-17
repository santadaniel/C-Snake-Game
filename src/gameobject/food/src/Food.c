//
// Created by Dani on 2022. 11. 08..
//

//include my headers
#include "gameobject/food/inc/Food.h"
#include "map/inc/Map.h"

GameObject createFood(GameState* game) {
    Coord coord = makeRandomCoord();
    bool everySnake = false;
    while (!everySnake) {
        for (int i = 0; i < game->numberOfPlayers; ++i) {
            if (sameCoordObject(game->players[i].snake, coord)) {
                coord = makeRandomCoord();
                break;
            }
        }
        everySnake = true;
    }
    return createGameObject(getSettings().sizeOfSquare / 2 - 10, coord, getColorRed());
}
