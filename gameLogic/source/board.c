#include <stdio.h>
#include <./util.h>
#include <ctype.h>
#include <game.c>

#define MAX_LOOPS 10

void printBoard(const char *board, const int size)
{
  for (int i = 0; i < size; i++)
  {
    printf(" %d  ", i + 1);
    for (int j = 0; j < size; j++)
    {
      printf("[%c]", get_c(board, size, i, j));
    }
    printf("\n");
  }

  printf("\n    ");

  for (int i = 65; i <= 72; i++)
  {
    printf(" %c ", (char)i);
  }
}

void movePiece(char *board, const int size)
{
  const int letterOffset = 97, numberOffset = 49;
  char input[5];

  printf("\n\nEnter your move: ");
  scanf("%s", input);
  printf("\n\n");

  for (int i = 0; input[i]; i++)
  {
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

  switch (toLower(pieceToMove))
  {
  case 'p':
    if (1 != isValidMovePawn(pieceToMove, board, size, oldI, oldJ, newI, newJ))
    {
      return;
    }
    break;

  case 'r':
    if (1 != isValidMoverook(pieceToMove, board, size, oldI, oldJ, newI, newJ))
    {
      return;
    }
    break;
  }

  set_c(board, size, oldI, oldJ, ' ');
  set_c(board, size, newI, newJ, pieceToMove);
}

int isValidMovePawn(pieceToMove, board, size, oldi, oldj, newi, newj)
{
  return newi == oldi + 1;
}

int isValidMoveRook(pieceToMove, board, size, oldi, oldj, newi, newj)
{
  int counter = 0;
  while (counter++ < MAX_LOOPS)
  {
    if (newi == 0 || newj == 0 || newi == GRID_SIZE || newj == GRID_SIZE)
    {
      printf("You can't move out of bounds you cheeky bugger you");
      return 0;
    }
    else if (newi != ' ' || newj != ' ')
    {
      return 1;
    }
    else if (newi != oldi+8 || newi != oldi-8)
    {
      return 0;
    }
    // Rule for checking whether left or right movement is valid
    else if (newj )

    return 1;
  }
}
