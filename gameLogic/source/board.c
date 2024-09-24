#include <stdio.h>
#include "./util/header/util.h"
#include <ctype.h>
#include "./gameLogic/header/rules.h"

#define MAX_LOOPS 10

// ======================================================================== Print Board
void printBoard(const char *board, const int size) {
  for (int i = 0; i < size; i++) {
    printf(" %d  ", i + 1);
    for (int j = 0; j < size; j++) {
      printf("[%c]", get_c(board, size, i, j));
    }
    printf("\n");
  }

  printf("\n    ");

  for (int i = 65; i <= 72; i++) {
    printf(" %c ", (char)i);
  }
}

// ======================================================================== Move Piece
void movePiece(char *board, const int size) {
  const int letterOffset = 97, numberOffset = 49;
  char input[32];

  inputStringPrompt(input, "\n\nEnter your move: ", "\n\n");

  for (int i = 0; input[i]; i++) {
    input[i] = tolower(input[i]);
  }

  // moves piece left to right
  int oldJ = ((int)input[0]) - letterOffset;
  // moves piece up and down
  int oldI = ((int)input[1]) - numberOffset;
  // moves piece left to right
  int newJ = ((int)input[2]) - letterOffset;
  // moves piece up and down
  int newI = ((int)input[3]) - numberOffset;
  // 3

  char pieceToMove = get_c(board, size, oldI, oldJ);

  // switch (toLower(pieceToMove)) {
  //   case 'p':
  //     if (1 != isValidMovePawn(pieceToMove, board, size, oldI, oldJ, newI, newJ)) { return; }break;
  //   case 'r':
  //     if (1 != isValidMoveRook(pieceToMove, board, size, oldI, oldJ, newI, newJ)) { return; }break;
  //   case 'k':
  //     if (1 != isValidMoveKing(pieceToMove, board, size, oldI, oldJ, newI, newJ)) { return; }break;
  //   case 'n':
  //     if (1 != isValidMoveKnight(pieceToMove, board, size, oldI, oldJ, newI, newJ)) { return; }break;
  //   case 'q':
  //     if (1 != isValidMoveQueen(pieceToMove, board, size, oldI, oldJ, newI, newJ)) { return; }break;
  //   case 'b':
  //     if (1 != isValidMoveBishop(pieceToMove, board, size, oldI, oldJ, newI, newJ)) { return; }break;
  // }

  set_c(board, size, oldI, oldJ, ' ');
  set_c(board, size, newI, newJ, pieceToMove);
}
