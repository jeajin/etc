#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include"game.h"
#pragma warning(disable:4996)

void gotoxy1(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void move1(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch (key) {
	case 72:
		*y1 -= 1;
		if (*y1<1) *y1 = 1;
		break;
	case 75:
		*x1 -= 2;
		if (*x1<1) *x1 = 1;
		break;
	case 77:
		*x1 += 2;
		if (*x1>x_b) *x1 = x_b;
		break;
	case 80:
		*y1 += 1;
		if (*y1>y_b) *y1 = y_b;
		break;
	default:
		break;

	}
}
int main1() {
	int arr[10][10] = { { 1,1,1,1,1,1,1,1,1,1 }
		,{ 1,1,1,1,1,1,1,1,1,1 }
		,{ 1,1,1,1,1,1,1,1,1,1 }
		,{ 1,1,1,1,1,1,1,1,1,1 }
		,{ 1,1,1,1,1,1,1,1,1,1 }
		,{ 1,1,1,1,1,1,1,1,1,1 }
		,{ 1,1,1,1,1,1,1,1,1,1 }
		,{ 1,1,1,1,1,1,1,1,1,1 }
		,{ 1,1,1,1,1,1,1,1,1,1 }
	,{ 1,1,1,1,1,1,1,1,1,1 } };
	char key;
	int A, B;
	int x = 1, y = 1, i, j;
	//맵찍기 
	for (i = 0; i<10; i++)
	{
		for (j = 0; j<10; j++)
		{
			if (arr[i][j] == 1)
				printf("□");
		}

		A = rand() % 10;
		B = rand() % 10;

		printf("\n");
	}

	do {
		gotoxy1(x, y);

		printf("■");
		key = getch();

		move1(key, &x, &y, 19, 10);
		if
			(x == A && y == B)
		{
			printf("★\n\n\n\n\n\n");
			printf("보물을 찾았습니다!");
			return 0;
		}

	}

	while (key != 27);


	return 0;
}




//srand((time());
