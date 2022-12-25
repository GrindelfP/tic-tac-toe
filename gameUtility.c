#include "gameUtility.h"

gameBoard initBoard() {
    gameBoard board;
    board.lineOne = EMPTY_BOARD_LINE;
    board.lineTwo = EMPTY_BOARD_LINE;
    board.lineThree = EMPTY_BOARD_LINE;

    return board;
}

gameBoard updateBoard(gameBoard board, moveCoordinates coordinates, int playerNumber) {
    if (coordinates.y == 1) board.lineOne[coordinates.x] = playersSymbol(playerNumber);
    else if (coordinates.y == 2) board.lineTwo[coordinates.x] = playersSymbol(playerNumber);
    else board.lineThree[coordinates.x] = playersSymbol(playerNumber);

    return board;
}

char playersSymbol(int number) {
    char symbol;
    if (number == 0) symbol = O_SYMBOL;
    else symbol = X_SYMBOL;

    return symbol;
}
