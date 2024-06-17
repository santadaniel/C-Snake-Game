//
// Created by Dani on 2022. 11. 27..
//

#include "menu/inc/File.h"
#include "gamestate/inc/End.h"

LeaderBoard readFromFile(FILE* file) {
    if (file == NULL) {
        printf("File cannot be opened.");
        exit(1);
    }

    int i = 0;
    LeaderBoard leaderBoard;

    while (fscanf(file, "%s %d", leaderBoard.playerData[i].name, &leaderBoard.playerData[i].score) == 2) {
        i++;
    }
    for (int j = i; j < 10; ++j) {
        leaderBoard.playerData[j] = toPlayerData("", -1);
    }

    return leaderBoard;
}

void writeToFile(LeaderBoard leaderBoard, FILE* file) {
    for (int j = 0; j < 10; ++j) {
        fprintf(file, "%s %d\n", leaderBoard.playerData[j].name, leaderBoard.playerData[j].score);
    }
}