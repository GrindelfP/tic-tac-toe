#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H
#include <stdio.h>
#include <stdbool.h>
#include "communication.h"
#include "gameUtility.h"
#include "gameStructs.h"
#include "gameDescription.h"

void gameQueue();

game_stage gameStageIs(struct gameBoard board);

#endif //TIC_TAC_TOE_GAME_H