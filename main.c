#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4
int board[SIZE][SIZE],score;
void initialize() {
        for (int i = 0; i< SIZE; ++i) {
        for(int j = 0; j <SIZE; ++j) {
            board[i][j] = 0;
        }
    }
    srand(time(NULL));
    int randRow1 = rand() % SIZE;
    int randCol1 = rand() % SIZE;
    int randRow2, randCol2;
    do {
            randRow2 = rand() % SIZE;
        randCol2 = rand() % SIZE;
    } while (randRow1 == randRow2 && randCol1 == randCol2);
    board[randRow1][randCol1] = (rand() % 2 + 1) * 2;
    board[randRow2][randCol2] = (rand() % 2 + 1) * 2;
}
void printBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%5d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void generateTile() {
    int emptyTiles[SIZE * SIZE][2];
    int count = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == 0) {
                emptyTiles[count][0] = i;
                emptyTiles[count][1] = j;
                count++;
            }
        }
    }
    if (count > 0) {
        int randomIndex = rand() % count;
        int value = (rand() % 2 + 1) * 2;
        board[emptyTiles[randomIndex][0]][emptyTiles[randomIndex][1]] = value;
    }
    else printf("NO MOVES AVAILABLE, GAMEOVER:(");
}
void mergeTilesUp() {
    for (int j = 0; j < SIZE; ++j) {
        for (int i = 0; i < SIZE - 1; ++i) {
            if (board[i][j] != 0) {
                for (int k = i + 1; k < SIZE; ++k) {
                    if (board[k][j] != 0) {
                        if (board[i][j] == board[k][j]) {
                            score+=board[i][j] *= 2;
                            board[k][j] = 0;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
}
void mergeTilesDown() {
    for (int j = 0; j < SIZE; ++j) {
        for (int i = SIZE - 1; i > 0; --i) {
            if (board[i][j] != 0) {
                for (int k = i - 1; k >= 0; --k) {
                    if (board[k][j] != 0) {
                        if (board[i][j] == board[k][j]) {
                            score+=board[i][j] *= 2;
                            board[k][j] = 0;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
}
void mergeTilesLeft() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE - 1; ++j) {
            if (board[i][j] != 0) {
                for (int k = j + 1; k < SIZE; ++k) {
                    if (board[i][k] != 0) {
                        if (board[i][j] == board[i][k]) {
                            score+=board[i][j] *= 2;
                            board[i][k] = 0;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
}
void mergeTilesRight() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = SIZE - 1; j > 0; --j) {
            if (board[i][j] != 0) {
                for (int k = j - 1; k >= 0; --k) {
                    if (board[i][k] != 0) {
                        if (board[i][j] == board[i][k]) {
                            score+=board[i][j] *= 2;
                            board[i][k] = 0;
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
}
void shiftRight() {
     int i, j, k;


    for (i = 0; i < SIZE; i++) {
        k = SIZE - 1;
        for (j = SIZE - 1; j >= 0; j--) {
            if (board[i][j] != 0) {

                board[i][k] = board[i][j];

                if (k != j) {
                    board[i][j] = 0;
                }

                k--;
            }
        }
    }
}
void shiftLeft() {
    int i, j, k;


    for (i = 0; i < SIZE; i++) {
        k = 0;
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != 0) {

                board[i][k] = board[i][j];

                    if (k != j) {
                    board[i][j] = 0;
                }

                k++;
            }
        }
    }
}
void shiftUp() {
  int i, j, k;


    for (j = 0; j < SIZE; j++) {
        k = 0;
        for (i = 0; i < SIZE; i++) {
            if (board[i][j] != 0) {

                board[k][j] = board[i][j];


                if (k != i) {
                    board[i][j] = 0;
                }

                k++;
            }
        }
    }
}
void shiftDown() {
    int i, j, k;


    for (j = 0; j < SIZE; j++) {
        k = SIZE - 1;
        for (i = SIZE - 1; i >= 0; i--) {
            if (board[i][j] != 0) {

                board[k][j] = board[i][j];


                if (k != i) {
                    board[i][j] = 0;
                }

                k--;
            }
        }
    }
}
int main()
 {

    initialize();
    while (1) {
        printBoard();
        char move;
        printf("Enter your move (a: left, d: right, w: up, s: down)    ");
        scanf(" %c", &move);
        printf("\n");
        switch (move) {
            case 'a':
                shiftLeft();
                mergeTilesLeft();
                generateTile();
                printf("Score:%d \n\n",score);
                break;
            case 'd':
                shiftRight();
                mergeTilesRight();
                generateTile();
                printf("Score:%d \n\n",score);
                break;
            case 'w':
                shiftUp();
                mergeTilesUp();
                generateTile();
                printf("Score:%d \n\n",score);
                break;
            case 's':
                shiftDown();
                mergeTilesDown();
                generateTile();
                printf("Score:%d \n\n",score);
                break;
            default:
                printf("Invalid move. Try again.\n");
                continue;
        }
    }

        return 0;
}

