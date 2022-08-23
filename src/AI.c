#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LegalMoves.h"
#include "Board.h"
#include "Pieces.h"
#include <assert.h>

#include "AI.h"
/**************potato mode********************/
SQUARES *AI_current(int PC,SQUARES board[8][8],GAME game)
{
SQUARES *curr_position;
SQUARES *destination;
int x;
int y;
int a;
int b;
int valid;
GAME copy;
copy=game;
for(x=0;x<8;x++)
{
	for(y=0;y<8;y++)
	{
	if(game.board[x][y].piece!=NULL && game.board[x][y].piece->color==PC)
	{
	curr_position=&game.board[x][y];
	
	for(a=0;a<8;a++)

	{

	for(b=0;b<8;b++)
	{
	destination=&game.board[a][b];

	
	if(curr_position->piece->piece_type==1 || curr_position->piece->piece_type==2)/*Pawn Move*/
        valid=Pmove(curr_position,destination,game.board,NULL,NULL);

    	else if(curr_position->piece->piece_type==3 || curr_position->piece->piece_type==4)/*Rook Move*/
        valid=Rmove(curr_position,destination,game);

    	else if(curr_position->piece->piece_type==5 || curr_position->piece->piece_type==6)/*Knight Move*/
        valid=Hmove(curr_position,destination);

    	else if(curr_position->piece->piece_type==7 || curr_position->piece->piece_type==8)/*Bishop Move*/
        valid=Bmove(curr_position,destination,game);

    	else if(curr_position->piece->piece_type==9 || curr_position->piece->piece_type==10)/*Queen Move*/
        valid=Qmove(curr_position,destination,game);

    	else if(curr_position->piece->piece_type==11 || curr_position->piece->piece_type==12)/*King Move*/
        valid=Kmove(curr_position,destination,game.board);
	
		

	if(valid==1)
	{
	 printf("c%d,%d\n",x,y);
	valid=check(game,PC);
	printf("valid=%d\n",valid);
	game=copy;
	if(valid==0)
	{curr_position=&board[x][y];
	valid=1;
	printf("made it\n");
	return curr_position;
	}
	}
  }


	}
}

	
	}		
	}

return curr_position;
}


/*******************************************************************************/

SQUARES *AI_new(SQUARES *curr_position,int PC,SQUARES board[8][8],GAME game)
{
SQUARES *temp;
SQUARES *destination;
int x;
int y;
int valid;
GAME copy;
copy=game;
temp=&game.board[curr_position->x][curr_position->y];
for(x=0;x<8;x++)
{
	for(y=0;y<8;y++)	
	{
 	destination=&game.board[x][y];
	
	if(curr_position->piece->piece_type==1 || curr_position->piece->piece_type==2)/*Pawn Move*/
        valid=Pmove(temp,destination,game.board,NULL,NULL);

    	else if(curr_position->piece->piece_type==3 || curr_position->piece->piece_type==4)/*Rook Move*/
        valid=Rmove(temp,destination,game);

    	else if(curr_position->piece->piece_type==5 || curr_position->piece->piece_type==6)/*Knight Move*/
        valid=Hmove(temp,destination);

    	else if(curr_position->piece->piece_type==7 || curr_position->piece->piece_type==8)/*Bishop Move*/
        valid=Bmove(temp,destination,game);

    	else if(curr_position->piece->piece_type==9 || curr_position->piece->piece_type==10)/*Queen Move*/
        valid=Qmove(temp,destination,game);

    	else if(curr_position->piece->piece_type==11 || curr_position->piece->piece_type==12)/*King Move*/
        valid=Kmove(temp,destination,game.board);

	if(valid==1)
	{
	valid=check(game,PC);
	printf("valid=%d\n",valid);
	game=copy;
	if(valid==0)
	valid=1;
	destination=&board[x][y];
	printf("d%d,%d\n",x,y);
	return destination;
	
	}
	}






}

return destination;
}

/*******************************master mode******************************************/
//PIECES * trackerW[16]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
//PIECES * trackerB[16]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
/*
void ai(int AI_COLOR, GAME gam,  SQUARES board[8][8]){
   SQUARES * sel;
   SQUARES * new;
   PIECE * save;
   SQUARES * sub;
   SQUARES * mov;
// 

	  
	int remove = 0;
        int totscore = 0;
	int x;
	int y;
	int xx;
	int yy;
   int bestscore;
   int XGO= 0; int YGO = 0; int XXGO = 0; int YYGO = 0;
   int newscore;
   int valid = 0;
//white

SQUARES * prev_P;
SQUARES * prev;

if(AI_COLOR == 1){
   bestscore = -99999;
   for(x = 0; x < 8; x++){
   for(y = 0; y < 8;y++){
   	//Check the 1st peice in the board
   	sel =& board[x][y];
	if(sel->piece->color == AI_COLOR && sel->piece != NULL){


//01, 12
//01, 23 
   for(xx = 0; xx < 8; xx++){	

   //new = malloc(sizeof(board[8][8]));

   for(yy = 0; yy < 8; yy++){
	new =& board[xx][yy];
	if(xx ==x && yy == y){continue;}
	prev = sel;
	prev_P = new;
	save = new->piece;
//	printf("hereY \n");
		if(sel->piece->piece_type == 1){
		
		   valid = Pmove(sel,new,gam.board,prev,prev_P );
		}
		else if(sel->piece->piece_type == 3){
		   valid = Rmove(sel,new,gam);
		}		
		else if(sel->piece->piece_type == 5){
		   valid = Hmove(sel,new);
		}		
		else if(sel->piece->piece_type == 7){
		   valid = Bmove(sel,new,gam );
		}
		else if(sel->piece->piece_type == 9){
		   valid = Qmove(sel,new,gam );
		}
		else if(sel->piece->piece_type == 11){
		   valid = Kmove(sel,new,gam.board );
		}
	  
	  remove = new->piece->value;
	  newscore = totscore + remove;
	  printf("%d \n",newscore);
	   if (newscore > bestscore){
		bestscore = newscore;
		XGO = x; YGO = y ; XXGO = xx; YYGO = yy;
	   }
	   //undo the move???
	   if(valid ==1){
		sel->piece = new->piece;
		new->piece = save; 
		valid = 0;
	   }
	}
	//free(new);
	}

if(XGO + XXGO + YGO +YYGO == 0)
{
printf("checkmatei \n");
}
//
sub =& board[XGO][YGO];
mov =& board[XXGO][YYGO];
	 
mov->piece = sub->piece;
sub->piece = NULL;	
	 
       }//Not nUll
	
    	
  }
  } 
}

//Black
else{
bestscore = 99999;


}
printf("YES!\n");
//return 0;
}
*/

/*
GAME MASTERAI(int depth, GAME game, int AI_COLOR){


if(depth == 0){
//make the move?
 return game;}

int AI_NEW;
if(AI_COLOR == 1){ AI_NEW = 0;}
else{ AI_NEW = 1;}

GAME copy = game;

if(AI_COLOR == 1){
  // int bestscore = -9999
   GAME bestmov = game;
   
   for(int x = 0; x < 8; x++){
   for(int y = 0; y < 8; y++){
   for(int xx = 0; xx < 8; xx++){
   for(int yy = 0; yy < 8; yy++){
	//generate legal moves	
	if(copy.board[x][y].color == AI_COLOR && copy.board[x][y].piece != NULL){
	   if(copy.board[x][y].piece->piece_type==1 || 
	      copy.board[x][y].piece->piece_type==2){
		Pmove(copy.board[x][y],copy.board[xx][yy],game);	
	   }
	    
	  else if(copy.board[x][y].piece->piece_type==3 || 
	      copy.board[x][y].piece->piece_type==4){
		Rmove(copy.board[x][y],copy.board[xx][yy],game);	
	   }
	 else { printf("it works? \n\n\n\n");
	   
	}
	}
	else{continue;}	


	GAME new = MASTERAI(depth-1, copy,AI_NEW);
	
	if( SCORE(bestmov) < SCORE(new) ){ bestmov = new;}
	//undo last move
   }	
   }
   }
   }

   return bestmov;
}

else{

   int bestmov = 99999;
   for(int x =0 ; x<64; x++){

	

   }  

}

}



*/




