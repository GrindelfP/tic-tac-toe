#ifndef TIC_TAC_TOE_GAME_UTILITY_H
#define TIC_TAC_TOE_GAME_UTILITY_H
#include "game.h"
#include "gameStructs.h"
#define X_SYMBOL 'X'
#define O_SYMBOL 'O'
#define EMPTY_SYMBOL '*'
#define DOUBLE_MAX_COORDINATE_VALUE 4
#define DOUBLE_MIN_COORDINATE_VALUE 0

struct gameBoard initBoard();
struct gameBoard updateBoard(struct gameBoard board, struct moveCoordinates coordinates, int playerNumber);
char playersSymbol(int number);
bool lineWin(struct gameBoard board);
bool columnWin(struct gameBoard board);
bool diagonalWin(struct gameBoard board);
bool coordinatesAreValid(struct moveCoordinates coordinates, struct gameBoard board);

#endif //TIC_TAC_TOE_GAME_UTILITY_H