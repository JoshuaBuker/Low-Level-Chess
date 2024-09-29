#include <stdio.h>
#include "gameLogic/header/board.h"
#include "util/header/util.h"
#include <stdlib.h>

#ifndef GRID_SIZE
#define GRID_SIZE 8
#endif

int main(void) {
  int isLowerTurn = 0;

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
      winCondition(board, GRID_SIZE);
      movePiece(isLowerTurn, board, GRID_SIZE);
      system("cls");

      isLowerTurn = (isLowerTurn ? 0 : 1);
  }

  return 0;
}