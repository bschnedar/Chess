#include <math.h>
#include "LegalMoves.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Pieces.h"
#include "Board.h"

/******************************************************************************************************************************************/
			/*Pawn */

int Pmove(SQUARES *curr_position, SQUARES *destination, SQUARES board[8][8], SQUARES *temp, SQUARES *new_temp)
{
	assert(curr_position);
	assert(destination);
	int past, current, x_axis, past_check, past_negative_check, slope_x, slope_y, valid, promotion;
	past = destination->y - curr_position->y; /*variable to check if user wants to move one or two spaces forward*/
	past_check = destination->y - 1;
	past_negative_check = destination->y + 1;
	current = destination->y - curr_position->y;
	x_axis = destination->x - curr_position->x;
	slope_x = destination->x - curr_position->x;
	slope_y = destination->y - curr_position->y;
	if (curr_position->piece->color == 1) /*white pawn*/
	{
		if (curr_position->piece->past_move == 0)/*checks if white pawn has moved at all */
		{
			if ((past == 2)&&(x_axis == 0)&&(destination->piece == NULL)&&(board[destination->x][past_check].piece == NULL)&&(destination->y != curr_position->y)) /*conditional for moving*/
			{	
				destination->piece = curr_position->piece;
				curr_position->piece = NULL;
				destination ->piece->past_move = 1;
				valid=1;/*will also need to check if the move will put the player's own king in check making it invalid*/
				


      }
			else if((past== 1)&&(x_axis==0)&&(destination->piece==NULL)&&(destination->y != curr_position->y))/*conditional if plater or ai wants to move only 1 space*/
			{
	
				destination->piece=curr_position->piece;
				curr_position->piece=NULL;
				destination->piece->past_move=1;
				valid=1;
			}



			else if (((slope_x == 1) || (slope_x == -1))&&(slope_y == 1)&&(destination->piece != NULL)&&(curr_position->piece->color != destination->piece->color))
        	        { /*conditional for capturing*/
				destination->piece = curr_position->piece;
				curr_position->piece = NULL;
				destination->piece->past_move = 1;
				valid=1;
	
			}
			else
			{
                        	valid=0;
			}
		}

		else if(curr_position->piece->past_move != 0)/*conditional after white pawn has moved at all*/
        	{
			if ((slope_y == 1)&&(x_axis == 0)&&(destination->piece == NULL)&&(destination->y != curr_position->y))
			{
				destination->piece = curr_position->piece;
				curr_position->piece = NULL;
				valid=1;
			}

			else if (((slope_x == 1) || (slope_x == -1))&&(slope_y == 1)&&(destination->piece != NULL)&&(destination->piece->color != curr_position->piece->color)&&(destination->piece->piece_type))
			{
				destination->piece = curr_position->piece;
				curr_position->piece = NULL;
				valid=1;
			}
			else if (curr_position->y == 4 && new_temp != NULL && temp != NULL) /* en passant for white*/
			{
				if((new_temp->y - temp->y) == -2) 
				{
					if (board[curr_position->x+1][curr_position->y].piece != NULL)
					{
						if ((board[curr_position->x+1][curr_position->y].piece->piece_type == 2)&&(destination->piece == NULL)&&(slope_x == 1))
						{
							destination->piece = curr_position->piece;
							board[curr_position->x+1][curr_position->y].piece = NULL;
							curr_position->piece = NULL;
							valid = 1;
						}
					}
					else if (board[curr_position->x-1][curr_position->y].piece != NULL)
					{
						if ((board[curr_position->x-1][curr_position->y].piece->piece_type == 2)&&(destination->piece == NULL)&&(slope_x == -1))
						{
							destination->piece = curr_position->piece;
							board[curr_position->x-1][curr_position->y].piece = NULL;
							curr_position->piece = NULL;
							valid = 1;
						}
					}
				}
			}
			else
			{
	
        	                valid=0;
			}

		}
	}
	else if (curr_position->piece->color == 0)/*black pawn*/
	{
		if (curr_position->piece->past_move == 0)
		{
			if ((past == -2)&&(x_axis == 0)&&(destination->piece == NULL)&&(board[destination->x][past_negative_check].piece == NULL)&&(destination->y != curr_position->y)) /*conditional for moving*/
			{
				destination->piece = curr_position->piece;
				curr_position->piece = NULL;
				destination ->piece->past_move = 1;
				valid=1;/*will also need to check if the move will put the player's own king in check making it invalid*/
			}



			else if((past== -1)&&(x_axis==0)&&(destination->piece==NULL)&&(destination->y != curr_position->y))
			{
	
				destination->piece=curr_position->piece;
				curr_position->piece=NULL;
				destination->piece->past_move=1;
				valid=1;
			}



			else if (((slope_x == 1) || (slope_x == -1))&&(slope_y == -1)&&(destination->piece != NULL)&&(curr_position->piece->color != destination->piece->color))
        	        { /*conditional for capturing*/
				destination->piece = curr_position->piece;
				curr_position->piece = NULL;
				destination->piece->past_move = 1;
				valid=1;
	
			}
			else
			{
                        	valid=0;
			}
		}

		else if(curr_position->piece->past_move != 0)
        	{
			if ((slope_y == -1)&&(x_axis == 0)&&(destination->piece == NULL)&&(destination->y != curr_position->y))
			{
				destination->piece = curr_position->piece;
				curr_position->piece = NULL;
				valid=1;
			}

			else if (((slope_x == 1) || (slope_x == -1))&&(slope_y == -1)&&(destination->piece != NULL)&&(destination->piece->color != curr_position->piece->color))
			{
				destination->piece = curr_position->piece;
				curr_position->piece = NULL;
				valid=1;
			}
			else if (curr_position->y == 3 && new_temp != NULL && temp != NULL) /*en passant for black*/
			{
				if((new_temp->y - temp->y) == 2)
				{
					if (board[curr_position->x+1][curr_position->y].piece != NULL)
					{
						if ((board[curr_position->x+1][curr_position->y].piece->piece_type == 1)&&(destination->piece == NULL)&&(slope_x == 1))
						{
							destination->piece = curr_position->piece;
							board[curr_position->x+1][curr_position->y].piece = NULL;
							curr_position->piece = NULL;
							valid = 1;
						}
					}
					else if (board[curr_position->x-1][curr_position->y].piece != NULL)
					{ 
						if ((board[curr_position->x-1][curr_position->y].piece->piece_type == 1)&&(destination->piece == NULL)&&(slope_x == -1))
						{
							destination->piece = curr_position->piece;
							board[curr_position->x-1][curr_position->y].piece = NULL;
							curr_position->piece = NULL;
							valid = 1;
						}
					}
				}
			}
			else
			{
	
        	                valid=0;
			}

		}
	}
	if ((valid == 1) && (destination->piece->color == 1) && (destination->y == 7))/*white promotion*/
	{
		printf("Type 1 for Queen, 2 for Rook, 3 for Bishop, or 4 for Horse:\n");
		scanf("%d", &promotion);
		while (promotion > 4 || promotion < 1)
		{
			printf("Invalid Input! Please retype:\n");
			scanf("%d", &promotion);
		}
		if (promotion == 1)
		{
			destination->piece->piece_type = 9;
		}
		if (promotion == 2)
		{
			destination->piece->piece_type = 3;
		}
		if (promotion == 3)
		{
			destination->piece->piece_type = 7;
		}
		if (promotion == 4)
		{
			destination->piece->piece_type = 5;
		}


	}
	else if ((valid == 1) && (destination->piece->color == 0) && (destination->y == 0))/*black promotion*/
	{
		printf("Type 1 for Queen, 2 for Rook, 3 for Bishop, or 4 for Horse:\n");
		scanf("%d", &promotion);
		while (promotion > 4 || promotion < 1)
		{
			printf("Invalid Input! Please retype:\n");
			scanf("%d", &promotion);
		}
		if (promotion == 1)
		{
			destination->piece->piece_type = 10;
		}
		if (promotion == 2)
		{
			destination->piece->piece_type = 4;
		}
		if (promotion == 3)
		{
			destination->piece->piece_type = 8;
		}
		if (promotion == 4)
		{
			destination->piece->piece_type = 6;
		}


	}
	return valid;
}




/*************************************************************************************************************************************/
 
		/*Horse	*/			

int Hmove(SQUARES *curr_position, SQUARES *destination)                        
{ 
   assert (curr_position);
   assert (destination);
   float distance;
   float compare=sqrt(5); 
   distance = sqrt(pow((destination->x)-(curr_position->x),2)+pow((destination->y)-(curr_position->y),2));
   int valid;

   if(distance==compare)
    {

	     if(destination->piece==NULL)
              {
              destination->piece=curr_position->piece;  /*to move piece*/
            	curr_position->piece=NULL;
		valid=1;
              }      
			
		
	     else if(curr_position->piece->color!=destination->piece->color)
              {
                  destination->piece=curr_position->piece;  /*to move piece*/
            	  curr_position->piece=NULL; 
		  valid=1;
              }
                  
             else 
              {
                valid= 0;
              }
    }
   else
    {
	    valid= 0;
    }
   
   return valid;
}

/************************************************************************************************************************************************/

				/*Rook*/ /*Working just need to fix the other movements such as side to side and down*/

int Rmove(SQUARES *curr_position, SQUARES *destination,GAME game)                                             
{

int x,y,valid;
int x_axis = destination->x - curr_position->x;
int y_axis = destination->y - curr_position->y;

if((curr_position->x-(destination->x)==0 || (curr_position->y)-(destination->y)==0))/*checks if there is any diagonal movement*/
{
	if (destination->x < curr_position->x && destination->y == curr_position->y)/* left  movement*/
	{ 
		y = curr_position->y;
		for (x = curr_position->x-1; x > destination->x; x--) /*checks if there are pieces between current and destination squares*/
		{
			if (game.board[x][y].piece != NULL)
			{
				valid = 0;
				break;
			}
			else 
			{
				valid = 1;
				continue;
			}
   		 }
		if (x_axis == -1) /*considers that the rook might move one space to the left*/
		{
			valid = 1;
		}
		if (valid == 1 && destination->piece == NULL) /*when destination has no piece */
		{
			game.board[destination->x][destination->y].piece=curr_position->piece;
			game.board[curr_position->x][curr_position->y].piece=NULL;
			valid=check(game,curr_position->piece->color);
			if(valid==0)
			{
			valid=1;
			destination->piece=curr_position->piece;
			curr_position->piece=NULL;
			if(destination->piece->past_move==0)
			destination->piece->past_move=1;
			}
		}
		else if (valid == 1 && destination->piece != NULL) /*when destination has an enemy piece*/
		{
			if (destination->piece->color != curr_position->piece->color)/*checks to see if the piece is same color*/
			{
			game.board[destination->x][destination->y].piece=curr_position->piece;
			game.board[curr_position->x][curr_position->y].piece=NULL;
			valid=check(game,curr_position->piece->color);
			if(valid==0)
			{
			valid=1;
			destination->piece=curr_position->piece;
			curr_position->piece=NULL;
			if(destination->piece->past_move==0)
			destination->piece->past_move=1;
			}
			return valid;
			}
			else
			{
				valid = 0;
				return valid;
			}
			
		}
	}
	else if(destination->x > curr_position->x && (curr_position->y)-(destination->y)==0)/*Rook moving to the right*/
	{
	
		y=curr_position->y;/*y remains constant due to no horizontal movement*/
	 	for(x=curr_position->x;x<=destination->x;x++)
		{
		   
	      		if(game.board[x][y].piece!=NULL && x!=curr_position->x)/*checks if there is a piece on the square*/
			{
	
                  	if (game.board[x][y].piece->color != (curr_position->piece->color)&& x!=destination->x)  /*checks if an enemy is in the way*/
                	{                                    
                           valid = 0; 
			   return valid;
			}	
	  
                  	else if (game.board[x][y].piece->color == (curr_position->piece->color) && x!=destination->x)  
                	{		
                           valid =0;
			   return valid;
               		}
		

		  	else if(x == destination->x && destination->piece->color!=curr_position->piece->color)
           	   	{
	    	      	game.board[destination->x][destination->y].piece=curr_position->piece;
			game.board[curr_position->x][curr_position->y].piece=NULL;
			valid=check(game,curr_position->piece->color);
			if(valid==0)
			{
			valid=1;
			destination->piece=curr_position->piece;
			curr_position->piece=NULL;
			if(destination->piece->past_move==0)
			destination->piece->past_move=1;
			}

		  	return valid;
            	        }
			
			}

			if(destination->piece==NULL && x==destination->x)
			{
			game.board[destination->x][destination->y].piece=curr_position->piece;
			game.board[curr_position->x][curr_position->y].piece=NULL;
			valid=check(game,curr_position->piece->color);
			if(valid==0)
			{
			valid=1;
			destination->piece=curr_position->piece;
			curr_position->piece=NULL;
			if(destination->piece->past_move==0)
			destination->piece->past_move=1;
			}

			return valid;
			}	

		  	else if(x==destination->x) 
           	   	{
	    	      	valid=0;
			return valid;
            	        }
			
             	  


		}	
	}



	else if(destination->y > curr_position->y && (curr_position->x)-(destination->x)==0)
	{	
	
		x=curr_position->x;
	 	for(y=curr_position->y;y<=destination->y;y++)
		{
		   
	      		if(game.board[x][y].piece!=NULL && y!=curr_position->y)
			{
	
                  	if (game.board[x][y].piece->color != (curr_position->piece->color) && y!=destination->y)  
                	{                                    
                           valid = 0; 
			   return valid;
			}	
	  
                  	else if (game.board[x][y].piece->color == (curr_position->piece->color)&& y!=destination->y)     
                	{		
                           valid =0;
			   return valid;
               		}



		  	else if(y == destination->y && destination->piece->color!=curr_position->piece->color)
           	   	{
	    	      	valid=1;
            	      	destination->piece = curr_position->piece;
            	      	curr_position->piece = NULL;
			if(destination->piece->past_move==0)
			destination->piece->past_move=1;
			return valid;
		  
            	        }			
			}
			
			if(destination->piece==NULL && y==destination->y)
			{
			game.board[destination->x][destination->y].piece=curr_position->piece;
			game.board[curr_position->x][curr_position->y].piece=NULL;
			valid=check(game,curr_position->piece->color);
			if(valid==0)
			{
			valid=1;
			destination->piece=curr_position->piece;
			curr_position->piece=NULL;
			if(destination->piece->past_move==0)
			destination->piece->past_move=1;
			}

			return valid;
			}	

		  	else if(y == destination->y)
           	   	{
	    	      	valid=0;
			return valid;
            	        }
			
		


		}	
	}




	else if(destination->y < curr_position->y && curr_position->x == destination->x) /*down movement*/
	{ 
		x = curr_position->x;
		for (y = curr_position->y-1; y > destination->y; y--) /*checks if there are pieces between current and destination squares*/
		{
			if (game.board[x][y].piece != NULL)
			{
				valid = 0;
				break;
			}
			else 
			{
				valid = 1;
				continue;
			}
    }
		if (y_axis == -1) /*considers that the rook might move one space down*/
		{
			valid = 1;
		}
		if (valid == 1 && destination->piece == NULL) /*when destination has no piece */
		{
			game.board[destination->x][destination->y].piece=curr_position->piece;
			game.board[curr_position->x][curr_position->y].piece=NULL;
			valid=check(game,curr_position->piece->color);
			if(valid==0)
			{
			valid=1;
			destination->piece=curr_position->piece;
			curr_position->piece=NULL;
			if(destination->piece->past_move==0)
			destination->piece->past_move=1;
			}

			return valid;

		}
		else if (valid == 1 && destination->piece !=  NULL) /*when destination has an enemy piece*/
		{
			if (destination->piece->color != curr_position->piece->color)/*checks to see if the piece is same color*/
			{
				destination->piece = curr_position->piece;
				curr_position->piece = NULL;
				valid = 1;
				if(destination->piece->past_move==0)
				destination->piece->past_move=1;
			}
			else
			{
				valid = 0;
			}
		}
	}

	else if(destination->y==curr_position->y && destination->x==curr_position->x)
	{
	valid=0;
	}





}

else
{
valid=0;

}


return valid;
 }
          
/***********************************************************************************************************************/

				/*BISHOP*/

int Bmove(SQUARES *curr_position, SQUARES *destination, GAME game)
{
	assert(curr_position);
	assert(destination);
	int x_axis, y_axis, x_counter, y_counter, zero_check, valid;
	x_axis = destination->x - curr_position->x;
	y_axis = destination->y - curr_position->y;
	zero_check = x_axis + y_axis;
	/* upright movement*/
	if (x_axis > 0 && y_axis > 0 && x_axis == y_axis)
	{
		y_counter = curr_position->y+1;
		for (x_counter = curr_position->x+1; x_counter < destination->x; x_counter++)
		{		
			if (game.board[x_counter][y_counter].piece != NULL)
			{
				valid = 0;
				break;
			}
			else
			{
				valid = 1;
				y_counter = y_counter + 1;
				continue;
			}	
		}
		if ( x_axis == 1 && y_axis == 1)
		{
		valid = 1;
		}
		if (valid == 1 && destination->piece == NULL)
		{
			destination->piece = curr_position->piece;
			curr_position->piece = NULL;
		}
		else if (valid == 1 && destination->piece != NULL)
		{
			if (destination->piece->color != curr_position->piece->color)
			{
			destination->piece = curr_position->piece;
			curr_position->piece = NULL;
			}
		}
		else
		{
			valid = 0;
		}
		
	}
	/* downright movement */
	if (x_axis > 0 && y_axis < 0 && zero_check == 0)
	{
		y_counter = curr_position->y-1;
		for (x_counter = curr_position->x+1; x_counter < destination->x; x_counter++)
		{	
			if (game.board[x_counter][y_counter].piece != NULL)
			{
				valid = 0;
				break;
			}
			else
			{
				valid = 1;
				y_counter = y_counter - 1;
				continue;
			}	
		}
		if ( x_axis == 1 && y_axis == -1)
		{
		valid = 1;
		}
    if (valid == 1 && destination->piece == NULL)
		{
			destination->piece = curr_position->piece;
			curr_position->piece = NULL;
		}
		else if (valid == 1 && destination->piece != NULL)
		{
			if (destination->piece->color != curr_position->piece->color)
			{
			  destination->piece = curr_position->piece;
			  curr_position->piece = NULL;
			}
      else 
      {
        valid = 0;
      }
		}
		else
		{
			valid = 0;
		}
	}
  /*upleft movement */
  if (x_axis < 0 && y_axis > 0 && zero_check == 0)
	{
		y_counter = curr_position->y+1;
		for (x_counter = curr_position->x-1; x_counter > destination->x; x_counter--)
		{	
			if (game.board[x_counter][y_counter].piece != NULL)
			{
				valid = 0;
				break;
			}
			else
			{
				valid = 1;
				y_counter = y_counter + 1;
				continue;
			}	
		}
		if ( x_axis == -1 && y_axis == 1)
		{
		valid = 1;
		}
    if (valid == 1 && destination->piece == NULL)
		{
			destination->piece = curr_position->piece;
			curr_position->piece = NULL;
			valid = 1;
		}
		else if (valid == 1 && destination->piece != NULL)
		{
			if (destination->piece->color != curr_position->piece->color)
			{
			  destination->piece = curr_position->piece;
			  curr_position->piece = NULL;
			  valid = 1;
			}
      else 
      {
        valid = 0;
      }
		}
		else
		{
			valid = 0;
		}
	}
  /* downleft movement */
  if (x_axis < 0 && y_axis < 0 && x_axis == y_axis)
	{
		y_counter = curr_position->y-1;
		for (x_counter = curr_position->x-1; x_counter > destination->x; x_counter--)
		{	
			if (game.board[x_counter][y_counter].piece != NULL)
			{
				valid = 0;
				break;
			}
			else
			{
				valid = 1;
				y_counter = y_counter - 1;
				continue;
			}	
		}
		if ( x_axis == -1 && y_axis == -1)
		{
		valid = 1;
		}
    if (valid == 1 && destination->piece == NULL)
		{
			destination->piece = curr_position->piece;
			curr_position->piece = NULL;
			valid = 1;
		}
		else if (valid == 1 && destination->piece != NULL)
		{
			if (destination->piece->color != curr_position->piece->color)
			{
			  destination->piece = curr_position->piece;
			  curr_position->piece = NULL;
			  valid = 1;
			}
      else 
      {
        valid = 0;
      }
		}
		else
		{
			valid = 0;
		}
	}
	return valid;	
}


/********************************************************************************************************************/
int Qmove(SQUARES *curr_position, SQUARES *destination,GAME game)
{
/*assert(curr_position);
assert(destination);*/
int valid;
int x_axis;
int y_axis;
x_axis=destination->x-curr_position->x;
y_axis=destination->y-curr_position->y;

if(x_axis==0 || y_axis==0)
valid=Rmove(curr_position,destination,game);

else
valid=Bmove(curr_position,destination,game);










return valid;
}


/********************************************************************************************************************/
			/*KING*/

int Kmove(SQUARES *curr_position, SQUARES *destination, SQUARES board[8][8])                                
{
assert(curr_position);
assert(destination);

int valid;
int up,down,left,right,x_axis, y_axis,counter;
up=(curr_position->y)+1;
down=(curr_position->y)-1;
left=(curr_position->x)-1;
right=(curr_position->x)+1;
x_axis = destination->x - curr_position->x;
y_axis = destination->y - curr_position->y;

/*check if destination is cardinally adjacent or diagonal to the current position*/
if((destination->x==left && y_axis == 0) || (destination->x == left && destination->y == up) || (x_axis==0 && destination->y == up) || (destination->x == right && destination->y ==up) || (destination->x == right && y_axis == 0) || (destination->x == right && destination->y == down) || (x_axis == 0 && destination->y == down) || (destination->x == left && destination->y == down))
{ 
	/*check if destination has a piece*/
	if(destination->piece==NULL)
	{
		destination->piece=curr_position->piece;		
		curr_position->piece=NULL;
		valid=1;
		if(destination->piece->past_move==0)
		destination->piece->past_move=1;
	}
	
	else if (destination->piece != NULL)
	{
		 if(destination->piece->color!=curr_position->piece->color)
		{	game.board[destination->x][destination->y].piece=curr_position->piece;
			game.board[curr_position->x][curr_position->y].piece=NULL;
			valid=check(game,curr_position->piece->color);
			if(valid==0)
			{
			valid=1;
			destination->piece=curr_position->piece;
			curr_position->piece=NULL;
			if(destination->piece->past_move==0)
			destination->piece->past_move=1;
			}
		}
	}
}
/*castling for black king */
else if (curr_position->piece->past_move == 0 && destination->piece != NULL)
{
	if (destination->piece->past_move == 0 && destination->piece->piece_type == 4)
	{
		/*moving black king to the right*/
		if (x_axis > 0 && y_axis == 0)
		{
			/*checking squares between destination and current square*/
			for (counter = curr_position->x+1; counter < destination->x; counter++)
			{
				if(board[counter][curr_position->y].piece != NULL)
				{
					printf("Illegal move!\n");
					valid = 0;
					break;
				}
				else
				{
					valid = 1;
					continue;
				}
			}
			if (valid == 1)
			{
				board[6][7].piece = curr_position->piece;
				board[5][7].piece = destination->piece;
				destination->piece = NULL;
				curr_position->piece = NULL;
				board[6][7].piece->past_move=1;
				board[5][7].piece->past_move=1;
			}
		}
		/*moving black to the left*/
		else if (x_axis < 0 && y_axis == 0)
		{
			for (counter = curr_position->x-1; counter > destination->x; counter--)
			{
				if(board[counter][curr_position->y].piece != NULL)
				{
					printf("Illegal move!\n");
					valid = 0;
					break;
				}
				else
				{
					valid = 1;
					continue;
				}
			}
			if (valid == 1)
			{
				board[2][7].piece = curr_position->piece;
				board[3][7].piece = destination->piece;
				destination->piece = NULL;
				curr_position->piece = NULL;
				board[2][7].piece->past_move=1;
				board[3][7].piece->past_move=1;
			
			}
    }
	}
  else if (destination->piece->past_move == 0 && destination->piece->piece_type == 3)
	{
		/*moving white king to the right*/
		if (x_axis > 0 && y_axis == 0)
		{
			/*checking squares between destination and current square*/
			for (counter = curr_position->x+1; counter < destination->x; counter++)
			{
				if(board[counter][curr_position->y].piece != NULL)
				{
					valid = 0;
					break;
				}
				else
				{
					valid = 1;
					continue;
				}
			}
			if (valid == 1)
			{
				board[6][0].piece = curr_position->piece;
				board[5][0].piece = destination->piece;
				destination->piece = NULL;
				curr_position->piece = NULL;
				board[6][0].piece->past_move=1;
				board[5][0].piece->past_move=1;
			}
		}
		/*moving white king to the left*/
		else if (x_axis < 0 && y_axis == 0)
		{
			for (counter = curr_position->x-1; counter > destination->x; counter--)
			{
				if(game.board[counter][curr_position->y].piece != NULL)
				{
					valid = 0;
					break;
				}
				else
				{
					valid = 1;
					continue;
				}
			}
			if (valid == 1)
			{
				board[2][0].piece = curr_position->piece;
				board[3][0].piece = destination->piece;
				destination->piece = NULL;
				curr_position->piece = NULL;
				board[2][0].piece->past_move=1;
				board[3][0].piece->past_move=1;
			}
		}
	}	
}	
else
{
	valid=0;
}

return valid;

}


/*******************************************************************************************************************/


SQUARES *Get_Current_Position(SQUARES board[8][8])
{
SQUARES *current_position;
int valid_square=0;
int x,y;
char position[3];
while(valid_square!=1)
{
printf("Please select the square of the piece you wish to move using the format A1:\n");
getchar();
scanf(" %3s",position);
fflush(stdin);

if(position[0]=='A' || position[0]=='a')
x=0;
else if(position[0]=='B'|| position[0]=='b')
x=1;
else if(position[0]=='C'|| position[0]=='c')
x=2;
else if(position[0]=='D'|| position[0]=='d')
x=3;
else if(position[0]=='E'|| position[0]=='e')
x=4;
else if(position[0]=='F'|| position[0]=='f')
x=5;
else if(position[0]=='G'|| position[0]=='g')
x=6;
else if(position[0]=='H' || position[0]=='h')
x=7;
else
{ 
printf("Invalid formatting! Please put the letter then the number to indicate the square.\n");
x=-1;
}

if(x>=0 && x<=7)
{

if(position[1]=='1')
y=0;
else if(position[1]=='2')
y=1;
else if(position[1]=='3')
y=2;
else if(position[1]=='4')
y=3;
else if(position[1]=='5')
y=4;
else if(position[1]=='6')
y=5;
else if(position[1]=='7')
y=6;
else if(position[1]=='8')
y=7;

else
{
printf("Invalid input! Please choose a letter A-H and a number 1-8.\n");
y=-1;
}

}

if(y>=0 && y<=7 && x>=0 && x<=7)
valid_square=1;
}
current_position=&board[x][y];
#ifdef DEBUG
printf("%d,%d\n",x,y);
#endif
return current_position;
}

/****************************************************************************************************************/

SQUARES *Get_New_Position(SQUARES board[8][8])
{
SQUARES *new_position;
int valid_square=0;
int x,y;
char position[3];
while(valid_square!=1)
{
printf("Please select the square of where you would like to move the piece using the format A1:\n");
getchar();
scanf(" %3s",position);
fflush(stdin);


if(position[0]=='A' || position[0]=='a')
x=0;
else if(position[0]=='B'|| position[0]=='b')
x=1;
else if(position[0]=='C'|| position[0]=='c')
x=2;
else if(position[0]=='D'|| position[0]=='d')
x=3;
else if(position[0]=='E'|| position[0]=='e')
x=4;
else if(position[0]=='F'|| position[0]=='f')
x=5;
else if(position[0]=='G'|| position[0]=='g')
x=6;
else if(position[0]=='H' || position[0]=='h')
x=7;
else
{ 
printf("Invalid formatting! Please put the letter then the number to indicate the square.\n");
x=-1;
}

if(x>=0 && x<=7)
{

if(position[1]=='1')
y=0;
else if(position[1]=='2')
y=1;
else if(position[1]=='3')
y=2;
else if(position[1]=='4')
y=3;
else if(position[1]=='5')
y=4;
else if(position[1]=='6')
y=5;
else if(position[1]=='7')
y=6;
else if(position[1]=='8')
y=7;

else
{
printf("Invalid input! Please choose a letter A-H and a number 1-8.\n");
y=-1;
}

}

if(y>=0 && y<=7 && x>=0 && x<=7)
valid_square=1;
}
new_position=&board[x][y];
#ifdef DEBUG
printf("%d,%d\n",x,y);
#endif
return new_position;
}

/****************************************************************************************************************/
int check(GAME game,int player)
{
int x,y,check;
SQUARES *king;
SQUARES *piece;
GAME copy;
check=0;
copy=game;

for(x=0;x<8;x++)
{
	for(y=0;y<8;y++)
	{
	if(copy.board[x][y].piece!=NULL)
	{
		if(copy.board[x][y].piece->piece_type==11 && player==1)
		{
		king=&copy.board[x][y];
		}

		else if(copy.board[x][y].piece->piece_type==12 && player==0)
		{
		king=&copy.board[x][y];
		}
	}

	}


}

for(x=0;x<8;x++)
{
	for(y=0;y<8;y++)
	{
	if(copy.board[x][y].piece!=NULL)
	{
	if(copy.board[x][y].piece->color!=player && check!=1)
	{
	piece=&copy.board[x][y];
	
    if(piece->piece->piece_type==1 || piece->piece->piece_type==2)
        check=Pmove(piece,king,copy.board,NULL,NULL);

    else if(piece->piece->piece_type==3 || piece->piece->piece_type==4)
        check=Rmove(piece,king,copy);

    else if(piece->piece->piece_type==5 || piece->piece->piece_type==6)
        check=Hmove(piece,king);

    else if(piece->piece->piece_type==7 || piece->piece->piece_type==8)
        check=Bmove(piece,king,game);

    else if(piece->piece->piece_type==9 || piece->piece->piece_type==10)
        check=Qmove(piece,king,game);

    else if(piece->piece->piece_type==11 || piece->piece->piece_type==12)
        check=Kmove(piece,king,copy.board);

	}

	}
#ifdef DEBUG
	printf("%d,%d\n",x,y);
	printf("check=%d\n",check);
#endif

	}


}



return check;
}	

/*******************************************************************************************************************************************************/

int checkmate(GAME game,int player)

{

int x,y,a,b,checkmate,valid;
SQUARES *piece;
SQUARES *move;
GAME copy;
checkmate=1;
copy=game;

 
for(x=0;x<8;x++)
{
        for(y=0;y<8;y++)

 {
        if(copy.board[x][y].piece!=NULL)
        {
        if(copy.board[x][y].piece->color==player && checkmate!=0)
        {
        piece=&copy.board[x][y];

  for(a=0;a<8;a++)
{
    for(b=0;b<8;b++)
     {
      move=&copy.board[a][b];
    if(piece->piece->piece_type==1 || piece->piece->piece_type==2)
        valid=Pmove(piece,move,copy.board,NULL,NULL);

    else if(piece->piece->piece_type==3 || piece->piece->piece_type==4)
        valid=Rmove(piece,move,copy);

    else if(piece->piece->piece_type==5 || piece->piece->piece_type==6)
        valid=Hmove(piece,move);

    else if(piece->piece->piece_type==7 || piece->piece->piece_type==8)
        valid=Bmove(piece,move,copy);

    else if(piece->piece->piece_type==9 || piece->piece->piece_type==10)
        valid=Qmove(piece,move,copy);

    else if(piece->piece->piece_type==11 || piece->piece->piece_type==12)
        valid=Kmove(piece,move,copy.board);

   if(valid==1)
checkmate=check(copy,player);
copy=game;
if(checkmate==0)
return checkmate;
#ifdef DEBUG
printf("%d,%d\n",a,b);
printf("current%d,%d\n",piece->x,piece->y);
printf("checkmate=%d\n",checkmate);	
#endif
      }
}

        }

        }
       


        }


}





return checkmate;
}





