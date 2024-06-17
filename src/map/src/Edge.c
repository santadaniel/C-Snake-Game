//
// Created by Dani on 2022. 11. 19..
//

//include my headers
#include "map/inc/Edge.h"

Coord* getMapEdge() {
    Settings settings = getSettings();
    int numberOfSquares = settings.windowHeight/settings.sizeOfSquare;
    Coord* edge = malloc(4 * numberOfSquares * sizeof (Coord));
    getTopEdge(edge, numberOfSquares);
    getBottomEdge(edge, numberOfSquares);
    getRightEdge(edge, numberOfSquares);
    getLeftEdge(edge, numberOfSquares);

    return edge;
}

void getTopEdge(Coord* edge, int numberOfSquares) {
    for (int i = 0; i < numberOfSquares; i++) {
        edge[i].x = i;
        edge[i].y = -1;
    }
}

void getBottomEdge(Coord* edge, int numberOfSquares) {
    for (int i = numberOfSquares; i < 2 * numberOfSquares; i++) {
        edge[i].x = i - numberOfSquares;
        edge[i].y = numberOfSquares;
    }
}

void getRightEdge(Coord* edge, int numberOfSquares) {
    for (int i = 2 * numberOfSquares; i < 3 * numberOfSquares; i++) {
        edge[i].x = numberOfSquares;
        edge[i].y = i - 2 * numberOfSquares;
    }
}

void getLeftEdge(Coord* edge, int numberOfSquares) {
    for (int i = 3 * numberOfSquares; i < 4 * numberOfSquares; i++) {
        edge[i].x = -1;
        edge[i].y = i - 3 * numberOfSquares;
    }
}