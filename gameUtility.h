#ifndef TIC_TAC_TOE_GAME_UTILITY_H
#define TIC_TAC_TOE_GAME_UTILITY_H
#include "game.h"
#define EMPTY_BOARD_LINE "***"

typedef struct gameBoard {
    char *lineOne;
    char *lineTwo;
    char *lineThree;
} gameBoard;

gameBoard initBoard();
gameBoard updateBoard(gameBoard board, moveCoordinates coordinates, int playerNumber);
char playersSymbol(int number);

#endif //TIC_TAC_TOE_GAME_UTILITY_H
