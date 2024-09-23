#include <stdio.h>
#include "./util/header/util.h"
#include <ctype.h>

void printBoard(const char* board, const int size) {
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

void movePiece(char* board, const int size) {
  const int letterOffset = 97, numberOffset = 49;
  char input[5];

  printf("\n\nEnter your move: ");
  scanf("%s", input);
  printf("\n\n");

  for(int i = 0; input[i]; i++){
    input[i] = tolower(input[i]);
  }

  int oldJ = ((int)input[0]) - letterOffset;
  int oldI = ((int)input[1]) - numberOffset;
  int newJ = ((int)input[2]) - letterOffset;
  int newI = ((int)input[3]) - numberOffset;

  char pieceToMove = get_c(board, size, oldI, oldJ);

  set_c(board, size, oldI, oldJ, ' ');
  set_c(board, size, newI, newJ, pieceToMove);

}