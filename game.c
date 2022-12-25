#include "game.h"

void gameQueue() {
    printGreetings();
    gameBoard board = initBoard();
    bool continueFlag = true;
    while (continueFlag) {
        visualizeBoard(board);
        printf("\nPlayer ONE! Make your move: ");
        moveCoordinates coordinatesA = getPlayerMove();
        updateBoard(board, coordinatesA, 0);
        visualizeBoard(board);
        printf("\nNow Player TWO! Make your move: ");
        moveCoordinates coordinatesB = getPlayerMove();
        updateBoard(board, coordinatesA, 0);
        printf("\nAlea iacta est!\n");
        continueFlag = gameContinues(board);
    }
}

void completeMove(moveCoordinates coordinates, int playerNumber, char *board) {
    int x = coordinates.x - '0' - 1, y = coordinates.y - '0' - 1;
    char playableSymbol;
    if (playerNumber == 0) playableSymbol = O_SYMBOL;
    else playableSymbol = X_SYMBOL;
    int finalCoordinate = BOARD_LINE_LENGTH * y + x;
    board[finalCoordinate] = playableSymbol;
}

moveCoordinates getPlayerMove() {
    moveCoordinates coordinates;
    char input[2];
    scanf("%s", input);
    coordinates.x = input[0] - '0';
    coordinates.y = input[1] - '0';

    return coordinates;
}

bool gameContinues(gameBoard board) {
    bool continues = true;
    // check*
    if (lineWin(board) || columnWin(board) || diagonalWin(board)) continues = false;
    return continues;
}

bool lineWin(gameBoard board) {
    bool gameWon = false;
    if ((board.lineOne[0] == board.lineOne[1] == board.lineOne[2]) ||
        (board.lineTwo[0] == board.lineTwo[1] == board.lineTwo[2]) ||
        (board.lineThree[0] == board.lineThree[1] == board.lineThree[2])) gameWon = true;
    return gameWon;
}

bool columnWin(gameBoard board) {
    bool gameWon = false;
    for (int i = 0; i < 3; ++i) {
        if (board.lineOne[i] == board.lineTwo[i] == board.lineThree[i]) gameWon = true;
    }
    return gameWon;
}

bool diagonalWin(gameBoard board) {
    bool gameWon = false;
    if ((board.lineOne[0] == board.lineTwo[1] == board.lineThree[2]) ||
        (board.lineOne[2] == board.lineTwo[1] == board.lineThree[0])) gameWon = true;
    return gameWon;
}