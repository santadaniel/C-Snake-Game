//
// Created by Dani on 2022. 11. 03..
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

//include my headers
#include "gameobject/object/inc/GameObject.h"

/// \brief Defines a struct that stores the traits of the snake and a pointer to the next element.
typedef struct Snake {
    GameObject snakeTrait;
    bool isAlive;
    int length;
    struct Snake* next;
} Snake;

/// \brief Defines an enum that stores the four main directions.
typedef enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
} Direction;

/// Grows the snake by 1.
/// \param snake the current state of the snake.
void growSnake(Snake* snake);

/// Creates a new last part of the yellow snake.
/// \param coord the coordinates of the new part.
/// \param r the radius of the new part.
/// \return a new last part of the snake.
Snake* createYellowSnake(Coord coord, int r);

/// Creates a new last part of the blue snake.
/// \param coord the coordinates of the new part.
/// \param r the radius of the new part.
/// \return a new last part of the snake.
Snake* createBlueSnake(Coord coord, int r);

/// Gets the last part of the snake.
/// \param snake the current state of the snake.
/// \return the last part of the snake.
Snake* lastPart(Snake* snake);

/// Gets a part of the yellow snake.
/// \param coord the coordinates of the part.
/// \param r the radius of the part.
/// \return A part of the snake.
GameObject getYellowPart(Coord coord, int r);

/// Gets a part of the blue snake.
/// \param coord the coordinates of the part.
/// \param r the radius of the part.
/// \return A part of the snake.
GameObject getBluePart(Coord coord, int r);

/// Makes a starting yellow snake in case of a multiplayer game.
/// \return the starting snake.
Snake* makeYellowSnake();

/// Makes a starting blue snake in case of a singleplayer game.
/// \return the starting snake.
Snake* makeBlueSnakeA();

/// Makes a starting blue snake in case of a multiplayer game.
/// \return the starting snake.
Snake* makeBlueSnakeB();

/// Updates the current state of the snake's head.
/// \param snake the current state of the snake.
/// \param dir the current direction of the snake.
void updateHead(Snake* snake, Direction dir);

/// Moves the whole snake to a direction.
/// \param snake the current state of the snake.
/// \param dir the current direction of the snake.
void moveSnake(Snake* snake, Direction dir);

/// Creates a snake using the given parameters.
/// \param snakeTrait the traits that helps create the snake.
/// \return the created snake.
Snake* createSnake(GameObject snakeTrait);

/// Frees the memory of the given snake.
/// \param snake the current snake.
void freeSnake(Snake* snake);

#endif //SNAKEGAME_SNAKE_H
