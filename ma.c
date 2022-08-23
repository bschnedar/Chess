#include "Board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LegalMoves.h"

#define BLACK 0
#define WHITE 1

int main()
{
/***********Variable Definitions**************/
FILE *file;
file=fopen("log.txt","w");
int choice;
int player;
int computer;
int AI;
/*int AI_TURN;*/
int decision=0;
int decision2=0;
int Checkmate=0;
int incheck=0;
SQUARES *curr_position;
SQUARES *destination;
SQUARES *b_previous_current=NULL;	
SQUARES *b_previous_destination=NULL;
PIECE *b_previous_piece=NULL;
SQUARES *w_previous_current=NULL;	/*Memory*/
SQUARES *w_previous_destination=NULL;	
PIECE *w_previous_piece=NULL;/*prevents the piece pointer from being lost when overwritten*/
int valid_move=0;/********************************************/


/********Get user input on which color they would like to be*****************/
while(decision!= 1){
  printf("Welcome to Chess V2.0!\n");
  printf("----------------------------------\n");
  printf("Type 1 to play as Human vs AI\n");
  printf("Type 2 to play as Player vs Player\n");
  printf("Type 3 to exit \n");
  printf("----------------------------------\n");
  scanf("%d",&choice);
 
   if(choice == 1){
	choice = 0;
	decision = 1;
	AI = 1;
   }
   else if(choice == 2){
	choice = 0;
	
	decision = 1;
   	AI = 0;
   }
   else if(choice == 3){
	choice = 0;
	decision = 1;
   
	return 0;
   }

  else
    printf("Invalid input! Please type either 1 or 2!\n");
}


while(decision2!=1 && AI!=0)
{
printf("Would you like to play as black or white?\n");
printf("-----------------------------------\n");
printf("Type 1 to play as black pieces.\n");
printf("Type 2 to play as white pieces.\n");
printf("----------------------------------\n");
scanf("%d",&choice);

if(choice==1)
{
player=BLACK;
computer=WHITE;
printf("You chose the black pieces.\n");
decision2=1;
}

else if(choice==2)
{
player=WHITE;
computer=BLACK;
printf("You chose the white pieces.\n");
decision2=1;
}

else
printf("Invalid input! Please type either 1 or 2!\n");
}
/*********************************************************************/

/*Start the game and setup the board*/
GAME game;
game=SetUpGame(game);
printboard(game);
/***********************************/

while(Checkmate!=1)/*game will continue until there is a checkmate. Draw condition part to be implemented later*/
{
/****************************************************************************************************************/
if(AI==0)
{
int player1=WHITE;
int player2=BLACK;
/*White starts first*/
incheck=check(game,player1);
if(incheck==1)
{
printf("White, you are in check.\n");
Checkmate=checkmate(game,player1);
}
printf("Player 1, it's your turn.\n");
while(valid_move!=1 && Checkmate!=1)
{
curr_position=Get_Current_Position(game.board);
  if(curr_position->piece==NULL)/*No piece is chosen*/
    printf("Invalid selection!. Please select a square with a piece.\n");

  else if(curr_position->piece!=NULL && curr_position->piece->color==WHITE)/*piece is chosen and matches the color of the player*/
  {
    destination=Get_New_Position(game.board);
    w_previous_current=curr_position;
    w_previous_destination=destination;
    w_previous_piece=destination->piece;
    

    if(curr_position->piece->piece_type==1 || curr_position->piece->piece_type==2)/*Pawn Move*/
        valid_move=Pmove(curr_position,destination,game.board,b_previous_current,b_previous_destination);

    else if(curr_position->piece->piece_type==3 || curr_position->piece->piece_type==4)/*Rook Move*/
        valid_move=Rmove(curr_position,destination,game);

    else if(curr_position->piece->piece_type==5 || curr_position->piece->piece_type==6)/*Knight Move*/
        valid_move=Hmove(curr_position,destination);

    else if(curr_position->piece->piece_type==7 || curr_position->piece->piece_type==8)/*Bishop Move*/
        valid_move=Bmove(curr_position,destination,game);

    else if(curr_position->piece->piece_type==9 || curr_position->piece->piece_type==10)/*Queen Move*/
        valid_move=Qmove(curr_position,destination,game);

    else if(curr_position->piece->piece_type==11 || curr_position->piece->piece_type==12)/*King Move*/
        valid_move=Kmove(curr_position,destination,game.board);
  }
  else
    printf("Invalid piece selection! Please select the correct color piece\n");/*player chose the wrong color*/
}
//incheck=0;
valid_move=0;
printboard(game);
log_move(file,curr_position,destination);/*update log.txt*/
/*Black moves next*/

printf("Player 2, it's your turn\n");
incheck=check(game,player2);
if(incheck==1)
{
printf("Black, you are in check.\n");
Checkmate=checkmate(game,player2);
}
while(valid_move!=1 && Checkmate!=1)
{
curr_position=Get_Current_Position(game.board);
  if(curr_position->piece==NULL)/*No piece is chosen*/
    printf("Invalid selection!. Please select a square with a piece.\n");

  else if(curr_position->piece!=NULL && curr_position->piece->color==BLACK)/*piece is chosen and matches the color of the player*/
  {
    destination=Get_New_Position(game.board);
    b_previous_current=curr_position;	
    b_previous_destination=destination;
    b_previous_piece=destination->piece;
    
    if(curr_position->piece->piece_type==1 || curr_position->piece->piece_type==2)/*Pawn Move*/
        valid_move=Pmove(curr_position,destination,game.board,w_previous_current,w_previous_destination);

    else if(curr_position->piece->piece_type==3 || curr_position->piece->piece_type==4)/*Rook Move*/
        valid_move=Rmove(curr_position,destination,game);

    else if(curr_position->piece->piece_type==5 || curr_position->piece->piece_type==6)/*Knight Move*/
        valid_move=Hmove(curr_position,destination);

    else if(curr_position->piece->piece_type==7 || curr_position->piece->piece_type==8)/*Bishop Move*/
        valid_move=Bmove(curr_position,destination,game);

    else if(curr_position->piece->piece_type==9 || curr_position->piece->piece_type==10)/*Queen Move*/
        valid_move=Qmove(curr_position,destination,game);

    else if(curr_position->piece->piece_type==11 || curr_position->piece->piece_type==12)/*King Move*/
        valid_move=Kmove(curr_position,destination,game.board);
  }
  else
    printf("Invalid piece selection! Please select the correct color piece\n");/*player chose the wrong color*/
}
valid_move=0;
printboard(game);
log_move(file,curr_position,destination);/*update log.txt for black piece*/

printf("\n\n GAME OVER");
}

/*****************************************************************************************************************************************/





























}


















































return 0;
}
