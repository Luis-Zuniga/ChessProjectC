#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOVE 5

void show_board(char board[8][8])
{
for (int i=0; i<8; i=i+1)
{
for (int j=0; j<8; j=j+1)
{
printf("%c ",board[i][j] );
};
printf("\n");
};
}

int main(void){

/* Making the Board */
char wteam[8] = {'K','Q','B','N','R','P'};
char bteam[8] = {'k','q','b','n','r','p'};
char board[8][8] = {
{bteam[4],bteam[3],bteam[2],bteam[1],bteam[0],bteam[2],bteam[3],bteam[4]},
{bteam[5],bteam[5],bteam[5],bteam[5],bteam[5],bteam[5],bteam[5],bteam[5],},
{' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' '},
{wteam[5],wteam[5],wteam[5],wteam[5],wteam[5],wteam[5],wteam[5],wteam[5],},
{wteam[4],wteam[3],wteam[2],wteam[1],wteam[0],wteam[2],wteam[3],wteam[4]}
};

/* Print the Board */
show_board(board);

/* Take User Input */
printf("Make a move: 'e.g. E2E4'\n");
char movin[MOVE];
fgets(movin, MOVE, stdin);
printf("%s \n",movin);

/* Format User Input 

-make sure in form letter-number-letter-number
-make sure A-H
-make sure capital
-make sure 1-8
*/
if ((strchr("ABCDEFGH",movin[0])||strchr("abcdefgh",movin[0]))&&strchr("12345678",movin[1])&&(strchr("ABCDEFGH",movin[2])||strchr("abcdefgh",movin[2]))&&strchr("12345678",movin[3])) 
{
printf("The format is a#a#, with #s 1-8 and letters a-h.\n");
} else {
printf("The format is not a#a#, or the numbers are not 1-8 and letters not a-h.\n");
return 0;
};


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
};
};

printf("%s \n",movin);

/* Validate Move i.e. check if legal */

/* Make Changes to Board Based on User Input */
int colin = movin[0]-'0';
int rowin = movin[1]-'0';
int colout = movin[2]-'0';
int rowout = movin[3]-'0';

printf("Moving piece from [%i,%i] to [%i,%i].\n",rowin,colin,rowout,colout);


board[rowout][colout] = board[rowin][colin];
board[rowin][colin] = ' ';

show_board(board);

}


