#include "communication.h"

void printGreetings() {
    char greeting[100] = "hello deer friend";
    char rules[222] = "Rules of the game: there are two players A (playing for \"O\") and B (playing for \"X\"), "
                      "\nthey take turns marking the cells on the field with their icons. "
                      "\nThe winner is the player who first puts three of his icons in a row.";
    char rulesOfInput[200] = "You have to input a couple of numbers. "
                             "\nExample: 23, where 2 is a row, 3 is a column.";
    printf("%s\n", greeting);
    printf("%s\n", rules);
    printf("%s\n", rulesOfInput);
    printf("Let us begin!");
}

void visualizeBoard(struct gameBoard board) {
    int i, j;
    char *boardLine = board.lineOne;
    for (j = 0; j < 3; ++j) {
        printf("\n");
        for (i = 0; i < 3; ++i) {
            printf("%c", boardLine[i]);
            if (i != 2) printf(" ");
        }
        if (j == 0) boardLine = board.lineTwo;
        if (j == 1) boardLine = board.lineThree;
    }
}

struct moveCoordinates getPlayerMove(int playerNumber) {
    if (playerNumber == 0) printf("\nPlayer ONE! Make your move: ");
    else printf("\nPlayer TWO! Make your move: ");
    struct moveCoordinates coordinates;
    char input[2];
    scanf("%s", input);
    coordinates.y = input[0] - '0' - 1;
    coordinates.x = input[1] - '0' - 1;

    return coordinates;
}

void printCongratulations(int playerNumber) {
    char player;
    player = playerNumber == 0 ? 'A' : 'B';
    printf("\nCongratulations, player %c, you've won this game! \nGood bye!", player);
}

// for further localisation:
//Правила игры:\nЕсть два игрока A(играет за "0") и B