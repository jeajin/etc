#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "game.h"
#pragma warning(disable:4996)
int key;
int x = 1, y = 1;

void gotoxy13(int x, int y)
{
	COORD Pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void gameover13() // 게임 클리어 
{
	system("cls");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ \n");
	printf("                  I                                   I\n");
	printf("                  I            game clear             I\n");
	printf("                  I                                   I\n");
	printf("                  I            감사합니다             I\n");
	printf("                  I            				          I\n");
	printf("                  I            ESC = EXIT             I\n");
	printf("                   ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ \n");
	printf("\n");

	key = getch();
	if (key == 27)
		return;
}

void move9(char key, int *x, int *y, int *x_b, int*y_b, int(*map)[20]) {

	switch (key) {

	case 72: //위 충돌감지 
		*y = *y - 1;
		if (map[*y][*x] == 1)
			*y += 1;
		gotoxy13(*x, *y);
		printf("▲");
		break;
		if (*y<1)
			*y = 1;
		break;
	case 75: // 왼쪽 충돌감지 
		*x = *x - 1;
		if (map[*y][*x] == 1)
			*x += 1;
		gotoxy13(*x, *y);
		printf("◀");
		break;
		if (*x<1)
			*x = 1;
		break;
	case 77: // 오른쪽 충돌감지 
		*x = *x + 1;
		if (map[*y][*x] == 1)
			*x -= 1;
		gotoxy13(*x, *y);
		printf("▶");
		break;
		if (*x>*x_b)
			*x = *x_b;
		break;
	case 80: // 아래 충돌감지 
		*y = *y + 1;
		if (map[*y][*x] == 1)
			*y -= 1;
		gotoxy13(*x, *y);
		printf("▼");
		break;
		if (*y>*y_b)
			*y = *y_b;
		break;
	default:
		break;

	}
}
void map131() // 맵 1 
{
	int i, j, count=0, star;
	int bo1, bo2, bo3, bo4, bo5, bo6;
	int x_b = 18, y_b = 18;

	int map[20][20] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1 },
		{ 1,0,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,1,1,1 },
		{ 1,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,0,1,1,1 },
		{ 1,0,1,0,0,0,0,1,1,0,1,1,0,1,1,1,0,1,1,1 },
		{ 1,0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1 },
		{ 1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1,1,1 },
		{ 1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1 },
		{ 1,1,1,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1 },
		{ 1,1,1,0,1,1,0,1,1,1,0,0,1,1,1,0,1,0,1,1 },
		{ 1,1,1,0,1,1,0,1,1,1,1,0,0,1,1,0,0,0,1,1 },
		{ 1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,1,0,1,1 },
		{ 1,1,1,1,1,1,1,0,1,1,1,0,1,0,0,1,1,1,1,1 },
		{ 1,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1 },
		{ 1,1,1,0,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1 },
		{ 1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,1 },
		{ 1,1,1,0,0,0,0,0,1,1,1,1,0,1.1,1,1,0,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };



	for (i = 0; i<20; i++)
	{
		for (j = 0; j<20; j++)
		{
			if (map[i][j] == 1)
				printf("■"); // 방의 값이 1이면  ■임 
			else if (map[i][j] == 0)
				printf("□"); // 방의 값이 0이면  □임 
		}
		printf("\n");
	}

	while (1)
	{
		srand(time(NULL));
		bo1 = (rand() % 20);
		bo2 = (rand() % 20);
		bo3 = (rand() % 20);
		bo4 = (rand() % 20);
		bo5 = (rand() % 20);
		bo6 = (rand() % 20);

		if (map[bo1][bo2] == 1)
			continue;

		else if (count == 1)
		{
			if (map[bo3][bo4] == 1)
				continue;
			if (map[bo5][bo6] == 1)
				continue;
			if (bo1 == bo3 || bo1 == bo5 || bo3 == bo5);
			continue;
		}

		else
			break; // 보물 벽에 안생기게 만듬 
	}

	gotoxy13(1, 1);
	printf("★");
	gotoxy13(2, 21);
	printf("bo2=%d,bo1=%d", bo2, bo1); // 보물 좌표 나타내기 

	gotoxy13(1, 1);
	printf("★");
	gotoxy13(2, 21);
	printf("bo4=%d,bo3=%d", bo4, bo3); // 보물2 좌표 나타내기 

	gotoxy13(1, 1);
	printf("★");
	gotoxy13(2, 21);
	printf("bo6=%d,bo5=%d", bo6, bo5); // 보물3 좌표 나타내기 

	do {
		key = getch();
		printf("\b ");
		gotoxy13(10, 21);
		printf("x=%d y=%d", x, y); // 캐릭터 위치 나타내기 
		printf("     맵의 값은 : %d", map[x][y]); // 방 값 나타내기 
		move9(key, &x, &y, &x_b, &y_b, map); // 키 

		if (count == 1)

			if (x == bo2 && y == bo1)
			{
				gotoxy13(x, y);
				printf("★ "); // 보물
				star++;
				gotoxy13(5, 25);
				printf("%d", star);
			}
		if (x == bo4 && y == bo3)
		{
			gotoxy13(x, y);
			printf("★ "); // 보물
			star++;
			gotoxy13(5, 25);
			printf("%d", star);
		}

		if (x == bo6 && y == bo5)
		{
			gotoxy13(x, y);
			printf("★ "); // 보물
			star++;
			gotoxy13(5, 25);
			printf("%d", star);
		}

		if (star == 3) {
			system("cls");
			gameover13();
		}

	} while (key != 27);
	gameover13();
}
void map130() // 맵2 
{
	int i, j, count=0;
	int bo1, bo2, bo3, bo4, bo5, bo6;
	int x_b = 18, y_b = 18;

	int map[20][20] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1 },
		{ 1,0,1,1,0,1,0,0,1,1,1,1,1,1,0,1,0,1,1,1 },
		{ 1,0,1,1,0,1,0,1,1,0,1,1,0,0,0,0,0,1,1,1 },
		{ 1,0,1,0,0,0,0,1,1,0,1,1,0,1,1,1,0,1,1,1 },
		{ 1,0,0,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1 },
		{ 1,1,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1,1,1 },
		{ 1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1 },
		{ 1,1,1,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1 },
		{ 1,1,1,0,1,1,0,1,1,1,0,0,1,1,1,0,1,0,1,1 },
		{ 1,1,1,0,1,1,0,1,1,1,1,0,0,1,1,0,0,0,1,1 },
		{ 1,0,0,0,1,1,0,0,1,1,1,1,0,0,1,1,1,0,1,1 },
		{ 1,1,1,1,1,1,1,0,1,1,1,0,1,0,0,1,1,1,1,1 },
		{ 1,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1 },
		{ 1,1,1,0,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1 },
		{ 1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,1 },
		{ 1,1,1,0,0,0,0,0,1,1,1,1,0,1.1,1,1,0,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };



	for (i = 0; i<20; i++)
	{
		for (j = 0; j<20; j++)
		{
			if (map[i][j] == 1)
				printf("■"); // 방의 값이 1이면  ■임 
			else if (map[i][j] == 0)
				printf("□"); // 방의 값이 0이면  □임 
		}
		printf("\n");
	}

	while (1)
	{
		srand(time(NULL));
		bo1 = (rand() % 20);
		bo2 = (rand() % 20);
		bo3 = (rand() % 20);
		bo4 = (rand() % 20);
		bo5 = (rand() % 20);
		bo6 = (rand() % 20);

		if (map[bo1][bo2] == 1)
			continue;

		else if (count == 1)
		{
			if (map[bo3][bo4] == 1)
				continue;
			if (map[bo5][bo6] == 1)
				continue;
			if (bo1 == bo3 || bo1 == bo5 || bo3 == bo5);
			continue;
		}

		else
			break; // 보물 벽에 안생기게 만듬 
	}

	gotoxy13(1, 1);
	printf("★");
	gotoxy13(2, 21);
	printf("bo2=%d,bo1=%d", bo2, bo1); // 보물 좌표 나타내기 

	do {
		key = getch();
		printf("\b ");
		gotoxy13(10, 21);
		printf("x=%d y=%d", x, y); // 캐릭터 위치 나타내기 
		printf("     맵의 값은 : %d", map[x][y]); // 방 값 나타내기 
		move9(key, &x, &y, &x_b, &y_b, map); // 키 
		if (x == bo2 && y == bo1)
		{
			gotoxy13(x, y);
			printf("★ "); // 보물
			count = 1;
			system("cls");
			map131();
		}


	} while (key != 27);
	gameover13();
}



void title13() // 게임 클리어 
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                   ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ \n");
	printf("                  I                                   I\n");
	printf("                  I            game start             I\n");
	printf("                  I                                   I\n");
	printf("                  I           아무거나 누르시오       I\n");
	printf("                   ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ \n");
	printf("\n");

	key = getch();
	if (key == 27)
		return;
	else
		system("cls");
	map130();

}


int main13()
{
	title13();

	return 0;
}
