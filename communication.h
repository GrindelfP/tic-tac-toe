#ifndef TIC_TAC_TOE_COMMUNICATION_H
#define TIC_TAC_TOE_COMMUNICATION_H
#include <stdio.h>
#include "gameUtility.h"
#include "gameStructs.h"

void printGreetings();
void visualizeBoard(struct gameBoard board);
struct moveCoordinates getPlayerMove(int playerNumber);

#endif //TIC_TAC_TOE_COMMUNICATION_H