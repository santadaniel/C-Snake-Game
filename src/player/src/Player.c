//
// Created by Dani on 2022. 11. 12..
//

#include "player/inc/Player.h"

Player createPlayerOneA() {
    return (Player) {
            {SDL_SCANCODE_W, SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_D},
            makeBlueSnakeA(),
            LEFT
    };
}

Player createPlayerOneB() {
    return (Player) {
    {SDL_SCANCODE_W, SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_D},
    makeBlueSnakeB(),
    LEFT
    };
}

Player createPlayerTwo() {
    return (Player) {
    {SDL_SCANCODE_UP, SDL_SCANCODE_LEFT, SDL_SCANCODE_DOWN, SDL_SCANCODE_RIGHT},
    makeYellowSnake(),
    LEFT
    };
}

void updatePlayer(Player player) {
    moveSnake(player.snake, player.dir);
}
