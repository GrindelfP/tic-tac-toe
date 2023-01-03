#include "communication.h"

void printGreetings() {
    char greeting[100] = "hello deer friend";
    char rules[223] = "Rules of the game: there are two players A (playing with \"O\") and B (playing with \"X\"). "
                      "\nThey take turns marking the cells on the field with their icons. "
                      "\nThe winner is the player who first puts three of his icons in a row.";
    char rulesOfInput[300] = "You have to input a coordinate for yor move in similar form: letter, number "
                             "\nwith no spaces or another dividers between them."
                             "\nExample: b3 (or B3), where b (or B) is a row number 2 and 3 is a column."
                             "\nIf you will put incorrect coordinates you will be warned about that and"
                             "\nasked to remake your move.";

    printf("%s\n", greeting);
    printf("%s\n", rules);
    printf("%s\n", rulesOfInput);
    printf("Let us begin!");
}

void visualizeBoard(struct gameBoard board) {
    EMPTY_LINE;
    int i, j;
    char *boardLine = board.lineOne;
    for (j = 0; j < 3; ++j) {
        EMPTY_LINE;
        for (i = 0; i < 3; ++i) {
            printf("%c", boardLine[i]);
            if (i != 2) printf(" ");
        }
        if (j == 0) boardLine = board.lineTwo;
        if (j == 1) boardLine = board.lineThree;
    }
    EMPTY_LINE;
}

struct moveCoordinates getFinalMove(int playerNumber, struct gameBoard board) {
    struct moveCoordinates coordinates = getPlayerMove(playerNumber);
    while (!coordinatesAreValid(coordinates, board)) {
        printf("Coordinates you've entered are not correct");
        coordinates = getPlayerMove(playerNumber);
    }

    return coordinates;
}

struct moveCoordinates getPlayerMove(int playerNumber) {
    if (playerNumber == 0) printf("\nPlayer ONE! Make your move: ");
    else printf("\nPlayer TWO! Make your move: ");
    struct moveCoordinates coordinates;
    char input[COORDINATES_INPUT_LENGTH];
    getPlayerInput(input, COORDINATES_INPUT_LENGTH);
    coordinates.y = getRowNumber(input[0]);
    coordinates.x = input[1] - '0' - 1;

    return coordinates;
}

void printCongratulations(player currentPlayer) {
    char playerName = currentPlayer == 0 ? 'A' : 'B';
    printf("\nCongratulations, player %c, you've won this game! \nGood bye!", playerName);
}

void printDrawMessage() {
    printf("\nYour game ended in a draw... \nMaybe, someone will be luckier next time... Good bye!\n");
}

// for further localisation:
//Правила игры:\nЕсть два игрока A(играет за "0") и B