#ifndef TIC_TAC_TOE_GAME_STRUCTS_H
#define TIC_TAC_TOE_GAME_STRUCTS_H

struct moveCoordinates {
    int x;
    int y;
};

struct gameBoard {
    char lineOne[3];
    char lineTwo[3];
    char lineThree[3];
};

#endif //TIC_TAC_TOE_GAME_STRUCTS_H