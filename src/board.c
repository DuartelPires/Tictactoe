#include "board.h"
#include "print.h"
#include <stdlib.h>
#include <stdio.h>

void resetBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

bool checkFreeSpaces(char board[3][3], int a, int b) {
    return board[a][b] == ' ';
}

void playerMoves(char board[3][3], char player, int *gameOver, int *scoreX, int *scoreY, int *moves, int width) {
    int row, col;
    char s[100];
    char *p;
    printTurn(player, width);

    while (1) {
        while (1) {
            addPadding(width, 22);
            printf(COLOR_PROMPT "➜ " COLOR_RESET "Choose a row (1-3): ");
            if (fgets(s, sizeof(s), stdin)) {
                row = strtol(s, &p, 10);
                if (p == s || *p != '\n' || row < 1 || row > 3) {
                    addPadding(width, 34);
                    printf(COLOR_X "✖ " COLOR_RESET "Invalid input. Please enter 1-3.\n");
                } else {
                    break;
                }
            }
        }

        while (1) {
            addPadding(width, 22);
            printf(COLOR_PROMPT "➜ " COLOR_RESET "Choose a col (1-3): ");
            if (fgets(s, sizeof(s), stdin)) {
                col = strtol(s, &p, 10);
                if (p == s || *p != '\n' || col < 1 || col > 3) {
                    addPadding(width, 34);
                    printf(COLOR_X "✖ " COLOR_RESET "Invalid input. Please enter 1-3.\n");
                } else {
                    break;
                }
            }
        }

        row--;
        col--;

        if (checkFreeSpaces(board, row, col)) {
            board[row][col] = player;
            (*moves)++;
            printBoard(board, *scoreX, *scoreY, width);

            int winner = checkWinner(board, row, col);
            if (winner != 0) {
                if (winner == 1) {
                    (*scoreX)++;
                } else if (winner == 2) {
                    (*scoreY)++;
                }
                printBoard(board, *scoreX, *scoreY, width);
                printWinner(winner, width);
                *gameOver = 1;
            }
            break;
        } else {
            addPadding(width, 40);
            printf(COLOR_X "✖ " COLOR_RESET "That space has already been played on!\n");
        }
    }
}

int checkWinCol(char board[3][3], int col) {
    char first = board[0][col];
    if (first == ' ') return 0;
    for (int i = 1; i < 3; i++) {
        if (board[i][col] != first) return 0;
    }
    return (first == 'X') ? 1 : 2;
}

int checkWinRow(char board[3][3], int row) {
    char first = board[row][0];
    if (first == ' ') return 0;
    for (int i = 1; i < 3; i++) {
        if (board[row][i] != first) return 0;
    }
    return (first == 'X') ? 1 : 2;
}

int checkWinLeftDiag(char board[3][3]) {
    char first = board[0][0];
    if (first == ' ') return 0;
    for (int i = 1; i < 3; i++) {
        if (board[i][i] != first) return 0;
    }
    return (first == 'X') ? 1 : 2;
}

int checkWinRightDiag(char board[3][3]) {
    char first = board[0][2];
    if (first == ' ') return 0;
    for (int i = 1; i < 3; i++) {
        if (board[i][2 - i] != first) return 0;
    }
    return (first == 'X') ? 1 : 2;
}

int checkWinner(char board[3][3], int row, int col) {
    int player = 0;
    if ((player = checkWinRow(board, row)) != 0) return player;
    if ((player = checkWinCol(board, col)) != 0) return player;
    if ((player = checkWinLeftDiag(board)) != 0) return player;
    if ((player = checkWinRightDiag(board)) != 0) return player;
    return 0;
}

