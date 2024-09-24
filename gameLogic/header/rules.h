#ifndef RULES_H
#define RULES_H

int isUserInputValid(char* input);

int isValidMoveBishop(char pieceToMove, char* board, int size, int oldi, int oldj, int newi, int newj);
int isValidMoveKnight(char pieceToMove, char* board, int size, int oldi, int oldj, int newi, int newj);
int isValidMoveQueen (char pieceToMove, char* board, int size, int oldi, int oldj, int newi, int newj);
int isValidMovePawn  (char pieceToMove, char* board, int size, int oldi, int oldj, int newi, int newj);
int isValidMoveRook  (char pieceToMove, char* board, int size, int oldi, int oldj, int newi, int newj);
int isValidMoveKing  (char pieceToMove, char* board, int size, int oldi, int oldj, int newi, int newj);


#endif