#include "communication.h"

void printGreetings() {
    char greeting[100] = "hello deer friend";
    char rules[100] = "";
    printf("%s\n", greeting);
    printf("%s", rules);
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