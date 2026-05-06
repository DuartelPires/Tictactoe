#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

void resetBoard(char board[3][3]);
bool checkFreeSpaces(char board[3][3], int a, int b);
void playerMoves(char board[3][3], char player, int *gameOver, int *scoreX, int *scoreY, int *moves);
int checkWinner(char board[3][3], int row, int col);

#endif

