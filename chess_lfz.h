
//#ifndef	MOVE
#define	MOVE 6

struct chesspiece {
	//char currentposition[3];
	int hasmoved;
	char unicodepiece[8];
	int color;
	int pieceeat[5][2];
	int piecemove[][2];
};

int isblank(char (movin)[MOVE], struct chesspiece board[8][8]){
	printf("--%s--\n",((board[movin[0]-'0'][movin[1]-'0']).unicodepiece));
	if(strchr(((board[movin[0]-'0'][movin[1]-'0']).unicodepiece),"  ")){
		return 1;
	} else {
		return 0;
	};
};

void show_board(struct chesspiece board[8][8])
{
	/* Print the Board */
for (int i=0; i<8; i=i+1)
{
for (int j=0; j<8; j=j+1)
{
	 printf("%s",(board[i][j]).unicodepiece);


};
printf("\n");
};
};

void makeboard(struct chesspiece (board)[8][8]){

	/* Making the Board */
  /* Defining Movements and Eatings */
  const int rookmove[][2] = {{0,3},{3,0}};
  const int bishopmove[][2]= {{3,3},{-3,3}};
  const int queenmove[][2]= {{0,3},{3,0},{3,3},{-3,3}};
  const int pawnmove[][2]= {{0,1},{0,2}};
  const int kingmove[][2]= {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
  const int knightmove[][2]= {{1,2},{1,-2},{-1,2},{-1,-2},{2,-1},{2,1},{-2,1},{-2,-1}};

  const int rookeat[][2]= {{0,3},{3,0}};
  const int bishopeat[][2]= {{3,3},{-3,3}};
  const int queeneat[][2]= {{0,3},{3,0},{3,3},{-3,3}};
  const int pawneat[][2]= {{-1,1},{1,1}};
  const int kingeat[][2]= {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
  const int knighteat[][2]= {{1,2},{1,-2},{-1,2},{-1,-2},{2,-1},{2,1},{-2,1},{-2,-1}};;

  /* Defining blank space */
  const struct chesspiece blank;
  strcpy(blank.unicodepiece,"  ");

  /* Defining Chess Pieces */
  const struct chesspiece wrook = {0,"\u2656 ",1,**rookeat,**rookmove};
  const struct chesspiece wbishop = {0,"\u2657 ",1,**bishopeat,**bishopmove};
  const struct chesspiece wqueen = {0,"\u2655 ",1,**queeneat,**queenmove};
  const struct chesspiece wpawn = {0,"\u2659 ",1,**pawneat,**pawnmove};
  const struct chesspiece wking = {0,"\u2654 ",1,**kingeat,**kingmove};
  const struct chesspiece wknight = {0,"\u2658 ",1,**knighteat,**knightmove};

  const struct chesspiece brook = {0,"\u265C ",0,**rookeat,**rookmove};
  const struct chesspiece bbishop = {0,"\u265D ",0,**bishopeat,**bishopmove};
  const struct chesspiece bqueen = {0,"\u265B ",0,**queeneat,**queenmove};
  const struct chesspiece bpawn = {0,"\u265F ",0,**pawneat,**pawnmove};
  const struct chesspiece bking = {0,"\u265A ",0,**kingeat,**kingmove};
  const struct chesspiece bknight = {0,"\u265E ",0,**knighteat,**knightmove};

  /* Define Temp Board */

  struct chesspiece board_temp[8][8] = {
    {brook,bknight,bbishop,bqueen,bking,bbishop,bknight,brook},
    {bpawn,bpawn,bpawn,bpawn,bpawn,bpawn,bpawn,bpawn},
    {blank,blank,blank,blank,blank,blank,blank,blank},
    {blank,blank,blank,blank,blank,blank,blank,blank},
    {blank,blank,blank,blank,blank,blank,blank,blank},
    {blank,blank,blank,blank,blank,blank,blank,blank},
    {wpawn,wpawn,wpawn,wpawn,wpawn,wpawn,wpawn,wpawn},
    {wrook,wknight,wbishop,wqueen,wking,wbishop,wknight,wrook},
  };

  /* Move temp values into main board*/
  for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			board[i][j]=board_temp[i][j];
		}
	};
};

void userin(char (movin)[MOVE]){
	/* Take User Input */
	fflush(stdin);
	printf("Make a move: 'e.g. E2E4'\n");
	//char movin[MOVE];
	fgets(movin, MOVE, stdin);
	fflush(stdin);
	//printf("%s \n",movin);

}

int checkinput(char (movin)[MOVE]){
	/* Format User Input

	-make sure in form letter-number-letter-number
	-make sure A-H
	-make sure capital
	-make sure 1-8
	*/

	if ((strchr("ABCDEFGH",movin[0])||strchr("abcdefgh",movin[0]))&&strchr("12345678",movin[1])&&(strchr("ABCDEFGH",movin[2])||strchr("abcdefgh",movin[2]))&&strchr("12345678",movin[3]))
	{
	//printf("The format is a#a#, with #s 1-8 and letters a-h.\n");
	return 1;
} else if(strchr(movin,'\n')){
	// EOF char quits game completely
	return 2;
	} else {
	printf("The format is not a#a#, or the numbers are not 1-8 and letters not a-h.\n");
	//printf("s% \n",movin);
	return 0;
	};
}


void interpretinput(char (movin)[MOVE]){
	/* Interpret User Input */
	for (int i = 0; i<3; i=i+2) {
	switch(movin[i]) {
		case 'A':
			movin[i]='0';
			break;
		case 'B':
			movin[i]='1';
			break;
		case 'C':
			movin[i]='2';
			break;
		case 'D':
	    movin[i]='3';
			break;
		case 'E':
	    movin[i]='4';
			break;
		case 'F':
	    movin[i]='5';
			break;
		case 'G':
	    movin[i]='6';
			break;
		case 'H':
	    movin[i]='7';
			break;
		default:
			movin[i]='Z';
	};
	};

	for (int i = 1; i<4; i=i+2) {
	switch(movin[i]) {
	        case '1':
	                movin[i]='7';
	                break;
	        case '2':
	                movin[i]='6';
	                break;
	        case '3':
	                movin[i]='5';
	                break;
	        case '4':
	                movin[i]='4';
	                break;
	        case '5':
	                movin[i]='3';
	                break;
	        case '6':
	                movin[i]='2';
	                break;
	        case '7':
	                movin[i]='1';
	                break;
	        case '8':
	                movin[i]='0';
									break;
					default:
									movin[i]='Z';
	};
	};

	//if(strchr(movin,'Z')!= NULL){
		//printf("Input move is out of bounds.\n");
		//return 0;
//};
}

void makemove(struct chesspiece board[8][8], char (movin)[MOVE]){
	int colin = movin[0]-'0';
	int rowin = movin[1]-'0';
	int colout = movin[2]-'0';
	int rowout = movin[3]-'0';

	//printf("Moving piece from [%i,%i] to [%i,%i].\n",rowin,colin,rowout,colout);

	/* Defining blank space */
  const struct chesspiece blank;
  strcpy(blank.unicodepiece,"  ");

	/* moving pieces */
	board[rowout][colout] = board[rowin][colin];
	board[rowin][colin] = blank;
}

int taketurn(struct chesspiece board[8][8]){
	/* Take User Input */

	char movin[MOVE];
	//userin(movin);

	/* Format User Input

	-make sure in form letter-number-letter-number
	-make sure A-H
	-make sure capital
	-make sure 1-8
	*/
	int isgoodin = 0;
	for(int i=0;i<3;i++){
		userin(movin);
		int isgoodin = checkinput(movin);
		if(isgoodin == 1)
		{
			break;
		};
		if(isgoodin == 2){
			return 0;
		};
	};

	/* Interpret User Input */

	interpretinput(movin);

	if(strchr(movin,'Z')!= NULL){
		printf("Input move is out of bounds.\n");
		return 0;
	};

	if(isblank(movin, board)==1){
		return 0;
		printf("That space has no piece to move.\n");
	};
	//printf("%s \n",movin);


	/* Validate Move i.e. check if legal */


	/* Make Changes to Board Based on User Input */
	makemove(board,movin);


	show_board(board);

	return 1;
}
