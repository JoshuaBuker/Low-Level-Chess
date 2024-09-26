#include <stdio.h>
#include<stdlib.h>
#include "./util/header/util.h"
#include <ctype.h>
#include "./gameLogic/header/rules.h"

#ifndef GRID_SIZE
#define GRID_SIZE 8
#endif

#ifndef MAX_LOOPS
#define MAX_LOOPS 10
#endif

// ======================================================================== Print Board
void printBoard(const char board[GRID_SIZE][GRID_SIZE], const int size) {
  for (int i = 0; i < size; i++) {
    printf(" %d  ", i + 1);
    for (int j = 0; j < size; j++) {
      // printf("[%c]", get_c(board, size, i, j));
      printf("[%c]", board[i][j]);
    }
    printf("\n");
  }

  printf("\n    ");

  for (int i = 65; i <= 72; i++) {
    printf(" %c ", (char)i);
  }
}

// ======================================================================== Move Piece
void movePiece(char board[GRID_SIZE][GRID_SIZE], const int size) {
  const int letterOffset = 97, numberOffset = 49;
  char input[32];

  inputStringPrompt(input, "\n\nEnter your move: ", "\n");

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

  char pieceToMove = board[oldI][oldJ];
  int validMove = 0;
  int isEligibleToChangePiece = 0;

  // switch(tolower(pieceToMove)) {
  switch ((pieceToMove)) {
    case 'p':
      validMove = isValidMovePawnLower(pieceToMove, board, size, oldI, oldJ, newI, newJ);
      isEligibleToChangePiece = newI == 0;
      break;
    case 'P':
      validMove = isValidMovePawnUpper(pieceToMove, board, size, oldI, oldJ, newI, newJ);
      isEligibleToChangePiece = newI == 7;
      break;
    case 'r':
      validMove = isValidMoveRook(pieceToMove, board, size, oldI, oldJ, newI, newJ);
      break;
    // I BROKE THE CARDINAL RULE FOR CODERS. I TOUCHED ANOTHER MANS CODE. ACCEPT MY DEEPEST APOLOGIES!!!
    case 'R':
      validMove = isValidMoveRook(pieceToMove, board, size, oldI, oldJ, newI, newJ);
      break;
    case 'k':
      validMove = isValidMoveKing(pieceToMove, board, size, oldI, oldJ, newI, newJ);
      break;
    case 'n':
      validMove = isValidMoveKnight(pieceToMove, board, size, oldI, oldJ, newI, newJ);
      break;
    case 'q':
      validMove = isValidMoveQueen(pieceToMove, board, size, oldI, oldJ, newI, newJ);
      break;
    case 'b':
      validMove = isValidMoveBishop(pieceToMove, board, size, oldI, oldJ, newI, newJ);
      break;
  }
  if (validMove == 1 && pieceToMove == 'p' && isEligibleToChangePiece) {
    board[oldI][oldJ] = ' ';
    char userInput;
    scanf(" %c", &userInput);
    board[newI][newJ] = tolower(userInput);
  } else if(validMove == 1 && pieceToMove == 'P' && isEligibleToChangePiece) {
    board[oldI][oldJ] = ' ';
    char userInput;
    scanf(" %c", &userInput);
    board[newI][newJ] = toupper(userInput);
  } else if (validMove == 1) {
    board[oldI][oldJ] = ' ';
    board[newI][newJ] = pieceToMove;
  } else {
    movePiece(board, size);
  }
}
