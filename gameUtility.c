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

bool lineVictory(struct gameBoard board) {
    bool gameWon = false;
    if ((board.lineOne[0] == board.lineOne[1] && board.lineOne[1] == board.lineOne[2] &&
         board.lineOne[2] != EMPTY_SYMBOL) ||
        (board.lineTwo[0] == board.lineTwo[1] && board.lineTwo[1] == board.lineTwo[2] &&
         board.lineTwo[2] != EMPTY_SYMBOL) ||
        (board.lineThree[0] == board.lineThree[1] && board.lineThree[1] == board.lineThree[2] &&
         board.lineThree[2] != EMPTY_SYMBOL))
        gameWon = true;

    return gameWon;
}

bool columnVictory(struct gameBoard board) {
    bool gameWon = false;
    for (int i = 0; i < 3; ++i) {
        if (board.lineOne[i] == board.lineTwo[i] && board.lineTwo[i] == board.lineThree[i] &&
            board.lineThree[i] != EMPTY_SYMBOL)
            gameWon = true;
    }

    return gameWon;
}

bool diagonalVictory(struct gameBoard board) {
    bool gameWon = false;
    if ((board.lineOne[0] == board.lineTwo[1] && board.lineTwo[1] == board.lineThree[2] &&
         board.lineThree[2] != EMPTY_SYMBOL) ||
        (board.lineOne[2] == board.lineTwo[1] && board.lineTwo[1] == board.lineThree[0] &&
         board.lineThree[0] != EMPTY_SYMBOL))
        gameWon = true;

    return gameWon;
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