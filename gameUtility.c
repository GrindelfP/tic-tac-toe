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

bool lineWin(struct gameBoard board) {
    bool gameWon = false;
    if ((board.lineOne[0] == board.lineOne[1] && board.lineOne[1] == board.lineOne[2] && board.lineOne[2] != EMPTY_SYMBOL) ||
        (board.lineTwo[0] == board.lineTwo[1] && board.lineTwo[1] == board.lineTwo[2] && board.lineTwo[2] != EMPTY_SYMBOL) ||
        (board.lineThree[0] == board.lineThree[1] && board.lineThree[1] == board.lineThree[2] && board.lineThree[2] != EMPTY_SYMBOL))
        gameWon = true;

    return gameWon;
}

bool columnWin(struct gameBoard board) {
    bool gameWon = false;
    for (int i = 0; i < 3; ++i) {
        if (board.lineOne[i] == board.lineTwo[i] && board.lineTwo[i] == board.lineThree[i] && board.lineThree[i] != EMPTY_SYMBOL)
            gameWon = true;
    }

    return gameWon;
}

bool diagonalWin(struct gameBoard board) {
    bool gameWon = false;
    if ((board.lineOne[0] == board.lineTwo[1] && board.lineTwo[1] == board.lineThree[2] && board.lineThree[2] != EMPTY_SYMBOL) ||
        (board.lineOne[2] == board.lineTwo[1] && board.lineTwo[1] == board.lineThree[0] && board.lineThree[0] != EMPTY_SYMBOL))
        gameWon = true;

    return gameWon;
}

bool coordinatesAreValid(struct moveCoordinates coordinates, struct gameBoard board) {
    switch (coordinates.x) {
        case 1: if (board.lineOne[coordinates.y] == '*') return false;
        case 2: if (board.lineTwo[coordinates.y] == '*') return false;
        case 3: if (board.lineThree[coordinates.y] == '*') return false;
    }
    return true;
}