#include <stdio.h>
#include <stdlib.h>

#include "./util/header/util.h"

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

  char element = board;

  // printf("%d\n", ' ');
  // if (' '  == 32) {
  //   printf("Condition passed\n");
  // }
  // printf("%c", board[0][0]);
  // printf("[%c]", (char) board[0][0]);

  if (board[5][5] != 'x') {
    printf("TRUE\n");
  }


  // Pawn is not on starting row and can only move forward if space is empty
  // TODO Fix: pawn can move forward even if space is not empty
  if (newi == oldi-1 && newj == oldj) {
    printf("Move forward\n");
    // return newi == oldi - 1;
    return 1;
  }

  // Pawn is on starting row
  if (oldi == 6 && newj == oldj) {
    printf("Move forward on starting row\n");
    return (newi == oldi-1 || newi == oldi-2 );
  }

  // Pawn move diagonal left
  // TODO Fix: pawn can move diagonal left even if space is empty
  if (newi == oldi-1 && (newj == oldj-1 || newj == oldj+1) && (board != (char) 32)) {
    printf("Diagonal\n");
    return 1;
  }

  // Pawn move diagonal right
  // TODO Fix: pawn can move diagonal right even if space is empty
  // if (newi == oldi-1 && newj == oldj+1) {
  //   printf("Move diagonal right\n");
  //   return 1;
  // }

  printf("isValidMovePawn return 0\n");
  return 0;

}

// ============================================================================================= Rook
int isValidMoveRook(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  int distance_i = abs((newi + 1) - (oldi + 1));
  int distance_j = abs((newj + 1) - (oldj + 1));

  if (isOnTeam(pieceToMove, board[newi][newj])) {
    printf("You cannot attack your own pieces.");
    return 2;
  }

  // Check if a diagonal move was played
  if (distance_i > 0 && distance_j > 0) {
    printf("Rook cannot move diagonally.\n");
    return 2;
  }

  if (distance_i > 0) {
    if (newi - oldi < 0) {
      for (int i = oldi - 1; i > newi; i--) {
        if (board[i][oldj] != ' ') {
          printf("Path blocked by %c", board[i][oldj]);
          return 2;
        }
      }
    } else {
      for (int i = oldi + 1; i < newi; i++) {
        if (board[i][oldj] != ' ' || !isOnTeam(board[i][oldj], pieceToMove)) {
          printf("Path blocked by %c", board[i][oldj]);
          return 2;
        }
      }
    }
  } else {
    if (newj - oldj > 0) {
      for (int j = oldj + 1; j < newj; j++) {
        if (board[oldi][j] != ' ') {
          printf("Path blocked by %c", board[oldi][j]);
          return 2;
        }
      }
    } else {
      for (int j = oldj - 1; j > newj; j--) {
        if (board[oldi][j] != ' ') {
          printf("Path blocked by %c", board[oldi][j]);
          return 2;
        }
      }
    }
  }
  
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
