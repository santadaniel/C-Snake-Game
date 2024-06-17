//
// Created by Dani on 2022. 11. 08..
//

//include my headers
#include "gameobject/object/inc/GameObject.h"
#include "stdlib.h"
#include "map/inc/Map.h"

SDL_Color getColorYellow() {
    return (SDL_Color) {255, 255, 0, 255};
};

SDL_Color getColorBlue() {
    return (SDL_Color) {0, 0, 255, 255};
};

SDL_Color getColorRed() {
    return (SDL_Color) {255, 0, 0, 255};
};

int makeRandomNumber() {
    Settings settings = getSettings();
    return rand() % (settings.windowHeight / settings.sizeOfSquare);
}

Coord makeRandomCoord() {
    return (Coord) {makeRandomNumber(), makeRandomNumber()};
}

GameObject createGameObject(int r, Coord coord, SDL_Color color) {
    return (GameObject) {r, coord, color};
}
