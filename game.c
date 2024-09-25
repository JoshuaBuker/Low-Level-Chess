#include <stdio.h>
#include "board.h"
#include <stdlib.h>

#ifndef GRID_SIZE
#define GRID_SIZE 8
#endif

int main(void) {
  char board[GRID_SIZE][GRID_SIZE] =
  {
    {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r'}
  };

  while (1) {
      printBoard(board, GRID_SIZE);
      movePiece(board, GRID_SIZE);
      system("cls");
  }

  return 0;
}