#include "Board.h"
#include "LegalMoves.h"
#include "Pieces.h"

#ifndef AI_H
#define AI_H

void ai(int AI_COLOR, GAME game, SQUARES board[8][8]);

SQUARES * AI_current(int PC, SQUARES board[8][8],GAME game);

SQUARES * AI_new (SQUARES *current,int PC, SQUARES board[8][8],GAME game);

#endif
