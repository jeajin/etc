
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h> 
#include <conio.h>
#include "game.h"
#pragma warning(disable:4996)
#define MI 25
#define UP 72 // 72 = 위
#define DOWN 80 // 80 = 아래
#define LEFT 75 // 75 = 왼쪽
#define RIGHT 77 // 77 = 오른쪽
#define SPACE 32 // 32 = 스페이스바
// Å 캐릭터 모양 

void printmap(int map[][30]);

void move10(int key, int rodmap[][30]);

void CursorUtil_Hide()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void gotoxy10(int x, int y)
{
	COORD Player_Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Player_Pos);
}


int player_x = 11;
int player_y = 19;
int map_x = 11;
int map_y = 19;
int find = 0;
int score10 = 000;
int finsh = 0;

int main10()
{
	CursorUtil_Hide();

	int key;

	int a, b, i, j;


	int map[20][30] =
	{
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,//0.0~29
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//1.0~29
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//2.0~29
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//3.0~29
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//4
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//5
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//6
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//7
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//8
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//9
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//10
		3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,//11
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,//12  
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,//13
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,//14
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,//15
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,//16
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,//17
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,//18  - > 미사일 발사 위치
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 //19  - > 케릭터 이동 위치 
	};





	printmap(&map[0]);

	gotoxy10(60, 1);

	printf("보물의 갯수 : ");

	scanf("%d", &find);

	srand((unsigned)time(NULL));

	for (i = 1; i <= find; i++)
	{

		a = rand() % 10 + 2;

		b = rand() % 15 + 2;

		map[a][b] = 9;

		//gotoxy10(60,i+2);
		//printf("보물 위치: %d,%d",b,a);

	}

	gotoxy10(11 * 2, 19);
	while (1)
	{

		key = getch();

		printf("\b ");
		move10(key, &map[0]);

		gotoxy10(player_x * 2, player_y);
		printf("\b ");
		printf("Å");


		if(key==27){break;
		}
		if (key == SPACE)
		{


			for (i = player_y - 1; i >= (player_y - 18); i--)
			{


				if (map[i][map_x] == 0)
				{

					gotoxy10(player_x * 2, i);

					Sleep(20);

					printf("│");

					Sleep(MI);
					printf("\b ");


				}

				if (map[i][map_x] == 1)
				{
					gotoxy10(player_x * 2, i);

					Sleep(20);

					printf("│");
					Sleep(MI);
					printf("\b ");

					map[i][map_x] = 0;
					goto change;
				}



				if (map[i][map_x] == 9)
				{


					gotoxy10(map_x * 2, i);
					printf("★");

					for (j = i; j <= player_y; j++)
					{
						map[i][map_x] = 0;

						Sleep(70);
						printf("\b ");
						gotoxy10(map_x * 2, j);
						Sleep(70);
						printf("★");

						if (j == player_y && map_x == player_x)
						{
							score10 += 100;
							gotoxy10(60, 8);
							printf("보물 획득");

						}

					}

					gotoxy10(60, 15);
					printf("보물 발견!");
					gotoxy10(60, 17);
					printf("보물위치 :%d,%d", map_x, i);

					gotoxy10(60, 10);
					printf("현재점수 : %d", score10);
					finsh++;
					goto change;
					if (find == finsh)
					{
						gotoxy10(3, 22);
						printf("보물을 모두 찾았습니다.");
						gotoxy10(3, 25);
						system("PAUSE");
						return 0;
					}


				}//보물찾기 if의 끝


			}//for 문의 끝

		change:;

		}







	}


	return 0;
}

void printmap(int map[][30]) {

	int x, y;

	for (x = 0; x<20; x++)
	{
		for (y = 0; y<30; y++)
		{
			if (map[x][y] == 1)
			{
				printf("■");
			}
			else if (map[x][y] == 3)
			{
				printf("▩");
			}
			else
			{
				printf("  ");
			}

		}
		printf("\n");
	}


}



void move10(int key, int rodmap[][30])
{

	

	switch (key)

	{

	case LEFT: {
		map_x--, player_x--;
		if (player_x == 0)

			map_x++, player_x++;

		break;
	}




	case RIGHT: {
		map_x++, player_x++;
		if (player_x == 29)

			map_x--, player_x--;

		break;
	}







	}

}
