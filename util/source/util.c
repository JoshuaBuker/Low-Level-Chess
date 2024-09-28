#include <stdio.h>

#ifndef GRID_SIZE
#define GRID_SIZE 8
#endif

// char get_c(const char arr[GRID_SIZE][GRID_SIZE], const int size, const int i, const int j) {
//   return *((arr+i*size) + j);
// } 

// char set_c(char arr[GRID_SIZE][GRID_SIZE], const int size, const int i, const int j, const char symbol) {
//   return *((arr+i*size) + j) = symbol;
// } 

int inputStringPrompt(char* buffer, const char* prompt, const char* afterPrompt) {
  printf("%s", prompt);
  scanf("%s", buffer);
  printf("%s", afterPrompt);

  return 1;
}

int isOnTeam(const char piece1, const char piece2) {
  int isPiece1Lower = (97 <= piece1 && piece1 <= 122) ? 1 : 0;
  int isPiece2Lower = (97 <= piece2 && piece2 <= 122) ? 1 : 0;
  
  return (isPiece1Lower == isPiece2Lower);
}