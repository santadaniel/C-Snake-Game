//
// Created by Dani on 2022. 11. 19..
//

#ifndef SNAKEGAME_EDGE_H
#define SNAKEGAME_EDGE_H

//include my headers
#include "map/inc/Map.h"

/// Puts the edge coordinates inside an array.
/// \return with an array of the edge coordinates.
Coord* getMapEdge();

/// Gets the Top Edge's coordinates.
/// \param edge array that contains the edges.
/// \param numberOfSquares the index of the array.
void getTopEdge(Coord* edge, int numberOfSquares);

/// Gets the Bottom Edge's coordinates.
/// \param edge edge array that contains the edges.
/// \param numberOfSquares the index of the array.
void getBottomEdge(Coord* edge, int numberOfSquares);

/// Gets the Right Edge's coordinates.
/// \param edge edge array that contains the edges.
/// \param numberOfSquares the index of the array.
void getRightEdge(Coord* edge, int numberOfSquares);

/// Gets the Left Edge's coordinates.
/// \param edge edge array that contains the edges.
/// \param numberOfSquares the index of the array.
void getLeftEdge(Coord* edge, int numberOfSquares);

#endif //SNAKEGAME_EDGE_H
