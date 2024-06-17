//
// Created by Dani on 2022. 11. 03..
//

//include my headers
#include "map/inc/Map.h"

void growSnake(Snake* snake) {
    Snake* last = lastPart(snake);
    int newRadius = last->snakeTrait.r;
    if(last->snakeTrait.r > 15)
        newRadius = last->snakeTrait.r - 1;
    if(snake->snakeTrait.color.b != 0)
        last->next = createBlueSnake(last->snakeTrait.coord, newRadius);
    else
        last->next = createYellowSnake(last->snakeTrait.coord, newRadius);
    snake->length++;
}

Snake* createYellowSnake(Coord coord, int r) {
    Snake* newPart = (Snake*) malloc(sizeof (Snake));
    newPart->snakeTrait = getYellowPart(coord, r);
    newPart->next = NULL;
    return newPart;
}

Snake* createBlueSnake(Coord coord, int r) {
    Snake* newPart = (Snake*) malloc(sizeof (Snake));
    newPart->snakeTrait = getBluePart(coord, r);
    newPart->next = NULL;
    return newPart;
}

Snake* lastPart(Snake* snake) {
    for (Snake* i = snake; i != NULL; i = i->next) {
        if (i->next == NULL)
            return i;
    }
    return NULL;
}

Snake* makeYellowSnake() {
    Coord coordHead = {9, 3};
    int radiusHead = getSettings().sizeOfSquare / 2 - 3;
    Snake* yellowSnake = createSnake(getYellowPart(coordHead, radiusHead));

    return yellowSnake;
}

Snake* makeBlueSnakeA() {
    Coord coordHead = {6, 7};
    int radiusHead = getSettings().sizeOfSquare / 2 - 3;
    Snake* blueSnake = createSnake(getBluePart(coordHead, radiusHead));

    return blueSnake;
}

Snake* makeBlueSnakeB() {
    Coord coordHead = {9, 11};
    int radiusHead = getSettings().sizeOfSquare / 2 - 3;
    Snake* blueSnake = createSnake(getBluePart(coordHead, radiusHead));

    return blueSnake;
}

GameObject getYellowPart(Coord coord, int r) {
    return createGameObject(r, coord, getColorYellow());
}

GameObject getBluePart(Coord coord, int r) {
    return createGameObject(r, coord, getColorBlue());
}

void updateHead(Snake* snake, Direction dir) {
    if (dir == LEFT)
        snake->snakeTrait.coord.x--;
    if (dir == RIGHT)
        snake->snakeTrait.coord.x++;
    if (dir == UP)
        snake->snakeTrait.coord.y--;
    if (dir == DOWN)
         snake->snakeTrait.coord.y++;
}

void moveSnake(Snake* snake, Direction dir) {
    Coord prevCoord = snake->snakeTrait.coord;
    Snake* current = snake->next;

    while (current != NULL) {
        Coord temp = current->snakeTrait.coord;
        current->snakeTrait.coord = prevCoord;
        prevCoord = temp;
        current = current->next;
    }
    updateHead(snake, dir);
}

Snake* createSnake(GameObject snakeTrait) {
    Snake* snakeHead = (Snake*) malloc(sizeof (Snake));
    snakeHead->snakeTrait = snakeTrait;
    snakeHead->isAlive = true;
    snakeHead->length = 3;

    Snake* snakeBody = (Snake*) malloc(sizeof (Snake));
    snakeBody->snakeTrait = snakeHead->snakeTrait;
    snakeBody->snakeTrait.coord.x = snakeHead->snakeTrait.coord.x + 1;
    snakeBody->snakeTrait.r = snakeHead->snakeTrait.r - 1;

    Snake* snakeTail = (Snake*) malloc(sizeof (Snake));
    snakeTail->snakeTrait = snakeBody->snakeTrait;
    snakeTail->snakeTrait.coord.x = snakeBody->snakeTrait.coord.x + 1;
    snakeTail->snakeTrait.r = snakeBody->snakeTrait.r - 1;

    snakeHead->next = snakeBody;
    snakeBody->next = snakeTail;
    snakeTail->next = NULL;

    return snakeHead;
}

void freeSnake(Snake* snake) {
    Snake *temp;
    while (snake != NULL) {
        temp = snake;
        snake = snake->next;
        free(temp);
    }
}