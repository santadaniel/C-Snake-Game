#include "stdbool.h"

//include my headers
#include "map/inc/Map.h"
#include "eventhandler/inc/EventHandler.h"
#include "gamestate/inc/GameState.h"
#include "gamestate/inc/End.h"
#include "menu/inc/File.h"

int main(int argc, char** argv) {
    FILE* file = fopen("LeaderBoard.txt", "r+");
    LeaderBoard leaderBoard = readFromFile(file);

    SDL_TimerID timeID = SDL_AddTimer(100,drawCallback, NULL);

    Controller controller = createController();

    bool isRunning = true;
    GameState game;
    game.currentStage = MENU;

    while (isRunning) {
        SDL_Event event;
        SDL_WaitEvent(&event);
        switch (game.currentStage) {
            case MENU:
                leaderBoard.isPressed = false;
                createMenu(controller);
                menuStartGame(&game);
                startLeaderBoard(&game.currentStage);
                if (event.type == SDL_QUIT || menuEndGame())
                    isRunning = false;
                break;
            case LEADERBOARD:
                openLeaderBoard(controller, &game, leaderBoard);
                if (event.type == SDL_QUIT){
                    freeGame(&game);
                    isRunning = false;
                }
                break;
            case PLAY:
                keyboardEvent(&game);
                if (event.type == SDL_USEREVENT)
                    caseUserEvent(controller, &game);
                if (event.type == SDL_QUIT){
                    freeGame(&game);
                    isRunning = false;
                }
                break;
            case END:
                caseOfEnding(controller, &game, &leaderBoard);
                if (event.type == SDL_QUIT) {
                    freeGame(&game);
                    isRunning = false;
                }
                break;
            default:
                freeGame(&game);
                isRunning = false;
                break;
        }
    }

    fclose(file);
    fclose(fopen("LeaderBoard.txt", "w"));

    file = fopen("LeaderBoard.txt", "r+");
    writeToFile(leaderBoard, file);
    fclose(file);

    SDL_RemoveTimer(timeID);
    destroyController(controller);

    return 0;
}
