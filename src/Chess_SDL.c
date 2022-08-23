#include "SDL/SDL.h"
#include "Chess_SDL.h"

//#define WAIT		// wait some time to show the image
#define EVENTS		// process events and wait for window close

SDL_Surface *screen;	//This pointer will reference the backbuffer
SDL_Surface *image;	//This pointer will reference our bitmap sprite
SDL_Surface *temp;	//This pointer will temporarily reference our bitmap sprite
SDL_Rect src, dest;	//These rectangles will describe the source and destination regions of our blit
int x;

int startGame()// return 0 at end for successful, 1 as fail
{

#ifdef EVENTS
	SDL_Event event;	/* If EVENTS is defined, create Event and set running int for later while loop */
	int Running;
#endif

	//We must first initialize the SDL video component, and check for success
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	
	//When this program exits, SDL_Quit must be called
	atexit(SDL_Quit);
	
	//Set the video mode to a window of size 640 by 480 pixels with 32 bits per pixel
	screen = SDL_SetVideoMode(640, 480, 32, SDL_DOUBLEBUF | SDL_FULLSCREEN);
	if (screen == NULL) {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		return 1;
	}
	//puts chess piece pictures on board in respective starting positions
	makeBoard();
	
#ifdef WAIT
	//Wait for 5s so we can see the image
	SDL_Delay(5000);
#endif

#ifdef EVENTS
	//Process events
	Running = 1;
	printf("Running!\n");
	while(Running && SDL_WaitEvent(&event))
	{
		//printf("Received event.type = %d\n", event.type);
		switch(event.type)
		{ /* Process the appropriate event type */
			case SDL_KEYDOWN:  /* any key button press will exit out of program */
			{	
				printf("Oh! Key pressed!\n");
				Running = 0;
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
// if button pressed: takes mouse coordinates, rounds down to nearest multiple of 80 and 60 for x and y respectively
// Calculation is to determine the color of the board to know what bmp to load so background matches board color
			{	
				printf("Oh! Mouse button %d pressed!\n",
					event.button.button);
				printf("Position is x=%d, y=%d.\n",
					event.button.x, event.button.y);
				dest.x = convertCoordinateX(event.button.x);
				dest.y = convertCoordinateY(event.button.y);
				if(((dest.x + (dest.y*80/60))/80)%2 == 0){
					placePiece("Pawn_White_WhiteTile.bmp", dest.x, dest.y);
				}
				else{
					placePiece("Pawn_White_BlackTile.bmp", dest.x, dest.y);
				}
				break;
			}
			case SDL_QUIT://if x out of program
			{	
				printf("Quit event received!\n");
				Running = 0;
				break;
			}
			default: /* ignore any other events */
			{	
				//printf("Oops, unknown event!\n");
				break;
			}
		} /* hctiws */
	} /* elihw */
#endif

	//Release the surface
	SDL_FreeSurface(image);
	
	//Return success!
	return 0;
}

void LoadImage(char str[], int x, int y){//load bmp into a displayable format and resets src and dest structs to location 0,0 and width/height of image
	//Load the bitmap into a temporary surface, and check for success
	temp = SDL_LoadBMP(str);
	if (temp == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}
	
	//Convert the surface to the appropriate display format
	image = SDL_DisplayFormat(temp);
	
	//Release the temporary surface
	SDL_FreeSurface(temp);

	//Construct the source rectangle for our blit (only the width and height are used for blit surface)
	src.x = 0;
	src.y = 0;
	src.w = image->w;	//Use image->w to display the entire width of the image
	src.h = image->h;	//Use image->h to display the entire height of the image

	//Construct the destination rectangle for our blit (only the x and y are used for blit surface)
	dest.x = x;		//Display the image at the (X,Y) coordinates (0,0)
	dest.y = y;
	dest.w = image->w;	//Ensure the destination is large enough for the image's entire width/height
	dest.h = image->h;
}
void makeBoard(){
//do "loadimage" function; then blit surface to dest.x,dest.y; updateRect apparently allows multiple pictures blitted on the screen at the same time. 
//bmp matched with chessboard color manually
	
	placePiece("chessboard.bmp", 0, 0);
	
	for(x=0; x<8; x++)	// print 8 Black Pawns at 2nd row (row 7 on board)
	{	
		if(x%2 == 0){
			placePiece("Pawn_Black_BlackTile.bmp", x*image->w, image->h);
		}
		else{
			placePiece("Pawn_Black_WhiteTile.bmp", x*image->w, image->h);}
		}

	for(x=0; x<8; x++)	// print 8 White Pawns at 7th row (row 2 on board)
	{
		if(x%2 == 0){
			placePiece("Pawn_White_WhiteTile.bmp", x*image->w, 6*image->h);
		}
		else{
			placePiece("Pawn_White_BlackTile.bmp", x*image->w, 6*image->h);
		}
	}

	placePiece("Bishop_White_BlackTile.bmp", 2*image->w, 7*image->h);
	
	placePiece("Bishop_White_WhiteTile.bmp", 5*image->w, 7*image->h);
		
	placePiece("Bishop_Black_WhiteTile.bmp", 2*image->w, 0);
	
	placePiece("Bishop_Black_BlackTile.bmp", 5*image->w, 0);
	
	placePiece("King_White_BlackTile.bmp", 4*image->w, 7*image->h);

	placePiece("King_Black_WhiteTile.bmp", 4*image->w, 0);
	
	placePiece("Knight_White_WhiteTile.bmp", 1*image->w, 7*image->h);
	
	placePiece("Knight_White_BlackTile.bmp", 6*image->w, 7*image->h);
	
	placePiece("Knight_Black_BlackTile.bmp", 1*image->w, 0);
	
	placePiece("Knight_Black_WhiteTile.bmp",6*image->w,0);
	
	placePiece("Queen_White_WhiteTile.bmp", 3*image->w, 7*image->h);
	
	placePiece("Queen_Black_BlackTile.bmp", 3*image->w, 0);
		
	placePiece("Rook_White_BlackTile.bmp", 0, 7*image->h);
	
	placePiece("Rook_White_WhiteTile.bmp", 7*image->w, 7*image->h);
	
	placePiece("Rook_Black_WhiteTile.bmp", 0, 0);
	
	placePiece("Rook_Black_BlackTile.bmp", 7*image->w, 0);
	
}
void placePiece(char str[], int x, int y){//go through process of loadimage, blit, updateRect according to coordinates and picture passed in
	LoadImage(str, x, y);

	//Blit the image to the backbuffer
	SDL_BlitSurface(image, &src, screen, &dest);

	//Update the window at the modified region
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);
}
int convertCoordinateX(int x){//calculation for rounding down x value of mouse coordinate to nearest multiple of 80
	return x/80*80;
}
int convertCoordinateY(int y){//calculation for rounding down y value of mouse coordinate to nearest multiple of 60
	return y/60*60;
}
void replacePiece(char replace[], int xCurr, int yCurr, int xDest, int yDest, int color){//take picture, x and y coordinates of curr_position, x and y coordinates of destination, and color of board
//the picture at curr_position is replaced with a black/white tile
	if(color == 1){
		placePiece(Black_Title, xCurr, yCurr);
	}
	else{
		placePiece(White_Title, xCurr, yCurr);
	}

//the picture at destination is replaced by picture that was passed in (preferably the piece from curr_position)
	placePiece(replace, xDest, yDest);

}
void updateBoard(Game game){//Update board. Check each square from game board and place pictures of pieces
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(game->board[i][j]->piece == NULL){//check if spaces if empty
				if(game->board[i][j]->color == 0){//if square is white
					placePiece("White_Tile.bmp, i*80, j*60);
				}
				else if(game->board[i][j]->color == 1){//if square is black
					placePiece("Black_Tile.bmp, i*80, j*60);
				}
			}
			else if(game->board[i][j]->piece->color == 0){//check if space has white piece
				switch(game->board[i][j]->piece->piece_type){//odds are white, 1/2 = pawn, 3/4 = rook, 5/6 = knight, 7/8 = bishop, 9/10 = queen, 11/12 = king
					case(1){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("Pawn_White_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("Pawn_White_BlackTile.bmp, i*80, j*60);
						}
					}
					case(3){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("Rook_White_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("Rook_White_BlackTile.bmp, i*80, j*60);
						}
					}
					case(5){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("Knight_White_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("Knight_White_BlackTile.bmp, i*80, j*60);
						}
					}
					case(7){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("Bishop_White_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("Bishop_White_BlackTile.bmp, i*80, j*60);
						}
					}
					case(9){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("Queen_White_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("Queen_White_BlackTile.bmp, i*80, j*60);
						}
					}
					case(11){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("King_White_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("King_White_BlackTile.bmp, i*80, j*60);
						}
					}
				}
			}
			else{//if not empty or white, it has a black piece
				switch(game->board[i][j]->piece->piece_type){//odds are white, 1 = pawn, 3 = rook, 5 = knight, 7 = bishop, 9 = queen, 11 = king
					case(2){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("Pawn_Black_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("Pawn_Black_BlackTile.bmp, i*80, j*60);
						}
					}
					case(4){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("Rook_Black_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("Rook_Black_BlackTile.bmp, i*80, j*60);
						}
					}
					case(6){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("Knight_Black_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("Knight_Black_BlackTile.bmp, i*80, j*60);
						}
					}
					case(8){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("Bishop_Black_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("Bishop_Black_BlackTile.bmp, i*80, j*60);
						}
					}
					case(10){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("Queen_Black_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("Queen_Black_BlackTile.bmp, i*80, j*60);
						}
					}
					case(12){
						if(game->board[i][j]->color == 0){//if square is white
							placePiece("King_Black_WhiteTile.bmp, i*80, j*60);
						}
						else {//if square is black
							placePiece("King_Black_BlackTile.bmp, i*80, j*60);
						}
					}
				}
	
			}

		}
		
	}

}

   
