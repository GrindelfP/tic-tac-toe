#include "gameUtility.h"

struct gameBoard initBoard() {
    struct gameBoard board;
    for (int i = 0; i < 3; ++i) {
        board.lineOne[i] = EMPTY_SYMBOL;
        board.lineTwo[i] = EMPTY_SYMBOL;
        board.lineThree[i] = EMPTY_SYMBOL;
    }

    return board;
}

struct gameBoard updateBoard(struct gameBoard board, struct moveCoordinates coordinates, int playerNumber) {
    if (coordinates.y == 0) board.lineOne[coordinates.x] = playersSymbol(playerNumber);
    else if (coordinates.y == 1) board.lineTwo[coordinates.x] = playersSymbol(playerNumber);
    else board.lineThree[coordinates.x] = playersSymbol(playerNumber);

    return board;
}

char playersSymbol(int number) {
    char symbol;
    if (number == 0) symbol = O_SYMBOL;
    else symbol = X_SYMBOL;

    return symbol;
}