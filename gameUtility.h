#ifndef TIC_TAC_TOE_GAME_UTILITY_H
#define TIC_TAC_TOE_GAME_UTILITY_H
#include "game.h"
#include "gameStructs.h"
#define X_SYMBOL 'X'
#define O_SYMBOL 'O'
#define EMPTY_SYMBOL '*'

struct gameBoard initBoard();
struct gameBoard updateBoard(struct gameBoard board, struct moveCoordinates coordinates, int playerNumber);
char playersSymbol(int number);
bool lineWin(struct gameBoard board);
bool columnWin(struct gameBoard board);
bool diagonalWin(struct gameBoard board);
bool coordinatesAreValid(struct moveCoordinates coordinates, struct gameBoard board);

#endif //TIC_TAC_TOE_GAME_UTILITY_H