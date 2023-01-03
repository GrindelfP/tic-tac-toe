#ifndef TIC_TAC_TOE_GAME_UTILITY_H
#define TIC_TAC_TOE_GAME_UTILITY_H

#include "game.h"
#include "gameStructs.h"

#define EMPTY_SYMBOL '*'

struct gameBoard initBoard();

struct gameBoard updateBoard(struct gameBoard board, struct moveCoordinates coordinates, int currentPlayer);

bool lineVictory(struct gameBoard board);

bool columnVictory(struct gameBoard board);

bool diagonalVictory(struct gameBoard board);

bool checkForDraw(struct gameBoard board);

#endif //TIC_TAC_TOE_GAME_UTILITY_H