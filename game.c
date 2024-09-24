#include <stdio.h>
#include "gameLogic/header/board.h"

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

  while (1) {
      printBoard(board, GRID_SIZE);
      movePiece(board, GRID_SIZE);
      system("cls");
  }

  return 0;
}