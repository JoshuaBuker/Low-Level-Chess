#include <stdio.h>

int add(const int x, const int y) {
  return x + y;
}

void printBoard(const char* board) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      printf("[%c]", *((board+i*8) + j));
    }
    printf("\n");
  }
}