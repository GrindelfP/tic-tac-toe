#include "game.h"

void gameQueue() {
    printGreetings();
    struct gameBoard board = initBoard();
    bool playerAMadeMove = false;
    int playerNumber;
    while (gameContinues(board)) {
        visualizeBoard(board);
        //add next message to getPlayerMove
        printf("\nPlayer ONE! Make your move: ");
        struct moveCoordinates coordinatesA = getPlayerMove();
        if (playerAMadeMove) playerNumber = 1; // 0 is for A player, 1 - for B
        else playerNumber = 0;
        board = updateBoard(board, coordinatesA, playerNumber);
        printf("\nAlea iacta est!\n");
        if (playerAMadeMove) playerAMadeMove = false;
        else playerAMadeMove = true;
    }
}

struct moveCoordinates getPlayerMove() {
    struct moveCoordinates coordinates;
    char input[2];
    scanf("%s", input);
    coordinates.y = input[0] - '0' - 1;
    coordinates.x = input[1] - '0' - 1;

    return coordinates;
}

bool gameContinues(struct gameBoard board) {
    bool continues = true;
    if ((lineWin(board) || columnWin(board) || diagonalWin(board))) continues = false;

    return continues;
}

bool lineWin(struct gameBoard board) {
    bool gameWon = false;
    if ((board.lineOne[0] == board.lineOne[1] == board.lineOne[2] && board.lineOne[2] != EMPTY_SYMBOL) ||
        (board.lineTwo[0] == board.lineTwo[1] == board.lineTwo[2] && board.lineTwo[2] != EMPTY_SYMBOL) ||
        (board.lineThree[0] == board.lineThree[1] == board.lineThree[2] && board.lineThree[2] != EMPTY_SYMBOL))
        gameWon = true;

    return gameWon;
}

bool columnWin(struct gameBoard board) {
    bool gameWon = false;
    for (int i = 0; i < 3; ++i) {
        if (board.lineOne[i] == board.lineTwo[i] == board.lineThree[i] && board.lineThree[i] != EMPTY_SYMBOL)
            gameWon = true;
    }

    return gameWon;
}

bool diagonalWin(struct gameBoard board) {
    bool gameWon = false;
    if ((board.lineOne[0] == board.lineTwo[1] == board.lineThree[2] && board.lineThree[2] != EMPTY_SYMBOL) ||
        (board.lineOne[2] == board.lineTwo[1] == board.lineThree[0] && board.lineThree[0] != EMPTY_SYMBOL))
        gameWon = true;

    return gameWon;
}