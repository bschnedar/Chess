#include "Board.h"
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define BLACK 0
#define WHITE 1

#define DEAD 0
#define ALIVE 1

GAME SetUpGame(GAME game)
{
int x,y;
game.board[0][0].color=BLACK;

for(x=0;x<8;x++)
{

if(game.board[x-1][0].color==BLACK && (x-1>0))
{
	game.board[x][0].color=WHITE;
}

else
{
game.board[x][0].color=BLACK;
}


	for(y=0;y<8;y++)
	{

	game.board[x][y].x=x;
	game.board[x][y].y=y;

	if(game.board[x][y-1].color==BLACK && (y-1>0))
	{
	game.board[x][y].color=WHITE;
	}
	
	else
	{
	if(y!=0)
	game.board[x][y].color=BLACK;
	}
	}
}



for(x=0;x<8;x++)
{
for(y=0;y<8;y++)
	{
	game.board[x][y].piece=NULL;
	}
}


/*****creating black pieces and assiging values*****/

bp1.piece_type=2;
bp1.color=BLACK;
bp1.past_move=0;
bp1.value = 1;

bp2.piece_type=2;
bp2.color=BLACK;
bp2.past_move=0;
bp2.value = 1;

bp3.piece_type=2;
bp3.color=BLACK;
bp3.past_move=0;
bp3.value = 1;

bp4.piece_type=2;
bp4.color=BLACK;
bp4.past_move=0;
bp4.value = 1; 

bp5.piece_type=2;
bp5.color=BLACK;
bp5.past_move=0;
bp5.value = 1;

bp6.piece_type=2;
bp6.color=BLACK;
bp6.past_move=0;
bp6.value = 1;

bp7.piece_type=2;
bp7.color=BLACK;
bp7.past_move=0;
bp7.value = 1;

bp8.piece_type=2;
bp8.color=BLACK;
bp8.past_move=0;
bp8.value = 1;

bR1.piece_type=4;
bR1.color=BLACK;
bR1.past_move=0;
bR1.value = 30;

bR2.piece_type=4;
bR2.color=BLACK;
bR2.past_move=0;
bR2.value = 30;

bKn1.piece_type=6;
bKn1.color=BLACK;
bKn1.past_move=0;
bKn1.value = 20;

bKn2.piece_type=6;
bKn2.color=BLACK;
bKn2.past_move=0;
bKn2.value = 20;

bB1.piece_type=8;
bB1.color=BLACK;
bB1.past_move=0;
bB1.value = 20;

bB2.piece_type=8;
bB2.color=BLACK;
bB2.past_move=0;
bB2.value = 20;

bQ.piece_type=10;
bQ.color=BLACK;
bQ.past_move=0;
bQ.value = 40;

bK.piece_type=12;
bK.color=BLACK;
bK.past_move=0;
bK.value = 1000;

/********creating and assigning values for white pieces**************/

wp1.piece_type=1;
wp1.color=WHITE;
wp1.past_move=0;
wp1.value = 1;

wp2.piece_type=1;
wp2.color=WHITE;
wp2.past_move=0;
wp2.value = 1;

wp3.piece_type=1;
wp3.color=WHITE;
wp3.past_move=0;
wp3.value = 1;

wp4.piece_type=1;
wp4.color=WHITE;
wp4.past_move=0;
wp4.value = 1;

wp5.piece_type=1;
wp5.color=WHITE;
wp5.past_move=0;
wp5.value = 1;

wp6.piece_type=1;
wp6.color=WHITE;
wp6.past_move=0;
wp6.value = 1;

wp7.piece_type=1;
wp7.color=WHITE;
wp7.past_move=0;
wp7.value = 1;

wp8.piece_type=1;
wp8.color=WHITE;
wp8.past_move=0;
wp8.value = 1;

wR1.piece_type=3;
wR1.color=WHITE;
wR1.past_move=0;
wR1.value = 30;

wR2.piece_type=3;
wR2.color=WHITE;
wR2.past_move=0;
wR2.value = 30;

wB1.piece_type=7;
wB1.color=WHITE;
wB1.past_move=0;
wB1.value = 20;

wB2.piece_type=7;
wB2.color=WHITE;
wB2.past_move=0;
wB2.value = 20;

wKn1.piece_type=5;
wKn1.color=WHITE;
wKn1.past_move=0;
wKn1.value = 20;

wKn2.piece_type=5;
wKn2.color=WHITE;
wKn2.past_move=0;
wKn2.value = 20;

wQ.piece_type=9;
wQ.color=WHITE;
wQ.past_move=0;
wQ.value = 40;

wK.piece_type=11;
wK.color=WHITE;
wK.past_move=0;
wK.value = 1000;


/********************Assign the pieces to the board**************************/

/************black pieces*********/

game.board[0][6].piece=&bp1;
game.board[1][6].piece=&bp2;
game.board[2][6].piece=&bp3;
game.board[3][6].piece=&bp4;
game.board[4][6].piece=&bp5;
game.board[5][6].piece=&bp6;
game.board[6][6].piece=&bp7;
game.board[7][6].piece=&bp8;


game.board[0][7].piece=&bR1;
game.board[7][7].piece=&bR2;

game.board[2][7].piece=&bB1;
game.board[5][7].piece=&bB2;

game.board[1][7].piece=&bKn1;
game.board[6][7].piece=&bKn2;

game.board[3][7].piece=&bQ;
game.board[4][7].piece=&bK;


/************white pieces*********/

game.board[0][1].piece=&wp1;
game.board[1][1].piece=&wp2;
game.board[2][1].piece=&wp3;
game.board[3][1].piece=&wp4;
game.board[4][1].piece=&wp5;
game.board[5][1].piece=&wp6;
game.board[6][1].piece=&wp7;
game.board[7][1].piece=&wp8;

game.board[0][0].piece=&wR1;
game.board[7][0].piece=&wR2;

game.board[2][0].piece=&wB1;
game.board[5][0].piece=&wB2;

game.board[1][0].piece=&wKn1;
game.board[6][0].piece=&wKn2;

game.board[3][0].piece=&wQ;
game.board[4][0].piece=&wK;

return game;
}

/**************End of CreateGame Function********************/

void printboard(GAME game)
{
int x,y;
int b=7;
char piece[4]="";
int a;

printf("    A \t    B \t    C \t    D \t    E \t    F \t    G \t    H \n");
for(y=8;y>0;y--)
{

printf("--------");
}
printf("\n");


for(x=0;x<8;x++)
{

printf("|\t|\t|\t|\t|\t|\t|\t|\t|");
printf("\n");
printf("|");

/******************************************/

a=0;

for(y=8;y>0;y--)
{

if(game.board[a][b].piece!=NULL)
{

if(game.board[a][b].piece->piece_type==1)
strcpy(piece,"wP");


else if(game.board[a][b].piece->piece_type==3)
strcpy(piece,"wR");

else if(game.board[a][b].piece->piece_type==7)
strcpy(piece,"wB");

else if(game.board[a][b].piece->piece_type==5)
strcpy(piece,"wKn");

else if(game.board[a][b].piece->piece_type==9)
strcpy(piece,"wQ");

else if(game.board[a][b].piece->piece_type==11)
strcpy(piece,"wK");

else if(game.board[a][b].piece->piece_type==2)
strcpy(piece,"bP");

else if(game.board[a][b].piece->piece_type==4)
strcpy(piece,"bR");

else if(game.board[a][b].piece->piece_type==6)
strcpy(piece,"bKn");

else if(game.board[a][b].piece->piece_type==8)
strcpy(piece,"bB");

else if(game.board[a][b].piece->piece_type==10)
strcpy(piece,"bQ");

else if(game.board[a][b].piece->piece_type==12)
strcpy(piece,"bK");

}

else
strcpy(piece,"");

printf("  %s \t|",piece);
a++;
}
printf(" %d",b+1);



printf("\n");

printf("|\t|\t|\t|\t|\t|\t|\t|\t|");
printf("\n");


for(y=8;y>0;y--)
{
printf("--------");
}
printf("\n");
b--;
}


}

/***************************END OF PRINT FUNCTION*********************************/

void log_move(FILE *file, SQUARES *current_position,SQUARES *destination)
{
char a;
int b;

char c;
int  d;

if (current_position->x==0)
a='A';
else if(current_position->x==1)
a='B';
else if(current_position->x==2)
a='C';
else if(current_position->x==3)
a='D';
else if(current_position->x==4)
a='E';
else if(current_position->x==5)
a='F';
else if(current_position->x==6)
a='G';
else if(current_position->x==7)
a='H';

b=current_position->y+1;

if (destination->x==0)
c='A';
else if(destination->x==1)
c='B';
else if(destination->x==2)
c='C';
else if(destination->x==3)
c='D';
else if(destination->x==4)
c='E';
else if(destination->x==5)
c='F';
else if(destination->x==6)
c='G';
else if(destination->x==7)
c='H';

d=destination->y+1;

fprintf(file,"[%c%d]->[%c%d]\n",a,b,c,d);

}







