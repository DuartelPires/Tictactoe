#include "print.h"
#include <stdlib.h>
#include <stdio.h>

void printBoard(char board[3][3], int scoreX, int scoreY) {
    clearScreen();
    printScore(scoreX, scoreY);
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("\n---╋---╋---\n");
        }
    }
    printf("\n");
}

void printWinner(int winner) {
    char player = (winner == 1) ? 'X' : 'O';
    printf("\n%c's player won!\n", player);
}

void printTurn(char player) {
    printf("\n┏------------┓\n");
    printf("|  %c's turn  |\n", player);
    printf("┗------------┛\n");
}

void clearScreen() {
    system("clear");
}

void printScore(int scoreX, int scoreY) {
    printf("   %d : %d    \n\n", scoreX, scoreY);
}

