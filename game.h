#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H
#include <stdio.h>
#include <stdbool.h>
#include "communication.h"
#define EMPTY_BOARD "\n* * *\n* * *\n* * *"
#define BOARD_LINE_LENGTH 6
#define X_SYMBOL 'X'
#define O_SYMBOL 'O'

struct moveCoordinates {
    char x;
    char y;
};

void gameQueue();

struct moveCoordinates getPlayerMove();

void completeMove(struct moveCoordinates coordinates, int playerNumber, char *board);

bool gameContinues(const char board[]);

bool lineWin(const char *board);

bool columnWin(const char *board);

bool diagonalWin(const char *board);

#endif //TIC_TAC_TOE_GAME_H