#ifndef BOARD_H
#define BOARD_H

#ifndef GRID_SIZE
#define GRID_SIZE 8
#endif

void printBoard(const char board[GRID_SIZE][GRID_SIZE], const int size);
void movePiece(char board[GRID_SIZE][GRID_SIZE], const int size);

#endif