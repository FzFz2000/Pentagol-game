#include<stdio.h>
#include<stdlib.h>
#include"graphics.h"
#include "functions.h"

void monitor(char game[6][6])			//whenever player play,it will print new board and update changes
{
	system("cls");
	printf("\n\t1 \t2 \t3 \t\t4 \t5 \t6 \n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d\t", i + 1);
		for (int j = 0; j < 6; j++)		//by 2 for loops all array is covered
		{
			printf("%c\t", game[i][j]);
			if (j == 2)
				printf("| \t");		//putting | to seperate 3*3 plates 
		}
		printf("\n\n");
		if (i == 2)
			printf("\n--\t--\t--\t--\t\t--\t--\t-- \n\n");	//to seperate 3*3 plates
	}
	printf("___________________________________________________________ \n\n");
}

void graphicboard()		//it determine size of circles,rectangles and ... 
{
	initwindow(690, 650, "Farnaz Feiz");
	setcolor(WHITE);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			line(75 + i * 450, 60 + j * 520, 125 + i * 450, 60 + j * 520);
			line(125, 60 + j * 520, 110, 55 + j * 520);
			line(125, 60 + j * 520, 110, 65 + j * 520);
			line(522, 60 + j * 520, 537, 55 + j * 520);
			line(522, 60 + j * 520, 537, 65 + j * 520);
		}

	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			line(60 + i * 520, 80 + j * 430, 60 + i * 520, 130 + j * 430);
			line(60 + j * 520, 130, 55 + j * 520, 115);
			line(60 + j * 520, 130, 65 + j * 520, 115);
			line(60 + i * 520, 510, 65 + i * 520, 525);
			line(60 + i * 520, 510, 55 + i * 520, 525);
		}
	}
	setcolor(3);
	rectangle(60, 50, 135, 70);
	settextstyle(5, HORIZ_DIR, 7);
	setcolor(12);
	outtextxy(210, 20, "Pentago");

	setcolor(10);
	for (int i = 90; i < 550; i++)
	{
		line(i, 90, i, 550);
	}
	setcolor(4);
	rectangle(102, 102, 157, 157);

	rectangle(102, 102, 157, 157);
	line(320, 90, 320, 550);
	line(90, 320, 550, 320);
	setcolor(8);
	setfillstyle(1, 8);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			fillellipse(130 + 77 * i, 130 + 77 * j, 25, 25);
		}
	}

}

void initilize(char game[6][6])					//before start playing this funcion create empty board(it puts dots inside array)
{

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			game[i][j] = { '.' };
		}
	}
}



void showturn(int theturn, int themarble)
{
	switch (theturn)		//when turn=0 it's blacks turn
	{					//when turn=1 it's whites turn
	case 0:
		if (themarble == 0)
			printf("player black turn\n");
		break;
	case 1:
		if (themarble == 0)
			printf("player white turn\n");
		break;
	}
}


int check_place(int x, int y, char game[6][6])		//game[i][j] i and j must be : 0<=i<6 
													//user think board starts from 1 but in program it
													//starts from zero so we check x-1 and y-1
{
	if (game[x - 1][y - 1] != '.' || x < 1 || y < 1 || x>6 || y>6)
	{
		printf("incorrect place!try again! \n");
		return 0;
	}
	else
		return 1;
}

int check_plate(int plate, int direction)
{
	if (plate == 1 || plate == 2 || plate == 3 || plate == 4)
	{
		if (direction == 0 || direction == 1)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}		//we have only 4 plates:1,2,3,4 and 2 rotaions:0 and 1 any thing else is false


int check_fraction(float input)	//if there is franction it returns 0
								// 1.00 = 1 but   1.05!=1
{
	if (int(input) == input)
		return 1;
	else
		return 0;
}

void clockwise(int plate, char arr[6][6])	//it's for 90+ spin
{
	char tran[6][6];
	switch (plate)										        //   ____________________________________
	{															 // |                 |		            |
	case 1:
		//  |                 |                 |
		tran[0][3] = arr[2][3];									 // |         2       |        1        |
		tran[0][4] = arr[1][3];									 // |                 |                 |	
		tran[0][5] = arr[0][3];									  //|                 |		            |
		tran[1][3] = arr[2][4];									  // _____________________________________
		tran[1][4] = arr[1][4];									 // |                 |                 |
		tran[1][5] = arr[0][4];									 // |                 |                 |
		tran[2][3] = arr[2][5];                                   //|         3       |        4        |
		tran[2][4] = arr[1][5];									  //|                 |                 |
		tran[2][5] = arr[0][5];									  //|                 |                 |
		for (int i = 0; i < 3; i++)								 // _____________________________________ 
		{
			for (int j = 3; j < 6; j++)
			{
				arr[i][j] = tran[i][j];
			}
		}														//lines tran[a][b]=games[c][d] is for creating new array which is turned
		break;
	case 2:
		tran[0][0] = arr[2][0];
		tran[0][1] = arr[1][0];
		tran[0][2] = arr[0][0];
		tran[1][0] = arr[2][1];
		tran[1][1] = arr[1][1];
		tran[1][2] = arr[0][1];
		tran[2][0] = arr[2][2];
		tran[2][1] = arr[1][2];
		tran[2][2] = arr[0][2];
		for (int i = 0; i < 3; i++)				//these for loops update the game array
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = tran[i][j];
			}
		}
		break;
	case 3:
		tran[3][0] = arr[5][0];
		tran[3][1] = arr[4][0];
		tran[3][2] = arr[3][0];
		tran[4][0] = arr[5][1];
		tran[4][1] = arr[4][1];
		tran[4][2] = arr[3][1];
		tran[5][0] = arr[5][2];
		tran[5][1] = arr[4][2];
		tran[5][2] = arr[3][2];
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = tran[i][j];
			}
		}
		break;
	case 4:
		tran[3][3] = arr[5][3];
		tran[3][4] = arr[4][3];
		tran[3][5] = arr[3][3];
		tran[4][3] = arr[5][4];
		tran[4][4] = arr[4][4];
		tran[4][5] = arr[3][4];
		tran[5][3] = arr[5][5];
		tran[5][4] = arr[4][5];
		tran[5][5] = arr[3][5];
		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				arr[i][j] = tran[i][j];
			}
		}
		break;
	}

}
void anti_clock_wise(int plate, char arr[6][6])				//only difference is that it turns 90-
{
	char tran[6][6];
	switch (plate)
	{
	case 1:
		tran[2][3] = arr[0][3];
		tran[1][3] = arr[0][4];
		tran[0][3] = arr[0][5];
		tran[2][4] = arr[1][3];
		tran[1][4] = arr[1][4];
		tran[0][4] = arr[1][5];
		tran[2][5] = arr[2][3];
		tran[1][5] = arr[2][4];
		tran[0][5] = arr[2][5];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				arr[i][j] = tran[i][j];
			}
		}
		break;
	case 2:
		tran[2][0] = arr[0][0];
		tran[1][0] = arr[0][1];
		tran[0][0] = arr[0][2];
		tran[2][1] = arr[1][0];
		tran[1][1] = arr[1][1];
		tran[0][1] = arr[1][2];
		tran[2][2] = arr[2][0];
		tran[1][2] = arr[2][1];
		tran[0][2] = arr[2][2];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = tran[i][j];
			}
		}
		break;
	case 3:
		tran[5][0] = arr[3][0];
		tran[4][0] = arr[3][1];
		tran[3][0] = arr[3][2];
		tran[5][1] = arr[4][0];
		tran[4][1] = arr[4][1];
		tran[3][1] = arr[4][2];
		tran[5][2] = arr[5][0];
		tran[4][2] = arr[5][1];
		tran[3][2] = arr[5][2];
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = tran[i][j];
			}
		}
		break;
	case 4:
		tran[5][3] = arr[3][3];
		tran[4][3] = arr[3][4];
		tran[3][3] = arr[3][5];
		tran[5][4] = arr[4][3];
		tran[4][4] = arr[4][4];
		tran[3][4] = arr[4][5];
		tran[5][5] = arr[5][3];
		tran[4][5] = arr[5][4];
		tran[3][5] = arr[5][5];
		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				arr[i][j] = tran[i][j];
			}
		}
		break;
	}
}


int choosespin(int arrow)		//instead of entering 1+ or 2- or... we'll do it in graphical page
{
	printf("choose the rotation by pressing d key  and then enter");
	switch (arrow)	//each arrow has a unique rotation
	{
	case 1:
		setcolor(BLACK);
		rectangle(60, 50, 135, 70);
		setcolor(3);
		rectangle(520, 50, 60 + 520, 70);
		arrow++;
		break;
	case 2:
		setcolor(BLACK);
		rectangle(520, 50, 60 + 520, 70);
		setcolor(3);
		rectangle(570, 75, 590, 140);
		arrow++;
		break;
	case 3:
		setcolor(BLACK);
		rectangle(570, 75, 590, 140);
		setcolor(3);
		rectangle(570, 75 + 425, 590, 140 + 425);
		arrow++;
		break;
	case 4:
		setcolor(BLACK);
		rectangle(570, 75 + 425, 590, 140 + 425);
		setcolor(3);
		rectangle(70 + 450, 50 + 520, 135 + 450, 70 + 520);
		arrow++;
		break;
	case 5:
		setcolor(BLACK);
		rectangle(70 + 450, 50 + 520, 135 + 450, 70 + 520);
		setcolor(3);
		rectangle(70, 50 + 520, 135, 70 + 520);
		arrow++;
		break;
	case 6:
		setcolor(BLACK);
		rectangle(70, 50 + 520, 135, 70 + 520);
		setcolor(3);
		rectangle(570 - 520, 75 + 425, 590 - 520, 140 + 425);
		arrow++;
		break;
	case 7:
		setcolor(BLACK);
		rectangle(570 - 520, 75 + 425, 590 - 520, 140 + 425);
		setcolor(3);
		rectangle(570 - 520, 75, 590 - 520, 140);
		arrow++;
		break;
	case 8:
		setcolor(BLACK);
		rectangle(570 - 520, 75, 590 - 520, 140);
		setcolor(3);
		rectangle(60, 50, 135, 70);
		arrow = 1;
		break;
	}
	return arrow;
}
void do_the_rotation(int arrow, char game[6][6])		//when player chose the rotation it happens to both pages
{
	switch (arrow)
	{
	case 1:
		clockwise(2, game);
		break;
	case 2:
		anti_clock_wise(1, game);
		break;
	case 3:
		clockwise(1, game);
		break;
	case 4:
		anti_clock_wise(4, game);
		break;
	case 5:
		clockwise(4, game);
		break;
	case 6:
		anti_clock_wise(3, game);
		break;
	case 7:
		clockwise(3, game);
		break;
	case 8:
		anti_clock_wise(2, game);
		break;
	}
	for (int i = 0; i < 6; i++)		//then we reprint marbles(updating the page)
	{
		for (int j = 0; j < 6; j++)
		{
			if (game[i][j] == 'b')
			{
				setfillstyle(1, BLACK);
				fillellipse(130 + 77 * j, 130 + 77 * i, 25, 25);
			}
			else if (game[i][j] == 'w')
			{
				setfillstyle(1, WHITE);
				fillellipse(130 + 77 * j, 130 + 77 * i, 25, 25);
			}
			else
			{
				setfillstyle(1, 8);
				fillellipse(130 + 77 * j, 130 + 77 * i, 25, 25);
			}
		}
	}
}


int find_row(char game[6][6])		//there is'nt any L if there ar'nt any row so we first fid row
{
	int rturn = 0;
	for (int j = 0; j < 6; j++)		//in each row of 6*6 there is 3 possible rows so we check all rows 
									//3 colunms in each.
	{
		for (int i = 0; i < 3; i++)
		{
			//first statement:we are searching for b and w to create L not empty dot!
			//other statements are just for the row
			if (game[i][j] != '.' && game[i][j] == game[i + 1][j] && game[i][j] == game[i + 2][j] && game[i][j] == game[i + 3][j])
			{
				if (j == 0)
					/*in first row you can't have this L so we don't check it

						  *
						  *
						  *
						  *
					   *  *

					*/
				{
					if (game[i][j] == game[i + 3][j + 1] || game[i][j + 1] == game[i][j])
					{
						printf("player %c won\n", game[i][j]);
						rturn = 37;
					}

				}
				else if (j == 5)
					/*in last row we don't check L shapes*/
				{
					if (game[i][j] == game[i + 3][j - 1] || game[i][j] == game[i][j - 1])
					{
						printf("player %c won\n", game[i][j]);
						rturn = 37;
					}
				}
				else
				{	//in other case we check both L
					if (game[i][j] == game[i + 3][j - 1] || game[i][j] == game[i + 3][j + 1] || game[i][j] == game[i][j - 1] || game[i][j + 1] == game[i][j])
					{
						printf("player %c won\n", game[i][j]);
						rturn = 37;
					}
				}
			}
		}
	}
	return rturn;//ending game depends on value of rturn
}
int find_colunm(char game[6][6]) //the only difference with find_row is that
								// game[a][b] has changed to game[b][a] 
								//no matter what is a and b
{
	int rturn = 0;
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (game[j][i] != '.' && game[j][i] == game[j][i + 1] && game[j][i] == game[j][i + 2] && game[j][i] == game[j][i + 3])
			{
				if (j == 0)
				{
					if (game[j][i] == game[j + 1][i + 3] || game[j + 1][i] == game[j][i])
					{
						printf("player %c won\n", game[j][i]);
						rturn = 37;
					}

				}
				else if (j == 5)
				{
					if (game[j][i] == game[j - 1][i + 3] || game[j][i] == game[j - 1][i])
					{
						printf("player %c won\n", game[j][i]);
						rturn = 37;
					}
				}
				else
				{
					if (game[j][i] == game[j - 1][i + 3] || game[j][i] == game[j - 1][i] || game[j][i] == game[j + 1][i + 3] || game[j + 1][i] == game[j][i])
					{
						printf("player %c won\n", game[j][i]);
						rturn = 37;
					}
				}
			}
		}
	}
	return rturn;
}

int find_diagonal(char game[6][6])
{
	int rturn = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j ++)
		{
			if (game[0+j][i] != '.' && game[0+j][i] == game[1+j][i + 1] && game[2+j][i + 2] == game[0+j][i] && game[3+j][i + 3] == game[0+j][i])
			{
				if (game[0 + j][i] == game[0 + j - 1][i + 1] || game[0 + j][i] == game[0 + j + 1][i - 1] || game[0 + j][i] == game[j + 2][i + 4] || game[j][i] == game[j + 4][i + 2])
				{
					printf("player %c made L", game[j][i]);
					rturn = 37;
				}
			}
		}
	}
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 3; j ++)
		{
			if (game[j][i] != '.' && game[j][i] == game[1 + j][i -1] && game[2 + j][i -2] == game[j][i] && game[3 + j][i -3] == game[j][i])
			{
				if (game[j][i] == game[j - 1][i - 1] || game[j][i] == game[j + 1][i + 1] || game[j][i] == game[j + 2][i - 4] || game[j][i] == game[j + 4][i - 2])
				{
					printf("player %c made L!", game[0 + j][i]);
					rturn = 37;
				}
			}
		}
	}
	return rturn;
}

