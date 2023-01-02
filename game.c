#include "game.h"

void gameQueue() {
    printGreetings();
    struct gameBoard board = initBoard();
    visualizeBoard(board);
    bool playerAMadeMove = false;
    player currentPlayer;
    game_stage gameStage = CONTINUES;
    while (gameStage != VICTORY && gameStage != DRAW) {
        if (playerAMadeMove) currentPlayer = PLAYER_TWO;
        else currentPlayer = PLAYER_ONE;
        struct moveCoordinates coordinates = getFinalMove(currentPlayer, board);
        board = updateBoard(board, coordinates, currentPlayer);
        printf("\nAlea iacta est!\n");
        visualizeBoard(board);
        if (playerAMadeMove) playerAMadeMove = false;
        else playerAMadeMove = true;
        gameStage = gameStageIs(board);
    }
    if (gameStage == VICTORY) printCongratulations(currentPlayer);
    if (gameStage == DRAW) printDrawMessage();
}

game_stage gameStageIs(struct gameBoard board) {
    game_stage gameStage = CONTINUES;
    if (checkForDraw(board)) gameStage = DRAW;
    if ((lineWin(board) || columnWin(board) || diagonalWin(board))) gameStage = VICTORY;

    return gameStage;
}