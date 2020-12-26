#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "game.h"
#pragma warning(disable:4996)
int map19[20][20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1


};

void gotoxy19(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void move19(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch (key) {
	case 72:
		*y1 = *y1 - 1;
		if (*y1<1) *y1 = 1;
		break;
	case 75:
		*x1 = *x1 - 2;
		if (*x1<1) *x1 = 1;
		break;
	case 77:
		*x1 = *x1 + 2;
		if (*x1>x_b) *x1 = x_b;
		break;
	case 80:
		*y1 = *y1 + 1;
		if (*y1>y_b) *y1 = y_b;
		break;
	default:
		break;
	}
}






void showBoard(void)
{
	int i, x, y, z, q;
	srand(time(NULL));

	for (i = 0; i<7; i++)
	{
		z = rand() % 20;
		q = rand() % 20;
		map19[z][q] = 2;
	}

	for (y = 0; y<20; y++)
	{
		for (x = 0; x<20; x++)
		{
			if (map19[y][x] == 1)
				printf("¡á");
			if (map19[y][x] == 0)
				printf("  ");
			if (map19[y][x] == 2)
				printf("¡Ú");
		}
		printf("\n");
	}
}



int main19() {


	char key;
	int x = 20, y = 10;
	int i, j, k = 0;
	showBoard();
	do {
		gotoxy19(x, y);
		printf("¡Ü");
		key = getch();
		move19(key, &x, &y, 79, 24);
		printf("\b ");
		if (map19[y][x / 2] == 2)
		{
			map19[y][x / 2] == 0;
			k++;
			gotoxy19(20, 20);
			printf("%d", k);
		}
		if (k == 18)
		{
			gotoxy19(0, 0);
			system("CLS");
			showBoard();
			k = 0;
		}

	} while (key != 27);

	return 0;
}
