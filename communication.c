#include "communication.h"

void printGreetings() {
    char greeting[100] = "hello deer friend";
    char rules[220] = "Rules of the game: there are two players A (playing for \"O\") and B (playing for \"X\"), "
                      "they take turns marking the cells on the field with their icons. "
                      "The winner is the player who first puts three of his icons in a row.";
    char rulesOfInput[200] = "You have to input a couple of numbers. "
                             "Example 23, where 2 is a row, 3 is a column.";
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
void gameRules(){

}
//Правила игры:\nЕсть два игрока A(играет за "0") и B