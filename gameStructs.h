#ifndef TIC_TAC_TOE_GAME_STRUCTS_H
#define TIC_TAC_TOE_GAME_STRUCTS_H

struct moveCoordinates {
    int x;
    int y;
};

struct gameBoard {
    char *lineOne;
    char *lineTwo;
    char *lineThree;
};

#endif //TIC_TAC_TOE_GAME_STRUCTS_H