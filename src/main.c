#include "board.h"
#include "print.h"
#include <stdio.h>

int main() {
    char board[3][3];
    const char Player1 = 'X';
    const char Player2 = 'O';
    int gameOver = 0;
    int scoreX = 0;
    int scoreY = 0;
    int moves = 0;
    int width = getTerminalWidth();
    do {
        resetBoard(board);
        printBoard(board, scoreX, scoreY, width);
        gameOver = 0;
        moves = 0;

        while (gameOver == 0 && moves < 9) {
            playerMoves(board, Player1, &gameOver, &scoreX, &scoreY, &moves, width);
            if (gameOver == 0 && moves < 9) {
                playerMoves(board, Player2, &gameOver, &scoreX, &scoreY, &moves, width);
            }
        }

        if (moves == 9 && gameOver == 0) {
            printf("\n");
            addPadding(width, 12);
            printf("It's a draw!\n");
        }

        char restart;
        printf("\n");
        addPadding(width, 34);
        printf("Do you want to play again? (y/n): ");
        restart = getchar();
        while (getchar() != '\n'); 

        if (restart == 'n' || restart == 'N') {
            break;
        }
    } while (1);

    return 0;
}

