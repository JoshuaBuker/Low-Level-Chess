#include <stdio.h>

#ifndef GRID_SIZE
#define GRID_SIZE 8
#endif

#ifndef MAX_LOOPS
#define MAX_LOOPS 10
#endif

// =================================================================================  User input
int isUserInputValid(char* input) {
  return 1;
}

// ============================================================================================= Pawn
int isValidMovePawn(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  return newi == oldi + 1;
}

// ============================================================================================= Rook
int isValidMoveRook(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  // int counter = 0;
  // while (counter++ < MAX_LOOPS)
  // {
  //   if (newi == 0 || newj == 0 || newi == size || newj == size)
  //   {
  //     printf("You can't move out of bounds you cheeky bugger you");
  //     return 0;
  //   }
  //   else if (newi != ' ' || newj != ' ')
  //   {
  //     return 1;
  //   }
  //   else if (newi != oldi+8 || newi != oldi-8)
  //   {
  //     return 0;
  //   }
  //   // Rule for checking whether left or right movement is valid
  //   else if (newj )

  //   return 1;
  // }
  return 1;
}

// ============================================================================================= Bishop
int isValidMoveBishop(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  return 1;
}

// ============================================================================================= Knight
int isValidMoveKnight(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  return 1;
}

// ============================================================================================= King
int isValidMoveKing(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  return 1;
}

// ============================================================================================= Queen
int isValidMoveQueen(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  return 1;
}
