//
// Created by Dani on 2022. 11. 27..
//

#ifndef SNAKEGAME_FILE_H
#define SNAKEGAME_FILE_H

#include "stdio.h"
#include "LeaderBoard.h"

/// Reads the datas from the file to a leaderboard.
/// \param file LeaderBoard.txt
/// \return with a Leaderboard that gets its data from the file.
LeaderBoard readFromFile(FILE* file);

/// Writes the datas from the current leaderboard to the file.
/// \param leaderBoard the current leaderboard.
/// \param file LeaderBoard.txt
void writeToFile(LeaderBoard leaderBoard, FILE* file);

#endif //SNAKEGAME_FILE_H
