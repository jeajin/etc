#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "game.h"
#include <math.h>
#include <stdlib.h>
#define MAX 20
#define XMAX 78

void gotoxy16(int x, int y);
void move16(char key, int *x1, int *y1, int x_b, int y_b);
void InputNum(char(*arr)[XMAX + 1]);
int choongdol(char(*arr)[XMAX + 1], int x, int y);
int movechoongdol(char(*arr)[XMAX + 1], int x, int y);
int fall(char(*arr)[XMAX + 1], int *px, int *py, int *px2, int *py2);
void keycheck(char(*arr)[XMAX + 1], int *px, int *py);
int gun(char(*arr)[XMAX + 1], char key, int *px, int *py);
int fallchoongdol(char(*arr)[XMAX + 1], int x, int y, int *px, int *py);

int i, k;                     // ���ֻ��Ǵ� ���� i,k ������� ������Ͽ� ����

							  /*
							  #include <stdio.h>
							  #include "header.h"
							  //#define XMAX 78 */

void keycheck(char(*arr)[XMAX + 1], int *px, int *py)
{
	if (GetAsyncKeyState(VK_UP) <0)
		move16(72, &(*px), &(*py), 79, 24);
	else if (GetAsyncKeyState(VK_LEFT) <0)
		move16(75, &(*px), &(*py), 79, 24);
	else if (GetAsyncKeyState(VK_RIGHT) <0)
		move16(77, &(*px), &(*py), 79, 24);
	else if (GetAsyncKeyState(VK_DOWN) <0)
		move16(80, &(*px), &(*py), 79, 24);
	//else if( GetAsyncKeyState(VK_SPACE) <0 )//& 0x8001 || GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x0000 || GetAsyncKeyState(VK_SPACE) & 0x0001 )
	//gun(arr, 32, &(*px), &(*py) );
}
int choongdol(char(*arr)[XMAX + 1], int x, int y)
{
	if (arr[y - 1][x - 1] != 1 && arr[y - 1][x - 1] != 30)          // ��ǥ(1,1)�� �迭 arr[0][0]�� ����, ��ǥ(20,20)�� �迭 arr[20-1][20-1]�� �����Ƿ�, arr[y-1][x-1] �� �����.
		return -1;
	return 1;
}



void move16(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch (key)
	{
	case 72: *y1 = *y1 - 1;              // �������, �� �� �� ��.
		if (*y1<1) *y1 = 1;               // ����� ����ϴ°��� �ϳ��� �����Ϸ� ������, ���̵� ������ ���� ���Ͽ����ϴ�.
		gotoxy16(*x1, *y1 + 1);            // �ܼ�ȭ�鿡 ĳ��(*)�� �������� �ϱ����� \b(backspace)�� ���ʿ� �ξ���.
		printf(" \b");
		gotoxy16(*x1, *y1);
		printf("*");
		break;
	case 75: *x1 = *x1 - 1;
		if (*x1<1) *x1 = 1;
		gotoxy16(*x1, *y1);
		printf("* ");
		gotoxy16(*x1, *y1);
		printf("\b");
		break;
	case 77: *x1 = *x1 + 1;
		if (*x1>x_b) *x1 = x_b;
		gotoxy16(*x1, *y1);
		printf("\b ");
		gotoxy16(*x1, *y1);
		printf("*");
		break;
	case 80: *y1 = *y1 + 1;
		if (*y1>y_b) *y1 = y_b;
		gotoxy16(*x1, *y1 - 1);
		printf(" \b");
		gotoxy16(*x1, *y1);
		printf("*");
		break;
	default:;
	}
}
void InputNum(char(*arr)[XMAX + 1])
{
	int x, y;
	for (i = 0; i<MAX; i++)
		for (k = 0; k<XMAX; k++) {
			if (k % 2 == 0)
				arr[i][k] = 0xa1;
			else
				arr[i][k] = 0xe1;
		}
	for (i = 1, k = 0; i, k<MAX; i++, k = k + 2)             // ����, ���������� �־����ִ� 0xa1, 0xe1 2���� �߰��� ������ ���ſ�, �ܰ� ��µǹǷ�
		arr[i][k] = arr[i][k + 1] = 1;              // arr[i][k], arr[i][k+1] 2���� �������� 1�� ����. �� ���� k�� 2�� ������Ŵ. /	}
	for (i = 2, k = 0; i, k<MAX; i++, k = k + 2)
		arr[i][k] = arr[i][k + 1] = 1;

	for (i = 1, k = 30; i, k<MAX + 30; i++, k = k + 2)
		arr[i][k] = arr[i][k + 1] = 1;
	for (i = 2, k = 30; i, k<MAX + 30; i++, k = k + 2)
		arr[i][k] = arr[i][k + 1] = 1;

	srand(time(NULL));
	x = rand() % 76 + 1;
	y = rand() % 4 + 2;
	if (x % 2 == 0)
		x--;
	arr[y - 1][x - 1] = 30;             //�����濡 �� 30�� ����.
	arr[y - 1][x] = 30;
}
int movechoongdol(char(*arr)[XMAX + 1], int x, int y)
{
	if (arr[y - 1][x - 1] == 30)             // ĳ���� �̵��Ҷ�, ������ ��ġ�� �¸��ϰ�, �ʿ� �ε����� �й��ϴ� �Լ�.
		return 30;
	if (arr[y - 1][x - 1] == 1)
		return 1;
	if (arr[y - 1][x - 1] & 0xa1 || arr[y - 1][x - 1] & 0xe0 || arr[y - 1][x - 1] & 0xe1)
		return -1;
}

int fallchoongdol(char(*arr)[XMAX + 1], int x, int y, int *px, int *py)
{
	if ((x == *px || x + 1 == *px) && y == *py)         //�������� ���ڿ� ĳ���� ������ ����������Ǵ� �Լ�.
		return -1;
	return 0;
}
int gun(char(*arr)[XMAX + 1], char key, int *px, int *py)
{
	int x = *px;
	int y = *py;
	int y2 = y;
	int homereturn = 0;

	if (GetAsyncKeyState(VK_SPACE) & 0x8001 || GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x0000 || GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		key = 32;
		while (y >= 2)
		{
			if (x >= 0 && x <= 79 && y >= 0 && y <= 20)
				if (choongdol(arr, x, y) == -1)
				{
					arr[y - 1][x - 1] = 1;
					if ((x - 1) % 2 == 0)
						arr[y - 1][x] = 1;
					else
						arr[y - 1][x - 2] = 1;
					break;
				}
			switch (key)
			{
			case 32:                        //(32)Space
				keycheck(arr, &(*px), &(*py));
				gotoxy16(x, y - 1);
				printf("^");

				Sleep(35);
				printf("\b ");
				if (y <= 6 && arr[y - 1][x - 1] == 30) {
					if (x % 2 == 1) x++;
					gotoxy16(x, y);
					printf("\b%c%c", 0xa2, 0xc2);
				}
				y--;
				break;
			}
		}
	}
	return 1;
}
int enemygun(char(*arr)[XMAX + 1], char key, int *px, int *py)
{
	int x = *px;
	int y = *py;
	int x2 = 0, y2 = 0;
	int num;
	srand(time(NULL));
	x = MAX + 1;
	y = rand() % 4 + 10;
	num = rand() % 3 + 2;
	for (k = 0; k<num; k++)
	{
		for (i = 0; i<1; i++)
		{
			x2 = rand() % 72;
			y2 = rand() % 21;
			if (x2 % 2 == 0)
				x2++;
			if (x2 >= 1 && y2 >= 5 && y <= 18)
			{
				arr[y2 - 1][x2 - 1] = 0xa1;
				arr[y2 - 1][x2] = 0xe0;

				gotoxy16(x2, y2);
				printf("%c%c", arr[y2 - 1][x2 - 1], arr[y2 - 1][x2]);
				if (fall(arr, &x2, &y2, &(*px), &(*py)) == -1)
					return -1;
			}
			else
				i--;
		}
	}
	return 0;
}

int main16(void)
{
	char key = 0;
	char arr[MAX + 4][XMAX + 1] = { 0, };
	int x = 25, y = 24;
	int gunnum = 0;
	int count = 0;
	int checkwin = 0;

	InputNum(arr);

	for (i = 0; i<MAX; i++) {
		for (k = 0; k<XMAX; k++)
		{
			switch (arr[i][k])
			{
			case 1: printf(" ");
				break;
			case 30: printf("%c", 0xa2);
				k++; printf("%c", 0xc2);
				break;
			default: printf("%c", arr[i][k]);
				k++; printf("%c", arr[i][k]);
				break;
			}
		}printf("\n");
	}
	gotoxy16(x, y);
	printf("*");

	do {
		if (GetAsyncKeyState(VK_ESCAPE)<0)
			return 0;

		gun(arr, key, &x, &y);
		if (x >= 0 && x <= XMAX + 1 && y >= 0 && y <= MAX)
			checkwin = movechoongdol(arr, x, y);
		switch (checkwin)
		{
		case -1:
			gotoxy16(40, 22);
			printf("Game Over \n");
			system("pause");
			return 0;
		case 30:
			gotoxy16(40, 21);
			printf("Win !! \n");
			system("pause");
			return 0;
		}

		count++;
		if (count >= 38)
		{
			count = 0;
			if (enemygun(arr, key, &x, &y) == -1) {
				gotoxy16(40, 22);
				printf("Game Over \n");
				system("pause");
				return 0;
			}
		}
	} while (key != 27);
	return 0;
}

// #include "header.h"


void gotoxy16(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int fall(char(*arr)[XMAX + 1], int *px2, int *py2, int *px, int *py)
{
	int x = *px2;
	int y = *py2;
	while (y <= 24)
	{
		Sleep(90);
		gun(arr, 32, &(*px), &(*py));
		keycheck(arr, &(*px), &(*py));
		y++;

		arr[y - 1][x - 1] = 0xa1;
		arr[y - 1][x] = 0xe0;
		gotoxy16(x, y);
		printf("%c%c", arr[y - 1][x - 1], arr[y - 1][x]);           // �������� ����(���ο�) ���.
		if (fallchoongdol(arr, x, y, &(*px), &(*py)) == -1) {
			printf("Game over \n");
			return -1;
		}

		gotoxy16(x, y - 1);
		printf("  \b\b");           // �������� ���ڸ� ������.
		if (y <= 21) {
			gotoxy16(x, y - 1);
			printf("%c%c", 0xa1, 0xe1);       // �������� ������ ��������, ������ ��(��)�� �������µ�, �װ��� �ٽ� ������.
		}
	}
	gotoxy16(x, y);
	printf("  \b\b");
	return 0;
}

