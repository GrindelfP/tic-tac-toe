#ifndef TIC_TAC_TOE_COMMON_UTILITY_H
#define TIC_TAC_TOE_COMMON_UTILITY_H

#include <stdio.h>
#include <stdbool.h>
#include "gameDescription.h"
#include "gameStructs.h"

#define X_SYMBOL 'X'
#define O_SYMBOL 'O'
#define MAX_COORDINATE_VALUE 2
#define MIN_COORDINATE_VALUE 0

void getPlayerInput(char *input, int inputLength);

int getRowNumber(char numberAsLetter);

char playersSymbol(int number);

bool coordinatesAreValid(struct moveCoordinates coordinates, struct gameBoard board);

#endif //TIC_TAC_TOE_COMMON_UTILITY_H