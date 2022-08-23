/**************************************************************************/

/*			Header file for Board.h				 */


/*************************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include "Pieces.h"
#include <stdio.h>
/*************************Structure definition****************************/
typedef struct squares {
	PIECE *piece; /*points to the piece that occupies the square
			     otherwise will be NULL*/
	int color;         /*gives the color of the square*/
	int x,y;           /*coordinates for the square*/
} 
SQUARES;

typedef struct board{
	SQUARES board[8][8];
	} GAME;
/***********************************************************************/

/**********************Function definitions******************************/

/*global variable game*/
GAME game;

/* Sets up the beginning board with the proper values*/
GAME SetUpGame(GAME game);


/*Prints the board in ASCII format*/
void printboard(GAME game);

/*logs the move and writes it in a file called log.txt*/
void log_move(FILE *file, SQUARES *current_position,SQUARES *destination);


//void ai(int AI_COLOR, GAME game, SQUARES board[8][8]);
#endif

