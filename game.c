#include "game.h"

void gameQueue() {
    printGreetings();
    struct gameBoard board = initBoard();
    bool playerAMadeMove = false;
    int playerNumber;
    while (gameContinues(board)) {
        if (playerAMadeMove) playerNumber = 1; // 0 is for A player, 1 - for B
        else playerNumber = 0;
        visualizeBoard(board);
        struct moveCoordinates coordinates;
        while (true) {
            coordinates = getPlayerMove(playerNumber);
            if (coordinatesAreValid(coordinates, board)) break;
        }
        board = updateBoard(board, coordinates, playerNumber);
        printf("\nAlea iacta est!\n");
        if (playerAMadeMove) playerAMadeMove = false;
        else playerAMadeMove = true;
    }
}

bool gameContinues(struct gameBoard board) {
    bool continues = true;
    if ((lineWin(board) || columnWin(board) || diagonalWin(board))) continues = false;

    return continues;
}