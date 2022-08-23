/*************************************************************************/

/*			Header File for Pieces.h		         */


/*************************************************************************/

#ifndef PIECES_H
#define PIECES_H

typedef struct Piece{
	int color;
	int piece_type;
	int past_move;
	int value;
	} PIECE;


/*Global Variable Declarations*/

/*Black Pieces*/
PIECE bp1;
PIECE bp2;
PIECE bp3;
PIECE bp4;
PIECE bp5;
PIECE bp6;
PIECE bp7;
PIECE bp8;

PIECE bB1;
PIECE bB2;

PIECE bR1;
PIECE bR2;

PIECE bKn1;
PIECE bKn2;

PIECE bQ;
PIECE bK;

//PIECE * TrackerB[16] = {bp1,bp2,bp3,bp4,bp5,bp6,bp7,bp8,bR1,bR1, bB1,bB2,bKn1,bKn2, bK,bQ};
/*White Pieces*/
PIECE wp1;
PIECE wp2;
PIECE wp3;
PIECE wp4;
PIECE wp5;
PIECE wp6;
PIECE wp7;
PIECE wp8;

PIECE wR1;
PIECE wR2;

PIECE wB1;
PIECE wB2;

PIECE wKn1;
PIECE wKn2;

PIECE wK;
PIECE wQ;

//PIECE * TrackerW[16] = {wp1,wp2,wp3,wp4,wp5,wp6,wp7,wp8,wR1,wR1, wB1,wB2,wKn1,wKn2, wK,wQ};
#endif	
