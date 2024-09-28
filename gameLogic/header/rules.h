#ifndef RULES_H
#define RULES_H

#ifndef GRID_SIZE
#define GRID_SIZE 8
#endif

int isUserInputValid(char* input);

int isValidMoveBishop     (char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMoveKnight     (char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMoveKnightLower(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMoveKnightUpper(char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMoveQueen      (char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMovePawn       (char* pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMovePawnLower  (char* pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMovePawnUpper  (char* pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMoveRook       (char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMoveKing       (char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMoveKingLower  (char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);
int isValidMoveKingUpper  (char pieceToMove, char board[GRID_SIZE][GRID_SIZE], int size, int oldi, int oldj, int newi, int newj);


#endif