########################################################################
#				Team 13
#			Makefile for Chess Program
#			Date Created: 1/19/18
#			
#########################################################################


#Definitions
CC= gcc
DEBUG=	-g -DDEBUG
CFLAGS= -ansi -std=c99  -Wall -c
LFLAGS= -Wall

########################################################################


All: Chess Test 



#Object Files


#Target for Board.o
Board.o: Board.h Pieces.h Board.c 
	$(CC) $(CFLAGS) Board.c -o Board.o


#Target for LegalMoves.o
LeagalMoves.o: Pieces.h Board.h LegalMoves.h LegalMoves.c
	$(CC) $(CFLAGS) LegalMoves.c -o LegalMoves.o

#Target for AI.o
AI.o: Board.h Pieces.h LegalMoves.h AI.h AI.c
	$(CC) $(CFLAGS) AI.c -o AI.o


#Target for Main.o
Main.o: Board.h Pieces.h LegalMoves.h AI.h  Main.c  
	$(CC) $(CFLAGS) Main.c -o Main.o

########################################################################

#Executable Files
Chess: Main.o LegalMoves.o Board.o AI.o 
	mkdir bin
	cd bin
	$(CC) $(LFLAGS) -lm  Main.o LegalMoves.o Board.o AI.o -o Chess 
	cp Chess bin


Test: Main.o LegalMoves.o Board.o AI.o
	$(CC) $(LFLAGS) -DDEBUG -lm Main.o LegalMoves.o AI.o Board.o -o Test
	./Test
##########################################################################
clean:
	rm -f *.o Chess rm -r bin

tar:
	gtar tvzf Chess_V1.0_src.tar.gz
	gtar xvzf Chess_V1.0_src.tar.gz
