#include "game.h"

void gameQueue() {
    printGreetings();
    struct gameBoard board = initBoard();
    while (gameContinues(board)) {
        visualizeBoard(board);
        printf("\nPlayer ONE! Make your move: ");
        struct moveCoordinates coordinatesA = getPlayerMove();
        updateBoard(board, coordinatesA, 0);
        visualizeBoard(board);
        printf("\nNow, Player TWO! Make your move: ");
        struct moveCoordinates coordinatesB = getPlayerMove();
        updateBoard(board, coordinatesB, 1);
        printf("\nAlea iacta est!\n");
    }
}

struct moveCoordinates getPlayerMove() {
    struct moveCoordinates coordinates;
    char input[2];
    scanf("%s", input);
    coordinates.x = input[0] - '0' - 1;
    coordinates.y = input[1] - '0' - 1;

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