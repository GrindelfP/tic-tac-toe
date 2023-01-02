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

struct gameBoard updateBoard(struct gameBoard board, struct moveCoordinates coordinates, player currentPlayer) {
    if (coordinates.y == 0) board.lineOne[coordinates.x] = playersSymbol(currentPlayer);
    else if (coordinates.y == 1) board.lineTwo[coordinates.x] = playersSymbol(currentPlayer);
    else board.lineThree[coordinates.x] = playersSymbol(currentPlayer);

    return board;
}

char playersSymbol(player currentPlayer) {
    char symbol;
    if (currentPlayer == 0) symbol = O_SYMBOL;
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
    bool validness = false;
    if (coordinates.x >= MIN_COORDINATE_VALUE && coordinates.y >= MIN_COORDINATE_VALUE &&
        coordinates.x <= MAX_COORDINATE_VALUE && coordinates.y <= MAX_COORDINATE_VALUE) {
        switch (coordinates.y) {
            case 0:
                if (board.lineOne[coordinates.x] == '*') validness = true;
                break;
            case 1:
                if (board.lineTwo[coordinates.x] == '*') validness = true;
                break;
            default:
                if (board.lineThree[coordinates.x] == '*') validness = true;
                break;
        }
    }
    return validness;
}

bool checkForDraw(struct gameBoard board) {
    bool draw = true;
    for (int i = 0; i < 3; ++i) {
        if (board.lineOne[i] == '*' || board.lineTwo[i] == '*' || board.lineThree[i] == '*') {
            draw = false;
            break;
        }
    }

    return draw;
}