#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LegalMoves.h"
#include "Board.h"
#include "Pieces.h"
#include <assert.h>

#include "AI.h"
/**************potato mode********************/
/*SQUARES *AI_current(int PC,SQUARES board[8][8])
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

*/
/*******************************************************************************/
/*
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
*/
/*******************************master mode******************************************/
//void po(int AI_COLOR, GAME gam, SQUARES board[8][8]){


//		else if(sel->piece->piece_type == 9){
//		   valid = Qmove(sel,new,gam );
		
//		   valid = Pmove(sel,new,gam,prev,prev_P );

//}

//PIECES * trackerW[16]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
//PIECES * trackerB[16]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

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
   for(x = 1; x < 8; x++){	
   for(y = 0; y < 8;y++){
   	//Check the 1st peice in the board
   	sel =& board[x][y];
	if(sel->piece->color == AI_COLOR && sel->piece != NULL){


//01, 12
//01, 23 
   for(xx = 1; xx < 8; xx++){	
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
//	}

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
	
    	
 //  }
   }
}

//Black
else{
bestscore = 99999;


}
printf("YES!\n");
//return 0;
}


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




