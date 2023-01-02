#include "game.h"

void gameQueue() {
    printGreetings();
    struct gameBoard board = initBoard();
    visualizeBoard(board);
    bool playerOneMadeMove = false;
    player currentPlayer;
    game_stage gameStage = CONTINUES;
    while (gameStage == CONTINUES) {
        if (playerOneMadeMove) currentPlayer = PLAYER_TWO;
        else currentPlayer = PLAYER_ONE;
        struct moveCoordinates coordinates = getFinalMove(currentPlayer, board);
        board = updateBoard(board, coordinates, currentPlayer);
        printf("\nAlea iacta est!\n");
        visualizeBoard(board);
        if (playerOneMadeMove) playerOneMadeMove = false;
        else playerOneMadeMove = true;
        gameStage = gameStageIs(board);
    }
    if (gameStage == VICTORY) printCongratulations(currentPlayer);
    if (gameStage == DRAW) printDrawMessage();
}

game_stage gameStageIs(struct gameBoard board) {
    game_stage gameStage = CONTINUES;
    if (checkForDraw(board)) gameStage = DRAW;
    if ((lineVictory(board) || columnVictory(board) || diagonalVictory(board))) gameStage = VICTORY;

    return gameStage;
}