#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "chess_lfz.h"

//#define MOVE 6

int checkking(struct chesspiece king){
	return 1;
};

int main(void){

  struct chesspiece board[8][8];

  makeboard(board);

  show_board(board);

  while(1){
  	int contplay = taketurn(board);
  	if(contplay==0){
  		break;
  	}
  };

  printf("The game ends here.\n");

};
