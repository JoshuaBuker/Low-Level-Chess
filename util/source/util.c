#include <stdio.h>

#define GRID_SIZE 8

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