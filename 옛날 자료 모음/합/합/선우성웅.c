#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "game.h"
#pragma warning(disable:4996)
void gotoxy8(int x, int y)//좌표 지정 함수 
{
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
move8(char key, int *x1, int *y1, int x_b, int y_b)//커서 이동  
{
	switch (key)
	{
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
int main8()
{
	char key;
	int i, j;
	int r1, r2;
	int map[14][13] =
	{
		{ '1','a','b','c','d','e','f','g','h','i','j','k','1' },
		{ 'a','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ 'b','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ 'c','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ 'd','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ 'e','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ 'f','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ 'g','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ 'h','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ 'i','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ 'j','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ 'k','0','0','0','0','0','0','0','0','0','0','0','1' },
		{ '1','1','1','1','1','1','1','1','1','1','1','1','1' }
	};
	int a;
	srand((signed int)time(NULL));

	printf("★함수보물찾기★\n");
	printf("시작하려면 1번을 눌러주세요 종료하고 싶다면 0번을 눌러주세요\n");
	scanf("%d", &a);

	switch (a)
	{
	case 1:
		printf("게임을 시작합니다");
		break;
	case 0:
		printf("프로그램을 종료합니다.");
		return 0;
		break;
	default:
		printf("잘못 입력하셨습니다. 프로그램을 종료합니다.");
		return 0;
		break;
	}

	system("cls");
	for (j = 0; j<14; j++)
	{
		for (i = 0; i<13; i++)
		{
			if (map[j][i] == 'a')
				printf("00");
			if (map[j][i] == 'b')
				printf("01");
			if (map[j][i] == 'c')
				printf("02");
			if (map[j][i] == 'd')
				printf("03");
			if (map[j][i] == 'e')
				printf("04");
			if (map[j][i] == 'f')
				printf("05");
			if (map[j][i] == 'g')
				printf("06");
			if (map[j][i] == 'h')
				printf("07");
			if (map[j][i] == 'i')
				printf("08");
			if (map[j][i] == 'j')
				printf("09");
			if (map[j][i] == 'k')
				printf("10");
			if (map[j][i] == '1')
				printf("■");
			if (map[j][i] == '0')
				printf("  ");
		}
		printf("\n");
	}
	r1 = rand() % 14;
	r2 = rand() % 10;
	printf("보물 찾기를 시작합니다 1개의 보물을 찾아 보세요\n");
	printf("보물의 좌표는  %d.%d 입니다", r1, r2);

	i = 3;
	j = 2;

	do
	{
		gotoxy8(i, j);
		printf("☆");
		key = getch();
		printf("\b\b  ");
		if (r1 == i&&r2 == j)
			printf("\b\b★");
		move8(key, &i, &j, 27, 15);
	} while (key != 27);



	return 0;
}
