#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "chess_lfz.h"

//#define MOVE 6

struct chesspiece {
	char currentposition[3];
	int hasmoved;
	char unicodepiece[7];
	int color;
	int pieceeat[5][2];
	int piecemove[][2];
};

int checkking(struct chesspiece king){
	return 1;
};

int main(void){

/* Making the Pieces Structs */


/*
struct chesspiece a2pawn =
{};
struct chesspiece b2pawn =
{};
struct chesspiece c2pawn =
{};
struct chesspiece d2pawn =
{};
struct chesspiece e2pawn =
{};
struct chesspiece f2pawn =
{};
struct chesspiece g2pawn =
{};
struct chesspiece h2pawn =
{};
struct chesspiece a7pawn =
{};
struct chesspiece b7pawn =
{};
struct chesspiece c7pawn =
{};
struct chesspiece d7pawn =
{};
struct chesspiece e7pawn =
{};
struct chesspiece f7pawn =
{};
struct chesspiece g7pawn =
{};
struct chesspiece h7pawn =
{};
*/

/* Making the Board */
char board[8][8];

makeboard(board);

show_board(board);

/* making the pieces*/
//[x,y] if 0 then no move,
//if 1 then move 1 space,
//if 2 then move 2 space,
//if -1 then move -1 space,
//if -2 then move -2 space,
//if 3 then move any number in direction,
//if {3,3}, then x and y movement must be the same
int rookmove[][2] = {{0,3},{3,0}};
int bishopmove[][2]= {{3,3},{-3,3}};
int queenmove[][2]= {{0,3},{3,0},{3,3},{-3,3}};
int pawnmove[][2]= {{0,1},{0,2}};
int kingmove[][2]= {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int knightmove[][2]= {{1,2},{1,-2},{-1,2},{-1,-2},{2,-1},{2,1},{-2,1},{-2,-1}};

int rookeat[][2]= {{0,3},{3,0}};
int bishopeat[][2]= {{3,3},{-3,3}};
int queeneat[][2]= {{0,3},{3,0},{3,3},{-3,3}};
int pawneat[][2]= {{-1,1},{1,1}};
int kingeat[][2]= {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int knighteat[][2]= {{1,2},{1,-2},{-1,2},{-1,-2},{2,-1},{2,1},{-2,1},{-2,-1}};;

struct chesspiece board1[8][8];

struct chesspiece e2pawn =
{
	"e2",
	0,
	"\u2659",
	1,
	**pawneat,
	**pawnmove
};

board1[1][1]= e2pawn;

/*struct chesspiece e2pawn =
{
	"e2",
	0,
	"\u2659",
	1,
	**pawneat,
	**pawnmove
};*/
//strcpy(e2pawn.currentposition,"e2");
//e2pawn.piecemove[0][0] = **pawnmove;
//e2pawn.pieceeat = pawneat;
//e2pawn.hasmoved = 0;
//e2pawn.color = 1;
//strcpy(e2pawn.unicodepiece,"\u2659");


/* playing the game*/
while(1){
	int contplay = taketurn(board);
	if(contplay==0){
		break;
	}
};

/* Print the Board */
//show_board(board);
printf("The game ends here.\n");




}
