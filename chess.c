#include <stdio.h>
#include "func.h"

#define GRID_SIZE 8

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

  printBoard(board, GRID_SIZE);

  return 0;
}