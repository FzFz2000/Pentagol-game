#pragma once
void monitor(char game[6][6]);

void initilize(char game[6][6]);

int check_place(int x, int y, char game[6][6]);

int check_plate(int plate, int direction);

int find_row(char game[6][6]);

int find_colunm(char game[6][6]);

int check_fraction(float input);

void clockwise(int plate, char arr[6][6]);

void anti_clock_wise(int plate, char arr[6][6]);

void graphicboard();

void showturn(int theturn, int themarble);

int choosespin(int arrow);

void do_the_rotation(int arrow, char game[6][6]);

int find_diagonal(char game[6][6]);