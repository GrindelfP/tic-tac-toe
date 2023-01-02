#ifndef TIC_TAC_TOE_COMMUNICATION_H
#define TIC_TAC_TOE_COMMUNICATION_H
#include <stdio.h>
#include "gameUtility.h"
#include "gameStructs.h"
#define EMPTY_LINE printf("\n")
#define COORDINATES_INPUT_LENGTH 2

void printGreetings();

void visualizeBoard(struct gameBoard board);

struct moveCoordinates getFinalMove(int playerNumber, struct gameBoard board);

struct moveCoordinates getPlayerMove(int playerNumber);

void printCongratulations(int playerNumber);

void printDrawMessage();

#endif //TIC_TAC_TOE_COMMUNICATION_H