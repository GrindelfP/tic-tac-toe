#include "game.h"

void gameQueue() {
    printGreetings();
    char board[18] = EMPTY_BOARD;
    while (gameContinues(board)) {
        printf("");
        printf("%s", board);
        printf("\nPlayer ONE! Make your move: ");
        struct moveCoordinates coordinatesA = getPlayerMove();
        completeMove(coordinatesA, 0, board);
        printf("\nNow Player TWO! Make your move: ");
        struct moveCoordinates coordinatesB = getPlayerMove();
        completeMove(coordinatesB, 1, board);
        printf("\nAlea iacta est!\n");
    }
}

void completeMove(struct moveCoordinates coordinates, int playerNumber, char *board) {
    int x = coordinates.x - '0' - 1, y = coordinates.y - '0' - 1;
    char playableSymbol;
    if (playerNumber == 0) playableSymbol = O_SYMBOL;
    else playableSymbol = X_SYMBOL;
    int finalCoordinate = BOARD_LINE_LENGTH * y + x;
    board[finalCoordinate] = playableSymbol;
}

struct moveCoordinates getPlayerMove() {
    struct moveCoordinates coordinates;
    char input[2];
    scanf("%s", input);
    coordinates.x = input[0];
    coordinates.y = input[1];

    return coordinates;
}


bool gameContinues(const char *board) {
    bool continues = false;
    if (lineWin(board) || columnWin(board) || diagonalWin(board)) continues = true;
    return continues;
}

bool lineWin(const char *board) {
    bool gameWon = false;
    for (int i = 1; i < 18; i += 6) {
        if (board[i] == board[i + 3] == board[i + 5]) gameWon = true;
    }
    return gameWon;
}

bool columnWin(const char *board) {
    bool gameWon = false;
    for (int i = 1; i < 4; ++i) {
        if (board[i] == board[i + 6] == board[i + 12]) gameWon = true;
    }
    return gameWon;
}

bool diagonalWin(const char *board) {
    bool gameWon = false;
    if ((board[1] == board[9] == board[17]) || (board[6] == board[9] == board[13])) gameWon = true;
    return gameWon;
}
