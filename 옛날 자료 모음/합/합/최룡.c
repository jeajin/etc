#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#pragma warning(disable:4996)
#include "game.h"

void gotoxy17(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main17()
{
	int life = 5, cou = 0;
	char key;
		int mode = 0, i, j, x = 17, y = 1,   exitcou = 0;
	int map[19][19] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1 },
		{ 1,0,1,4,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,4,1,0,1 },
		{ 1,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1,4,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,3,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,3,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };

restart:

	 

	do
	{
		printf("\n");
		printf("　───┐　│　　　│　　　│　───┐　│\n");
		printf("　　　　│　│　──┴──　│　　　　│　│\n");
		printf("　　　　│　│　　 ／＼　 　├─　　　│　│\n");
		printf("　　　　│　│　　／　 ＼　 │　　　　│　│\n");
		printf("\n");
		printf("　　　───┐　　　─────　　　　　　　　　　　  │　　─　　│　\n");
		printf("　　　┌──┘　　　　　／＼　　　　　　　───┐　││　／　＼　│  \n");
		printf("　　　└───　　　 　／　 ＼　　　　　　　　　│　││ │　　│ │  \n");
		printf("　　　　　　　　　　　　　　　　　　　　　　　　│─┤│　＼　／　│　\n");
		printf("　　　　　　　　　　　　　　　　　　　　　　　　│　││    ─　　│　\n");
		printf("　      　┌─조작KEY!!!─┐　　　    　　　　　　　││　　┌──┐　\n");
		printf("　　      │ 　 　△      │　　　　　　　　　　　　││　　│　　│　\n");
		printf("　　      │ 　 ◁▽▷    │　　　　　　　　　　　　　　　　└──┘　\n");
		printf("　　      └───────┘　　　　　　　　　　　　　　　　　　　　　\n");
		printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
		printf("　　　                       ※게임설명※　　　　　　　 　　　　　　　\n");
		printf("\n");
		printf("　　        ★ 맵 안에 있는 ♥ 3개를 모두 획득해야 CLEAR!　　　　　 　\n");
		printf("　        　★ 이동제한횟수 200회! 제한시간 60초!　 　　　          　\n");
		printf("　　        ★ 맵 안에 숨겨져 있는 함정을 밟을시 처음위치로 초기화!　 \n");
		printf("　　　　                                                          　　\n");
		printf("　　　　　         　스페이스바 입력시 GAME START!!　　　　 　　　　　\n");

		key = getch();
		if (key == 27);
		mode++;
	} while (mode = 0);

	while (mode = 1)
	{
		system("cls");
		gotoxy17(45, 3);
		printf("먹어야 할 개수 : %d", 3 - exitcou);
		gotoxy17(45, 5);
		printf("남은 목숨 : %d", life);
		gotoxy17(45, 9);
		printf("이동 제한 횟수 : %d", 200 - cou);
		gotoxy17(45, 7);
		printf("시간 제한 : %d 초", 60 - clock() / 1000);

		for (i = 0; i < 19; i++)
		{
			gotoxy17(1, 1 + i);
			for (j = 0; j < 19; j++)
			{
				if (map[i][j] == 0)
					printf("　");
				else if (map[i][j] == 1)
					printf("■");
				else if (map[i][j] == 2)
					printf("★");
				else if (map[i][j] == 3)
					printf("♥");
				else if (map[i][j] == 4)
					printf("　");
			}
			printf("\n");
		}

		key = getch();

		if (key == 80) // ↓ 
		{
			if (map[y + 1][x] == 0)
			{
				map[y + 1][x] = 2;
				map[y][x] = 0;
				y++;
				cou++;
			}
			else if (map[y + 1][x] == 3)
			{
				map[y + 1][x] = 2;
				map[y][x] = 0;
				y++;
				cou++;
				exitcou++;
			}
			else if (map[y + 1][x] == 4)
			{
				map[y][x] = 0;
				life--;
				gotoxy17(45, 15);
				printf("함정을 밟았습니다");
				getch();
				goto restart;
			}
		}

		else if (key == 75) // ← 
		{
			if (map[y][x - 1] == 0)
			{
				map[y][x - 1] = 2;
				map[y][x] = 0;
				x--;
				cou++;
			}
			else if (map[y][x - 1] == 3)
			{

				map[y][x - 1] = 2;
				map[y][x] = 0;
				x--;
				cou++;
				exitcou++;
			}
			else if (map[y][x - 1] == 4)
			{
				map[y][x] = 0;
				life--;
				gotoxy17(45, 15);
				printf("함정을 밟았습니다");
				getch();
				goto restart;
			}
		}

		else if (key == 72) // ↑ 
		{
			if (map[y - 1][x] == 0)
			{
				map[y - 1][x] = 2;
				map[y][x] = 0;
				y--;
				cou++;
			}
			else if (map[y - 1][x] == 3)
			{
				map[y - 1][x] = 2;
				map[y][x] = 0;
				y--;
				cou++;
				exitcou++;
			}
			else if (map[y - 1][x] == 4)
			{
				map[y][x] = 0;
				life--;
				gotoxy17(45, 15);
				printf("함정을 밟았습니다");
				getch();
				goto restart;
			}
		}

		else if (key == 77) // → 
		{
			if (map[y][x + 1] == 0)
			{
				map[y][x + 1] = 2;
				map[y][x] = 0;
				x++;
				cou++;
			}
			else if (map[y][x + 1] == 3)
			{
				map[y][x + 1] = 2;
				map[y][x] = 0;
				x++;
				cou++;
				exitcou++;
			}
			else if (map[y][x + 1] == 4)
			{
				map[y][x] = 0;
				life--;
				gotoxy17(45, 15);
				printf("함정을 밟았습니다");
				getch();
				goto restart;
			}
		}

		if (cou == 200)
		{
			gotoxy17(4, 7);
			printf("　　　　　　　　　　　　　　　　　");
			gotoxy17(4, 8);
			printf("　┌─────────────┐　");
			gotoxy17(4, 9);
			printf("　│        GAME OVER!        │　");
			gotoxy17(4, 10);
			printf("　│제한횟수를 초과하였습니다.│　");
			gotoxy17(4, 11);
			printf("　└─────────────┘　");
			gotoxy17(4, 12);
			printf("　　　　　　　　　　　　　　　　　");
			system("pause");
		}

		if (clock() / 1000 == 60)
		{
			gotoxy17(4, 7);
			printf("　　　　　　　　　　　　　　　　　");
			gotoxy17(4, 8);
			printf("　┌─────────────┐　");
			gotoxy17(4, 9);
			printf("　│        GAME OVER!        │　");
			gotoxy17(4, 10);
			printf("　│제한시간을 초과하였습니다.│　");
			gotoxy17(4, 11);
			printf("　└─────────────┘　");
			gotoxy17(4, 12);
			printf("　　　　　　　　　　　　　　　　　");
			system("pause");
			return 0;
		}

		if (life == 0)
		{
			gotoxy17(4, 7);
			printf("　　　　　　　　　　　　　　　　　");
			gotoxy17(4, 8);
			printf("　┌─────────────┐　");
			gotoxy17(4, 9);
			printf("　│        GAME OVER!        │　");
			gotoxy17(4, 10);
			printf("　│목숨을 모두 사용하였습니다│　");
			gotoxy17(4, 11);
			printf("　└─────────────┘　");
			gotoxy17(4, 12);
			printf("　　　　　　　　　　　　　　　　　");
			system("pause");
			return 0;
		}

		if (exitcou == 3)
		{
			gotoxy17(4, 7);
			printf("　　　　　　　　　　　　　　　　　");
			gotoxy17(4, 8);
			printf("　┌─────────────┐　");
			gotoxy17(4, 9);
			printf("　│        GAME CLEAR!!      │　");
			gotoxy17(4, 10);
			printf("　└─────────────┘　");
			gotoxy17(4, 11);
			printf("　　　　　　　　　　　　　　　　　");
			system("pause");
			return 0;
		}

	}

}





