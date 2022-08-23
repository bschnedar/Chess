#ifndef BOARD
#include "Board.h"
#endif

void LoadImage(char str[], int x, int y);

void makeBoard();

void placePiece(char str[], int x, int y);

void replacePiece(char replace[], int xCurr, int yCurr, int xDest, int yDest, int color); 

int convertCoordinateX(int x);

int convertCoordinateY(int y);

int startGame();

void updateBoard(GAME game);
