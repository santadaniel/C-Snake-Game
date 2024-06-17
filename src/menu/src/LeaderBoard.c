//
// Created by Dani on 2022. 11. 26..
//

#include "menu/inc/LeaderBoard.h"
#include "gamestate/inc/End.h"

bool input_text(char *dest, size_t hossz, SDL_Rect teglalap, SDL_Color hatter, SDL_Color szoveg, TTF_Font *font, SDL_Renderer *renderer) {
    /* Ez tartalmazza az aktualis szerkesztest */
    char composition[SDL_TEXTEDITINGEVENT_TEXT_SIZE];
    composition[0] = '\0';
    /* Ezt a kirajzolas kozben hasznaljuk */
    char textandcomposition[hossz + SDL_TEXTEDITINGEVENT_TEXT_SIZE + 1];
    /* Max hasznalhato szelesseg */
    int maxw = teglalap.w - 2;
    int maxh = teglalap.h - 2;

    dest[0] = '\0';

    bool enter = false;
    bool kilep = false;

    SDL_StartTextInput();
    while (!kilep && !enter) {
        /* doboz kirajzolasa */
        boxRGBA(renderer, teglalap.x, teglalap.y, teglalap.x + teglalap.w - 1, teglalap.y + teglalap.h - 1, hatter.r, hatter.g, hatter.b, 255);
        rectangleRGBA(renderer, teglalap.x, teglalap.y, teglalap.x + teglalap.w - 1, teglalap.y + teglalap.h - 1, szoveg.r, szoveg.g, szoveg.b, 255);
        /* szoveg kirajzolasa */
        int w;
        strcpy(textandcomposition, dest);
        strcat(textandcomposition, composition);
        if (textandcomposition[0] != '\0') {
            SDL_Surface *felirat = TTF_RenderUTF8_Blended(font, textandcomposition, szoveg);
            SDL_Texture *felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
            SDL_Rect cel = { teglalap.x, teglalap.y, felirat->w < maxw ? felirat->w : maxw, felirat->h < maxh ? felirat->h : maxh };
            SDL_RenderCopy(renderer, felirat_t, NULL, &cel);
            SDL_FreeSurface(felirat);
            SDL_DestroyTexture(felirat_t);
            w = cel.w;
        } else {
            w = 0;
        }
        /* kurzor kirajzolasa */
        if (w < maxw) {
            vlineRGBA(renderer, teglalap.x + w + 2, teglalap.y + 2, teglalap.y + teglalap.h - 3, szoveg.r, szoveg.g, szoveg.b, 192);
        }
        /* megjeleniti a képernyon az eddig rajzoltakat */
        SDL_RenderPresent(renderer);

        SDL_Event event;
        SDL_WaitEvent(&event);
        switch (event.type) {
            /* Kulonleges karakter */
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    int textlen = strlen(dest);
                    do {
                        if (textlen == 0) {
                            break;
                        }
                        if ((dest[textlen-1] & 0x80) == 0x00)   {
                            /* Egy bajt */
                            dest[textlen-1] = 0x00;
                            break;
                        }
                        if ((dest[textlen-1] & 0xC0) == 0x80) {
                            /* Bajt, egy tobb-bajtos szekvenciabol */
                            dest[textlen-1] = 0x00;
                            textlen--;
                        }
                        if ((dest[textlen-1] & 0xC0) == 0xC0) {
                            /* Egy tobb-bajtos szekvencia elso bajtja */
                            dest[textlen-1] = 0x00;
                            break;
                        }
                    } while(true);
                }
                if (event.key.keysym.sym == SDLK_RETURN) {
                    enter = true;
                }
                break;

                /* A feldolgozott szoveg bemenete */
            case SDL_TEXTINPUT:
                if (strlen(dest) + strlen(event.text.text) < hossz) {
                    strcat(dest, event.text.text);
                }

                /* Az eddigi szerkesztes torolheto */
                composition[0] = '\0';
                break;

                /* Szoveg szerkesztese */
            case SDL_TEXTEDITING:
                strcpy(composition, event.edit.text);
                break;

            case SDL_QUIT:
                /* visszatesszuk a sorba ezt az eventet, mert
                 * sok mindent nem tudunk vele kezdeni */
                SDL_PushEvent(&event);
                kilep = true;
                break;
        }
    }

    /* igaz jelzi a helyes beolvasast; = ha enter miatt allt meg a ciklus */
    SDL_StopTextInput();
    return enter;
}

void startLeaderBoard(Stage* stage) {
    int x, y;
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    if (buttons == SDL_BUTTON_LEFT)
        if (200 <= x && x <= 550) {
            if (475 <= y && y <= 560) {
                *stage = LEADERBOARD;
            }
        }
}

void putIndexOnLeaderBoard(Controller controller, int i) {
    char index[3 + 1];
    if (i+1 != 10) {
        sprintf(index, " %d.", i + 1);
    }
    else {
        sprintf(index, "%d.", i + 1);
    }
    Text text = {
        (SDL_Rect) {150, (i) * 50 + 50, 25, 25},
        index,
        (SDL_Color) {255, 255, 255, 255}
    };
    createText(text, controller);
}

void putScoreOnLeaderBoard(Controller controller, int score, int i) {
    char scoreStr[5 + 1];
    sprintf(scoreStr, "%d", score);
    char dest[5 + 1] = {' ', ' ', ' ', ' ', ' ', '\0'};
    int difference = strlen(dest) - strlen(scoreStr);
    for (int j = difference; j < strlen(dest); ++j) {
        dest[j] = scoreStr[j - difference];
    }
    Text text = {
            (SDL_Rect) {500, (i) * 50 + 50, 100, 25},
            dest,
            (SDL_Color) {255, 255, 255, 255}
    };
    createText(text, controller);
}

void putNameOnLeaderBoard(Controller controller, char* name, int i) {
    char dest[20 + 1];
    strcat(dest, name);
    for (int j = 0; j < 20-strlen(name); ++j) {
        strcat(dest, " ");
    }
    Text text = {
            (SDL_Rect) {200, (i) * 50 + 50, 200, 25},
            dest,
            (SDL_Color) {255, 255, 255, 255}
    };
    createText(text, controller);
}

void putPlayerOnLeaderBoard(Controller controller, LeaderBoard leaderBoard, int i) {
    putIndexOnLeaderBoard(controller, i);
    putNameOnLeaderBoard(controller, leaderBoard.playerData[i].name, i);
    putScoreOnLeaderBoard(controller, leaderBoard.playerData[i].score, i);
}

void openLeaderBoard(Controller controller, GameState* game, LeaderBoard leaderBoard) {
    drawMenuBackGround(controller);
    Text text;
    text.color = (SDL_Color) {255, 255, 255, 255};
    SDL_SetRenderDrawColor(controller.renderer ,255,255,255, 255);
    for (int i = 0; i < 10; ++i) {
        if (leaderBoard.playerData[i].score != -1) {
            SDL_RenderDrawLine(controller.renderer, 190, (i) * 50 + 72, 600, (i) * 50 + 72);
            putPlayerOnLeaderBoard(controller, leaderBoard, i);
        }
    }
    backToMenu(controller, game);
    SDL_RenderPresent(controller.renderer);
}

void checkLeaderBoard(Controller controller, GameState* game, LeaderBoard* leaderBoard) {
    Text text;
    text.color = (SDL_Color) {255, 255, 255, 255};
    text.rect = (SDL_Rect) {175, 150, 400, 50};
    int playerScore = game->players->snake->length * 100 - 300;
    if (playerScore > leaderBoard->playerData[10 - 1].score && playerScore != 0) {
        int placing = placingOnLeaderBoard(leaderBoard, playerScore);
        refactorLeaderBoard(leaderBoard, placing);
        text.sentence = "Enter you name (max 20 char.)";
        leaderBoard->playerData[placing].score = playerScore;
        createText(text, controller);
        input_text(
        leaderBoard->playerData[placing].name,
        20,
        (SDL_Rect) {225, 250, 300, 75},
        (SDL_Color) {0, 0, 0, 255},
        (SDL_Color) {255, 255, 255, 255},
        controller.font,
        controller.renderer
        );
    }
    else {
        text.sentence = "You did not make it";
        createText(text, controller);
    }
    SDL_RenderPresent(controller.renderer);
}

void refactorLeaderBoard(LeaderBoard* leaderBoard, int placing) {
    PlayerData current = leaderBoard->playerData[placing];
    for (int i = placing; i < 10 - 1; ++i) {
        PlayerData temp = leaderBoard->playerData[i + 1];
        leaderBoard->playerData[i + 1] = current;
        current = temp;
    }
}

int placingOnLeaderBoard(LeaderBoard* leaderBoard, int score) {
    for (int i = 0; i < 10; ++i) {
        if (score > leaderBoard->playerData[i].score) {
            return i;
        }
    }
}
