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

// int isOnTeam(const char piece1, const char piece2) {
//   int isPiece1Lower = (97 <= piece1 && piece1 <= 122) ? 1 : 0;
//   int isPiece2Lower = (97 <= piece2 && piece2 <= 122) ? 1 : 0;
  
//   return (isPiece1Lower == isPiece2Lower);
// }

int isOnTeam(char piece1, char piece2) {
  // Lower case
  if ((int) piece1 >= 97 && (int) piece1 <= 122 && (int) piece2 >= 97 && (int) piece2 <= 122) {return 1;}

  // Upper case
  if ((int) piece1 >= 65 && (int) piece1 <= 90 && (int) piece2 >= 65 && (int) piece2 <= 90) {return 1;}

  return 0;
}

int isValidPieceUpper(char* pieceToMove) {
  while (1) {
        printf("Change piece to q, b, r, n\n");
        scanf(" %c", pieceToMove);
        if (toupper(*pieceToMove) == 'Q' || toupper(*pieceToMove) == 'B' || toupper(*pieceToMove) == 'R' || toupper(*pieceToMove) == 'N') {
          *pieceToMove = toupper(*pieceToMove);
          break;
        }
        printf("Invalid input. Choose from the above options.\n");
      }
}