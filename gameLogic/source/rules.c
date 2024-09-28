#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int isValidMovePawn(char* pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  if (pieceToMove[0] == 'p') {
    return isValidMovePawnLower(pieceToMove, board, size, oldi, oldj, newi, newj);
  } else {
    return isValidMovePawnUpper(pieceToMove, board, size, oldi, oldj, newi, newj);
  }
}

// ============================================================================================= Pawn Lower
int isValidMovePawnLower(char* pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  int distance_i = abs((newi + 1) - (oldi + 1));
  int distance_j = abs((newj + 1) - (oldj + 1));

  // Pawn move forward
  if (newi == oldi-1 && newj == oldj && board[newi][newj] == ' ') {
    printf("Move forward\n");
    if (newi == 0) {
      printf("Change piece to q, b, r, n\n");
      scanf(" %c", pieceToMove);
      *pieceToMove = tolower(*pieceToMove);
    }
    return 1;
  }

  // Pawn is on starting row
  if (oldi == 6 && newj == oldj && (newi == oldi-1 || newi == oldi-2)) {
    printf("Move forward on starting row\n");
    return (newi == oldi-1 || newi == oldi-2 );
  }

  // Pawn move diagonal
  if (newi == oldi-1 && distance_j == 1 && !isOnTeam(pieceToMove, board[newi][newj])) {
    printf("Diagonal\n");
    if (newi == 0) {
      printf("Change piece to q, b, r, n\n");
      scanf(" %c", pieceToMove);
      *pieceToMove = tolower(*pieceToMove);
    }
    return 1;
  }

  printf("Invalid move LOWER\n");
  return 2;

}

// ============================================================================================= Pawn Upper
int isValidMovePawnUpper(char* pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  int distance_i = abs((newi + 1) - (oldi + 1));
  int distance_j = abs((newj + 1) - (oldj + 1));

  // Pawn move forward
  if (newi == oldi+1 && newj == oldj && board[newi][newj] == ' ') {
    printf("Move forward\n");
    if (newi == 7) {
      printf("Change piece to q, b, r, n\n");
      scanf(" %c", pieceToMove);
      *pieceToMove = toupper(*pieceToMove);
    }
    return 1;
  }

  // Pawn is on starting row
  if (oldi == 1 && newj == oldj) {
    printf("Move forward on starting row\n");
    return (newi == oldi+1 || newi == oldi+2 );
  }

  // Pawn move diagonal
  if (newi == oldi+1 && distance_j == 1 && !isOnTeam(pieceToMove, board[newi][newj])) {
    printf("Diagonal\n");
    if (newi == 7) {
      printf("Change piece to q, b, r, n\n");
      scanf(" %c", pieceToMove);
      *pieceToMove = toupper(*pieceToMove);
    }
    return 1;
  }

  printf("Invalid move UPPER\n");
  return 2;

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
        if (board[i][oldj] != ' ') {
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
  int distance_i = abs((newi + 1) - (oldi + 1));
  int distance_j = abs((newj + 1) - (oldj + 1));

  if (board[newi][newj] != ' ' && isOnTeam(pieceToMove, board[newi][newj])) {
    printf("You cannot attack your own pieces.");
    return 2;
  }

  if (distance_i != distance_j) {
    printf("Bishop must move diagonally.\n");
    return 2;
  }

  int isPositive_I = newi > oldi;
  int isPositive_J = newj > oldj;

  for (int i = 1; i <= distance_i-1; i++) {
    int temp_I = (isPositive_I ? oldi + i : oldi - i);
    int temp_J = (isPositive_J ? oldj + i : oldj - i);
    if (board[temp_I][temp_J] != ' ') {
      printf("Path blocked by %c", board[temp_I][temp_J]);
      return 2;
    }
  }

  return 1;
}

// ============================================================================================= Knight
int isValidMoveKnight(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  if (pieceToMove == 'n') {
    isValidMoveKnightLower(pieceToMove, board, size, oldi, oldj, newi, newj);
  } else {
    isValidMoveKnightUpper(pieceToMove, board, size, oldi, oldj, newi, newj);
  }
}

// ============================================================================================= Knight Lower
int isValidMoveKnightLower(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  int distance_i = abs((newi + 1) - (oldi + 1));
  int distance_j = abs((newj + 1) - (oldj + 1));

  printf("distance_i: %d\n", distance_i);
  printf("distance_j: %d\n", distance_j);
  printf("oldi: %d newi: %d\n", oldi, newi);
  printf("oldj: %d newj: %d\n", oldj, newj);
  printf("board: %d\n", board[newi][newj]);
  printf("isOnTeam: %d\n", isOnTeam(pieceToMove, board[newi][newj]));

  if (distance_i == 2 && distance_j == 1 && !isOnTeam(pieceToMove, board[newi][newj])) {
    return 1;
  }

  if (distance_i == 1 && distance_j == 2 && !isOnTeam(pieceToMove, board[newi][newj])) {
    return 1;
  }

  return 2;
}

// ============================================================================================= Knight Upper
int isValidMoveKnightUpper(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  int distance_i = abs((newi + 1) - (oldi + 1));
  int distance_j = abs((newj + 1) - (oldj + 1));

  printf("distance_i: %d\n", distance_i);
  printf("distance_j: %d\n", distance_j);
  printf("oldi: %d newi: %d\n", oldi, newi);
  printf("oldj: %d newj: %d\n", oldj, newj);
  printf("board: %d\n", board[newi][newj]);
  printf("isOnTeam: %d\n", isOnTeam(pieceToMove, board[newi][newj]));

  if (distance_i == 2 && distance_j == 1 && !isOnTeam(pieceToMove, board[newi][newj])) {
    return 1;
  }

  if (distance_i == 1 && distance_j == 2 && !isOnTeam(pieceToMove, board[newi][newj])) {
    return 1;
  }

  return 2;
}

// ============================================================================================= King
int isValidMoveKing(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  if (pieceToMove == 'k') {
    isValidMoveKingLower(pieceToMove, board, size, oldi, oldj, newi, newj);
  } else {
    isValidMoveKingUpper(pieceToMove, board, size, oldi, oldj, newi, newj);
  }
}

// ============================================================================================= King Lower
int isValidMoveKingLower(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  int distance_i = abs((newi + 1) - (oldi + 1));
  int distance_j = abs((newj + 1) - (oldj + 1));

  // Move king back and forward
  if (distance_i == 1 && distance_j == 0 && !isOnTeam(pieceToMove, board[newi][newj]) ) {
    return 1;
  }

  // Move king side to side
  if (distance_i == 0 && distance_j == 1 && !isOnTeam(pieceToMove, board[newi][newj])) {
    return 1;
  }

  // Move king diagonal
  if (distance_i == 1 && distance_j == 1 && !isOnTeam(pieceToMove, board[newi][newj])) {
    return 1;
  }

  printf("Invalid move for piece: %c\n", pieceToMove);
  return 2;
}

// ============================================================================================= King Upper
int isValidMoveKingUpper(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  int distance_i = abs((newi + 1) - (oldi + 1));
  int distance_j = abs((newj + 1) - (oldj + 1));

  // Move king back and forward
  if (distance_i == 1 && distance_j == 0 && !isOnTeam(pieceToMove, board[newi][newj])) {
    printf("Valid move\n");
    return 1;
  }

  // Move king side to side
  if (distance_i == 0 && distance_j == 1 && !isOnTeam(pieceToMove, board[newi][newj])) {
    return 1;
  }

  // Move king diagonal
  if (distance_i == 1 && distance_j == 1 && !isOnTeam(pieceToMove, board[newi][newj])) {
    return 1;
  }

  printf("Invalid move for piece: %c\n", pieceToMove);
  return 2;
}

// ============================================================================================= Queen
int isValidMoveQueen(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj) {
  int distance_I = abs((newi + 1) - (oldi + 1));
  int distance_J = abs((newj + 1) - (oldj + 1));

  if (board[newi][newj] != ' ' && isOnTeam(pieceToMove, board[newi][newj])) {
    printf("You cannot attack your own pieces.");
    return 2;
  }

  int isPositive_I = newi > oldi;
  int isPositive_J = newj > oldj;

  if (distance_I == distance_J) { // Diagonal
    for (int i = 1; i <= distance_I-1; i++) {
      int temp_I = (isPositive_I ? oldi + i : oldi - i);
      int temp_J = (isPositive_J ? oldj + i : oldj - i);
      if (board[temp_I][temp_J] != ' ') {
        printf("Path blocked by %c", board[temp_I][temp_J]);
        return 2;
      }
    }
  } else { // Cardinal
    if (distance_I > 0 && distance_J > 0) {
      printf("Queen must move diagonal or cardinally");
      return 2;
    }
    if (distance_I > 0) {
      if (newi - oldi < 0) {
        for (int i = oldi - 1; i > newi; i--) {
          if (board[i][oldj] != ' ') {
            printf("Path blocked by %c", board[i][oldj]);
            return 2;
          }
        }
      } else {
        for (int i = oldi + 1; i < newi; i++) {
          if (board[i][oldj] != ' ') {
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
  }





  return 1;
}

void winCondition(char board[GRID_SIZE][GRID_SIZE], const int size) {
  int countOfMulletedHorseLower = 0;
  int countOfMulletedHorseUpper = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i][j] == 'n') {
        countOfMulletedHorseLower++;
      }

      if (board[i][j] == 'N') {
        countOfMulletedHorseUpper++;
      }
    }
  }

  if (countOfMulletedHorseLower == 0 || countOfMulletedHorseUpper == 0) {
    printf("\nYou've lost all your mulleted horses.\nWhat reason do you have to play?\nGAME OVER :(");
    exit(0);
  }
}
