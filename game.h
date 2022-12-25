#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H
#include <stdio.h>
#include <stdbool.h>
#include "communication.h"
#include "gameUtility.h"
#define BOARD_LINE_LENGTH 6
#define X_SYMBOL 'X'
#define O_SYMBOL 'O'

typedef struct moveCoordinates {
    int x;
    int y;
} moveCoordinates;

void gameQueue();

struct moveCoordinates getPlayerMove();

void completeMove(struct moveCoordinates coordinates, int playerNumber, char *board);

bool gameContinues(gameBoard board);

bool lineWin(gameBoard board);

bool columnWin(gameBoard board);

bool diagonalWin(gameBoard board);

#endif //TIC_TAC_TOE_GAME_H