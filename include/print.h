#ifndef PRINT_H
#define PRINT_H

#define COLOR_X "\033[1;31m"
#define COLOR_O "\033[1;34m"
#define COLOR_BOARD "\033[0;90m"
#define COLOR_SCORE "\033[1;33m"
#define COLOR_PROMPT "\033[1;36m"
#define COLOR_RESET "\033[0m"

void printBoard(char board[3][3], int scoreX, int scoreY, int width);
void printWinner(int winner, int width);
void printTurn(char player, int width);
void clearScreen();
int getTerminalWidth();
void addPadding(int width, int contentLength);
void printScore(int scoreX, int scoreY, int width);

#endif

