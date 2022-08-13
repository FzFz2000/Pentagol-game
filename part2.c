#include<stdio.h>
#include "graphics.h"
#include "functions.h"


int main() {
	//defining varibles
	int x1 = 102;
	int y1 = 102;
	int x2 = 157;
	int y2 = 157;
	int end = 0;			
	char turn = 0;
	int marble = 0;		//when marble is not 0:the player has not pressed enter(has not chosen)
	char board[6][6];
	int arrow_number=1;		//arrows in graphic page has number
	 int x = 0;		//by pressing wasd keys x and y change
	 int y = 0;
		
	 
	int wid = ALL_WINDOWS;	//show both graphic and non graphical pages
	graphicboard();
	initilize(board);
	monitor(board);
	
	do
	{
		delay(10);
		
		showturn(turn, marble);	
		
		switch (getch())
		{
		case 119:  //w is pressed so the square goes up
			if (y1 > 102)
			{
				setcolor(10);
				rectangle(x1, y1, x2, y2);
				setcolor(4);
				y1 -= 77;
				y2 -= 77;
				rectangle(x1, y1, x2, y2);
				y--;
				marble++;
			}
			break;
		case 115:		//s is pressed
			if (y2 < 542)
			{
				setcolor(10);
				rectangle(x1, y1, x2, y2);
				setcolor(4);
				y1 += 77;
				y2 += 77;
				rectangle(x1, y1, x2, y2);
				y++;
				marble++;
			}
			break;
		case 97:		//a is pressed
			if (x1 > 102)
			{
				setcolor(10);
				rectangle(x1, y1, x2, y2);
				setcolor(4);
				x1 -= 77;
				x2 -= 77;
				rectangle(x1, y1, x2, y2);
				x--;
				marble++;
			}
			break;
		case 100:		//d is pressed
			if (x2 < 542)
			{
				setcolor(10);
				rectangle(x1, y1, x2, y2);
				setcolor(4);
				x1 += 77;
				x2 += 77;
				rectangle(x1, y1, x2, y2);
				x++;
				marble++;
			}
			break;
		case 13:		//enter is pressed it means we put the black or white 
			if (turn % 2 == 0)		//player blacks turn
			{
				if (check_place(y+1, x+1, board) == 0)		//check if the place is empty or not
				{
					printf("error! try again\n");
					continue;
				}
				else
				{
					setfillstyle(1, BLACK);		//putting B
					board[y][x] = { 'b' };
					fillellipse(130 + 77 * x, 130 + 77 * y, 25, 25);
					monitor(board);
					turn++;
					marble = 0;
					end++;
				}
			}
			else if (turn % 2 == 1)			//plater white turn
			{
				if (check_place(y+1, x+1, board) == 0)		//the place is empty?
				{
					printf("error! try again \n");
					continue;
				}
				else
				{
					board[y][x] = { 'w' };		//putting W
					setfillstyle(1, WHITE);
					fillellipse(130 + 77 * x, 130 + 77 * y, 25, 25);
					monitor(board);
					turn--;
					end++;
					marble = 0;
				}
			}
			do        //this loop is for choosing the rotation by pressing D then enter
			{
				if (getch() == 100)		//if d is pressed go to the next arrow
				{
					monitor(board);
					arrow_number = choosespin(arrow_number);
			 }
				else if (getch() == 13)		//if enter is pressed, rotate the board
				{
					do_the_rotation(arrow_number, board);
					break;
				}
			} while (1);
			break;
		default:				//if player press an incorrect key,they'll get an error
			printf("error");
			delay(1000);
			marble++;
			break;
		}
		monitor(board);		//update page
		if (find_colunm(board) != 0 && find_colunm(board)+ find_row(board)>37)		//if both white and black make L at the same time
			end = 36;
		else
			end = find_colunm(board) + find_row(board)+find_diagonal(board);				//it ends the loop if any L is found
	}while (end < 36);
	
	
	if (end == 36)	//it means all places are full or 2 L is made
	{
		printf("equal");
		delay(5000);
	}
	else if (end > 36)		//it means someone has won
	{
		printf("the end!");
		delay(5000);
	}
	closegraph(wid);
	return 0;
}



