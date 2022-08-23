#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LegalMoves.h"
#include "Board.h"
#include "Pieces.h"
#include <assert.h>


/**************potato mode********************/
SQUARES *AI_current(int PC,SQUARES board[8][8])
{
SQUARES *current;
int c;
int aix1;
int aiy1;

srand(time(NULL));
while(c!=PC)
{
aix1=rand()%7;
aiy1=rand()%7;
if(board[aix1][aiy1].piece!=NULL)
{
if(board[aix1][aiy1].piece->color==PC)
c=PC;
printf("%d\n",c);
printf("%d\n",board[aix1][aiy1].piece->color);
printf("%d\n",PC);
}
printf("stuck\n");
}

current=&board[aix1][aiy1];
return current;
}


/*******************************************************************************/
SQUARES *AI_new(SQUARES *current,int PC,SQUARES board[8][8])
{
SQUARES *new;
int aix2;
int aiy2;

printf("hello\n");
aix2=rand()%7;
aiy2=rand()%7;
new=&board[aix2][aiy2];


return new;
}


/*******************************master mode******************************************/








