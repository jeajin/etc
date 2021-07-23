#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include "game.h"
#pragma warning(disable:4996)
int k = 1;
int kk = 15;
int kkk = 50;
void map6();

void go(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void setcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int arr[20][20] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2
};



void wall() {

	int i, j;

	for (i = 0; i<20; i++)
	{
		for (j = 0; j<20; j++)
		{
			if (arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i][j - 1] == 1 && arr[i - 1][j] == 1)
			{
				arr[i + 1][j] = 0;
			}

			if (arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i][j - 1] == 1 && arr[i - 1][j + 1] == 1)
			{
				arr[i - 1][j + 1] = 0;
			}

			if (arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i][j - 1] == 1 && arr[i - 1][j + 2] == 1)
			{
				arr[i + 1][j] = 0;
			}

			if (arr[i][j + 1] == 1 && arr[i + 1][j] == 1 && arr[i - 1][j] == 1)
			{
				arr[i][j + 1] = 0;
			}

			if (arr[i][j + 1] == 1 && arr[i + 1][j] == 1 && arr[i][j - 1] == 1 && arr[i + 2][j - 1] == 1)
			{
				arr[i][j + 1] = 0;
			}

			if (arr[i][j + 1] == 1 && arr[i][j] == 1 && arr[i - 1][j] == 1)
			{
				arr[i][j + 1] = 0;
			}

			if (arr[i][j] == 1 && arr[i + 1][j - 1] == 1 && arr[i - 1][j + 1])
			{
				arr[i][j] = 0;
			}

			if (arr[i][j] == 1 && arr[i][j - 1] == 1 && arr[i][j + 1] == 1 && arr[i - 1][j + 1] == 1)
			{
				arr[i][j] = 0;
			}

			if (arr[i][j] == 1 && arr[i][j - 1] == 1 && arr[i][j + 1] == 1 && arr[i - 1][j - 1] == 1)
			{
				arr[i][j] = 0;
			}

			if (arr[i][j] == 1 && arr[i - 1][j + 1] == 1 && arr[i][j - 1] == 1)
			{
				arr[i][j] = 0;
			}

			if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i - 1][j] == 1 && arr[i + 2][j] == 1)
			{
				arr[i][j] = 0;
			}

			if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i - 1][j] == 1 && arr[i - 2][j] == 1)
			{
				arr[i][j] = 0;
			}

			if (arr[i - 1][j] == 1 && arr[i][j - 1] == 1 && arr[i][j + 1] == 1)
			{
				arr[i - 1][j] = 0;
			}

			if (arr[i][j - 1] == 1 && arr[i][j] == 1 && arr[i][j - 2] == 1 && arr[i][j + 1] == 1)
			{
				arr[i][j] = 0;
			}

			if (arr[i][j - 1] == 1 && arr[i][j] == 1 && arr[i][j + 2] == 1 && arr[i][j + 1] == 1)
			{
				arr[i][j] = 0;
			}
		}
	}
}





void mv(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch (key)
	{
	case 72:
		*y1 = *y1 - 1;
		if (*y1<1) { *y1 = 1; }
		if (arr[*y1 - 1][*x1 / 2] == 1)
		{
			go(1, 1); *y1 = 1, *x1 = 1; setcolor(kk); kkk--; map6();
		}
		break;

	case 75:
		*x1 = *x1 - 2;
		if (*x1<1) { *x1 = 1; }
		if (arr[*y1 - 1][*x1 / 2] == 1)
		{
			go(1, 1); *y1 = 1, *x1 = 1; setcolor(kk); kkk--; map6();
		}
		break;

	case 77:
		*x1 = *x1 + 2;
		if (*x1>x_b) { *x1 = x_b; }
		if (arr[*y1 - 1][*x1 / 2] == 1)
		{
			go(1, 1); *y1 = 1, *x1 = 1; setcolor(kk); kkk--; map6();
		}
		break;

	case 80:
		*y1 = *y1 + 1;
		if (*y1>y_b) { *y1 = y_b; }
		if (arr[*y1 - 1][*x1 / 2] == 1)
		{
			go(1, 1); *y1 = 1, *x1 = 1; setcolor(kk); kkk--; map6();
		}
		break;

	default:;
	}

}


void map6() {
	int i, j;

	arr[0][0] = 0;
	arr[0][1] = 0;
	arr[19][18] = 0;
	arr[19][19] = 2;

	go(1, 1);

	for (i = 0; i<20; i++)
	{
		for (j = 0; j<20; j++)
		{
			if (arr[i][j] == 2)
			{
				printf("♣");
			}
			else
			{
				printf("▤");
			}
		}
		printf("\n");
	}
	go(15, 21);
	printf("%d  R O U N D", k);

	go(50, 20);
	printf("남은 기회 : %2d", kkk);

}

void hint() {

	go(1, 1);

	int v, m;

	for (v = 0; v<20; v++)
	{
		for (m = 0; m<20; m++)
		{
			if (arr[v][m] == 2)
			{
				printf("♣");
			}
			else if (arr[v][m] == 1)
			{
				printf("▤");
			}
			else if (arr[v][m] == 0)
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}



int main6() {
	int e = 1;
	int key = 0;
	int a = 1, b = 1, q, w = 1, c, d;
	srand((signed int)time(NULL));




exit:
	wall();


	for (q = 1; q<40 + w * 3; q++)
	{
		c = rand() % 20;
		d = rand() % 20;
		arr[c][d] = 1;
	}

	hint();

	Sleep(1500);

	map6();

	a = 1, b = 1;

	do {

		go(a, b);
		setcolor(1);
		printf("▤");
		go(a, b);


		key = getch();

		if (a == 40 && b == 20)
		{
			k++; e++;
			go(15, 21);
			printf("%d  R O U N D", k);
			go(1, 1);
			kk = e;
			setcolor(e);
			goto exit;
		}

		mv(key, &a, &b, 40, 20);
		if (kkk <= 0)
		{
			break;
		}
	} while (key != 27);
setcolor(7);
	return 0;
}
