#include "print.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>


#define P(c) ((c == 'X') ? COLOR_X "X" COLOR_RESET : (c == 'O') ? COLOR_O "O" COLOR_RESET : " ")

void printBoard(char board[3][3], int scoreX, int scoreY, int width) {
    clearScreen();
    printf("\n\n");
    printScore(scoreX, scoreY, width);
    printf("\n");
    
    int boardWidth = 11;
    int padding = (width - boardWidth) / 2;

    // Column numbers
    for(int k = 0; k < padding; k++) printf(" ");
    printf(COLOR_BOARD " 1   2   3 \n\n" COLOR_RESET);

    for (int i = 0; i < 3; i++) {
        // Row numbers
        int rowNumPadding = padding - 5;
        if (rowNumPadding < 0) rowNumPadding = 0;
        for(int k = 0; k < rowNumPadding; k++) printf(" ");
        
        printf(COLOR_BOARD "  %d  " COLOR_RESET, i + 1);
        printf(" %s │ %s │ %s \n", P(board[i][0]), P(board[i][1]), P(board[i][2]));
        
        if (i != 2) {
            for(int k = 0; k < padding; k++) printf(" ");
            printf(COLOR_RESET "───┼───┼───\n" COLOR_RESET);
        }
    }
    printf("\n");
}

void printWinner(int winner, int width) {
    printf("\n");
    addPadding(width, 15);
    if (winner == 1) printf(COLOR_X "X's player won!\n" COLOR_RESET);
    else printf(COLOR_O "O's player won!\n" COLOR_RESET);
}

int getTerminalWidth(){
  struct winsize w;
  char *col_str = getenv("COLUMNS");
  if (col_str != NULL && atoi(col_str) > 0) {
    return atoi(col_str);
  }
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) != -1 && w.ws_col > 0) {
    return w.ws_col;
  }
  return 80;
}

void addPadding(int width, int contentLength){
  int padding = (width - contentLength) / 2;
  if (padding < 0) return;
  for(int i = 0; i < padding; i++){
    printf(" ");
  }
}

void printTurn(char player, int width) {
    addPadding(width, 18);
    printf(COLOR_BOARD "┏━━━━━━━━━━━━━━━━┓\n" COLOR_RESET);
    addPadding(width, 18);
    if (player == 'X') {
        printf(COLOR_BOARD "┃" COLOR_RESET "    " COLOR_X "X" COLOR_RESET "'s turn    " COLOR_BOARD "┃\n" COLOR_RESET);
    } else {
        printf(COLOR_BOARD "┃" COLOR_RESET "    " COLOR_O "O" COLOR_RESET "'s turn    " COLOR_BOARD "┃\n" COLOR_RESET);
    }
    addPadding(width, 18);
    printf(COLOR_BOARD "┗━━━━━━━━━━━━━━━━┛\n" COLOR_RESET);
}

void clearScreen() {
    system("clear");
}

void printScore(int scoreX, int scoreY, int width) {
    addPadding(width, 18);
    printf(COLOR_BOARD "╔════════════════╗\n" COLOR_RESET);
    addPadding(width, 18);
    printf(COLOR_BOARD "║" COLOR_RESET "   " COLOR_X "X" COLOR_RESET " %d" COLOR_RESET "  :  " COLOR_RESET "%d " COLOR_O "O" COLOR_RESET "  " COLOR_BOARD "║\n" COLOR_RESET, scoreX, scoreY);
    addPadding(width, 18);
    printf(COLOR_BOARD "╚════════════════╝\n" COLOR_RESET);
}
