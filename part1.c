#include<stdio.h>
#include "graphics.h"
#include "functions.h"
#include<stdlib.h>


int main()
{
	int end = 0;			//defining vriables
	char turn = 0;
	char board[6][6];
	float x, y, place, pl, di;
	char direction,plate;

	initilize(board);		//put dots in board


	do {

		monitor(board);

		showturn(turn, 0);


		scanf_s("%f", &place);			//player choose a place in board
		if (check_fraction(place) == 0 || place < 0)
			continue;
		else
		{
			y = int(place) % 10;
			x = (int(place) - y) / 10;
		}
		if (check_place(x, y, board) == 0)
			continue;
		//if input is not corrrect we'll ask again but when it's char we'll end game



		printf("which plate?\n+for wise and - for anti wise\n"); //next step:player rotate a plate
		scanf_s("%f%c", &pl,&direction);
			if (direction == '+')
			{
				di = 0;
			}
			else if (direction == '-')
			{
				di = 1;
			}
			else
			{
				printf("error");
				continue;
			}
			if (check_plate(pl, di) == 0 || check_fraction(pl) == 0)
			{
				printf("incorret rotation!try again \n");
				//if rotation in incorrect we'll ask again but if it's char we;ll end the game
				continue;
			}


			//when program come to here it means inputs are correct

			if (turn % 2 == 0)		//player blacks turn
			{
				board[int(x) - 1][int(y) - 1] = { 'b' };
				turn++;
			}
			else if (turn % 2 == 1)			//plater white
			{
				board[int(x) - 1][int(y) - 1] = { 'w' };
				turn--;
			}



			if (di == 0)		//rotaion is clockwise
			{
				clockwise(pl, board);
				end++;
			}
			else if (di == 1)		//rotation is anti clockwise
			{
				anti_clock_wise(pl, board);
				end++;
			}
			if (find_colunm(board) != 0 && find_colunm(board) + find_row(board) > 37)
				end = 36;
			else
				end += find_row(board) + find_colunm(board) + find_diagonal(board);	//when we find a horizontal >>or << vertical L
			if (end == 36)								//it means while loop have to be broken
			{
				printf("no one won\n");
				break;
			}
	} while (end < 36);		//when no one wins 36 times must be played
	delay(3000);
}