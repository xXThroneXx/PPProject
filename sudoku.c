

/* * This is a sudoku cl game, where one can place his inputs and the computer will check them and tell when one is finished
	*@author Mohammad Sadegh Solimany
	*@version 1.0
*/

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>


// some needed variables for the main()
int input, row, column;
bool gameRunning, isInputValid, rulesRespected,initialFieldsCheck,setAllowed;
// defining & initializing a 2D static array which represents the game board
int board[9][9] = {{4, 1, 0, 0, 6, 5, 0, 0, 7},
                   {0, 0, 6, 0, 0, 7, 4, 8, 0},
                   {2, 0, 7, 4, 9, 0, 0, 0, 6},
                   {0, 6, 0, 0, 7, 0, 1, 0, 0},
                   {3, 0, 1, 5, 0, 0, 0, 7, 2},
                   {0, 9, 0, 0, 4, 2, 3, 0, 8},
                   {1, 0, 8, 6, 0, 0, 0, 2, 9},
                   {0, 2, 0, 0, 1, 8, 6, 4, 0},
                   {6, 0, 0, 3, 0, 0, 0, 1, 0}
};

// here we save all the zeros from the original board to distinguish whether a field is editable or not
int boardInitialFields[9][9];

// iterate through board and mark all fields where we have a zero
void initializeBoard() {

    for (int rowCount = 0; rowCount < 9; ++rowCount) {
        for (int columnCount = 0; columnCount < 9; ++columnCount) {
            if (board[rowCount][columnCount] == 0) {
                boardInitialFields[rowCount][columnCount] = -1;

            } else boardInitialFields[rowCount][columnCount] = 1;

        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d\t", boardInitialFields[i][j]);
        }
        printf("\n");
    }
    printf("\nSpielfeld erfolgreich initialisiert!\n");

}

// this function prints out the game board
void printField() {

    printf("\n\n");

    // we iterate through a field with 1 foor loop which goes vertically and one that fills in the fields horizontally


    // vertical outter foor loop
    for (int i = 0; i < 9; ++i) {
        // make sure to have a clean box top
        if (i == 0) {
            printf("\t \t \t");
            for (int n = 0; n < 9; ++n) {
                if ((n > 0) && (n % 3 == 0)) {
                    printf(" \t");
                }
                printf("%d\t", n + 1);
            }
            printf("\n\n");
            printf("\t \t+");
            for (int m = 0; m < 94; ++m) {
                if ((m > 0) && (m % 31 == 0)) {
                    printf("+");
                }
                if (m != 93) {
                    printf("-");
                }


            }
            printf("\n");

        }
        if ((i > 0) && (i % 3 == 0)) {
            printf("\t \t+");
            for (int k = 0; k < 94; ++k) {
                if ((k > 0) && (k % 31 == 0)) {
                    printf("+");
                }
                if (k != 93) {
                    printf("-");
                }

            }
            printf("\n");
        }
        printf("\t%d\t|", i + 1);

        // horizontal foor loop which fills in the board fields from the above array
        for (int j = 0; j < 9; ++j) {
            if ((j > 0) && (j % 3 == 0)) {
                printf("\t|");
            }
            printf("\t%d", board[i][j]);
            if (j == 8) {
                printf("\t|\n");
            }
        }

        // make sure to have a clean box bottom
        if (i == 8) {
            printf("\t \t+");
            for (int o = 0; o < 94; ++o) {
                if ((o > 0) && (o % 31 == 0)) {
                    printf("+");
                }
                if (o != 93) {
                    printf("-");
                }


            }
        }
        printf("\n");

    }


}

// check if all 3 Sudoku rules were respected by the input
bool checkTheRules(int row, int column, int input) {

    int rowStart, rowEnd, columnStart, columnEnd;
    rulesRespected = true;

    // check if there is no duplicate in row
    for (int j = 0; j < 9; ++j) {
        if (board[row - 1][j] == input) {
            rulesRespected = false;
        }
    }

    // check if there is no duplicate in column
    for (int i = 0; i < 9; ++i) {
        if (board[i][column - 1] == input) {
            rulesRespected = false;
        }
    }

    // check if there is no duplicate in the same quadrant
    if ((row - 1) < 3) {
        rowStart = 0;
        rowEnd = 3;

    } else if ((row - 1) < 6) {
        rowStart = 3;
        rowEnd = 6;

    } else if ((row - 1) < 9) {
        rowStart = 6;
        rowEnd = 9;
    }
    if ((column - 1) < 3) {
        columnStart = 0;
        columnEnd = 3;
    } else if ((column - 1) < 6) {
        columnStart = 3;
        columnEnd = 6;
    } else if ((column - 1) < 9) {
        columnStart = 6;
        columnEnd = 9;
    }
    for (int i = rowStart; i < rowEnd; ++i) {
        for (int j = columnStart; j < columnEnd; ++j) {
            if (board[i][j] == input) {
                rulesRespected = false;
            }
        }
    }
    return (rulesRespected);
}

// check if user has won or not
bool winLegit() {

    bool userHasWon = true;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                userHasWon = false;
            }
        }
    }
    return (userHasWon);
}


int main() {
    gameRunning = true;
    isInputValid = false;
    initialFieldsCheck = true;
    setAllowed = true;
    row = 0;
    column = 0;

    initializeBoard();
    while (gameRunning) {

        printField();
        do {
            printf("\nBitte geben Sie ein, welches Feld Sie bearbeiten wollen [Zeile,Spalte]:\n");
            do {
                printf("Zuerst die Zeile:\n");
                scanf("%d", &row);
                fflush(stdin);
            } while ((row <= 0) || (row >= 10));
            do {
                printf("Und nun die Spalte:\n");
                scanf("%d", &column);
                fflush(stdin);
            } while ((column <= 0) || (column >= 10));

            if (boardInitialFields[row - 1][column - 1] == 1) {
                printf("Bitte die Koordinaten eines Feldes eingeben, das nicht initial besetzt ist!\n");
                initialFieldsCheck = false;
                row = 0;
                column = 0;
            } else
                do {
                    printf("Und zuletzt die Zahl die eingegeben werden soll:\n");
                    scanf("%d", &input);
                    fflush(stdin);
                } while ((input <= 0) || (input >= 10));

            if (initialFieldsCheck == true) {

                if ((checkTheRules(row, column, input) == false)) {
                    printf("Diese Zahl ist bereits in derselben Reihe oder Spalte oder im selben Quadranten vorhanden!\n");
                    setAllowed = false;
                }else isInputValid = true;
            }

        } while (isInputValid == false);

        if (setAllowed == true)
        {
        	board[row - 1][column - 1] = input;
        }
        

        if (winLegit() == true) {
            gameRunning = false;
        }
    }
    printf("Du hast das Sudoku Puzzle gemeistert! YEAY!\n");


    return 0;
}