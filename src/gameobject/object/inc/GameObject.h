//
// Created by Dani on 2022. 11. 07..
//

#ifndef SNAKEGAME_GAMEOBJECT_H
#define SNAKEGAME_GAMEOBJECT_H

#include "SDL2/SDL_pixels.h"
#include "stdbool.h"

/// \brief Defines a struct that stores the x and the y coordinates.
typedef struct Coord {
    int x;
    int y;
} Coord;

/// \brief Defines a struct that stores the radius, the coordinates and the color of the object.
typedef struct GameObject {
    int r;
    Coord coord;
    SDL_Color color;
} GameObject;

/// Gets the color yellow.
/// \return the RGBA of the given color.
SDL_Color getColorYellow();

/// Gets the color yellow.
/// \return the RGBA of the given color.
SDL_Color getColorBlue();

/// Gets the color yellow.
/// \return the RGBA of the given color.
SDL_Color getColorRed();

/// Creates a random number between two parameters.
/// \return with a random number between 0 and the number of squares-1.
int makeRandomNumber();

/// Creates a random coordinate on the map.
/// \return with random x and y coordinates.
Coord makeRandomCoord();

/// Creates a Gameobject using the given parameters.
/// \param r the radius of the gameobject.
/// \param coord the coordinates of the gameobject.
/// \param color the color of the gameobject .
/// \return with a Gameobject at the given coordinates, with the given color and a given radius.
GameObject createGameObject(int r, Coord coord, SDL_Color color);

#endif //SNAKEGAME_GAMEOBJECT_H
