#include "commonUtility.h"

void getPlayerInput(char *input, int inputLength) {
    scanf("%2s", input);
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int getRowNumber(char numberAsLetter) {
    int rowNumber;
    if (numberAsLetter == 'a' || numberAsLetter == 'A') rowNumber = 0;
    else if (numberAsLetter == 'b' || numberAsLetter == 'B') rowNumber = 1;
    else if (numberAsLetter == 'c' || numberAsLetter == 'C') rowNumber = 2;
    else rowNumber = -1;

    return rowNumber;
}
char playersSymbol(player currentPlayer) {
    char symbol;
    if (currentPlayer == 0) symbol = O_SYMBOL;
    else symbol = X_SYMBOL;

    return symbol;
}

bool coordinatesAreValid(struct moveCoordinates coordinates, struct gameBoard board) {
    bool validness = false;
    if (coordinates.x >= MIN_COORDINATE_VALUE && coordinates.y >= MIN_COORDINATE_VALUE &&
        coordinates.x <= MAX_COORDINATE_VALUE && coordinates.y <= MAX_COORDINATE_VALUE) {
        switch (coordinates.y) {
            case 0:
                if (board.lineOne[coordinates.x] == '*') validness = true;
                break;
            case 1:
                if (board.lineTwo[coordinates.x] == '*') validness = true;
                break;
            default:
                if (board.lineThree[coordinates.x] == '*') validness = true;
                break;
        }
    }
    return validness;
}