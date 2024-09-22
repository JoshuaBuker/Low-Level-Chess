#include <stdio.h>
#include "util.h"

void printBoard(const char* board, const int size) {
  for (int i = 0; i < size; i++) {
    printf(" %d  ", size - i);
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