#ifndef LEGALMOVES_H
#define LEGALMOVES_H

#include "Board.h"



int Qmove(SQUARES *curr_position, SQUARES *destination, GAME game);

int Kmove(SQUARES *curr_position, SQUARES *destination,SQUARES [8][8]);

int Hmove(SQUARES *curr_position, SQUARES *destination);

int Bmove(SQUARES *curr_position, SQUARES *destination, GAME game);

int Pmove(SQUARES *curr_position, SQUARES *destination, SQUARES [8][8],SQUARES *temp, SQUARES *new_temp);

int Rmove(SQUARES *curr_position, SQUARES *destination,GAME game);

SQUARES *Get_Current_Position(SQUARES board[8][8]);

SQUARES *Get_New_Position(SQUARES board[8][8]);

int check(GAME game,int player);

int checkmate(GAME game,int player);
#endif
