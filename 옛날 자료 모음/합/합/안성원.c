
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h> 
#include <conio.h>
#include "game.h"
#pragma warning(disable:4996)
#define MI 25
#define UP 72 // 72 = ��
#define DOWN 80 // 80 = �Ʒ�
#define LEFT 75 // 75 = ����
#define RIGHT 77 // 77 = ������
#define SPACE 32 // 32 = �����̽���
// �� ĳ���� ��� 

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
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,//18  - > �̻��� �߻� ��ġ
		3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 //19  - > �ɸ��� �̵� ��ġ 
	};





	printmap(&map[0]);

	gotoxy10(60, 1);

	printf("������ ���� : ");

	scanf("%d", &find);

	srand((unsigned)time(NULL));

	for (i = 1; i <= find; i++)
	{

		a = rand() % 10 + 2;

		b = rand() % 15 + 2;

		map[a][b] = 9;

		//gotoxy10(60,i+2);
		//printf("���� ��ġ: %d,%d",b,a);

	}

	gotoxy10(11 * 2, 19);
	while (1)
	{

		key = getch();

		printf("\b ");
		move10(key, &map[0]);

		gotoxy10(player_x * 2, player_y);
		printf("\b ");
		printf("��");


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

					printf("��");

					Sleep(MI);
					printf("\b ");


				}

				if (map[i][map_x] == 1)
				{
					gotoxy10(player_x * 2, i);

					Sleep(20);

					printf("��");
					Sleep(MI);
					printf("\b ");

					map[i][map_x] = 0;
					goto change;
				}



				if (map[i][map_x] == 9)
				{


					gotoxy10(map_x * 2, i);
					printf("��");

					for (j = i; j <= player_y; j++)
					{
						map[i][map_x] = 0;

						Sleep(70);
						printf("\b ");
						gotoxy10(map_x * 2, j);
						Sleep(70);
						printf("��");

						if (j == player_y && map_x == player_x)
						{
							score10 += 100;
							gotoxy10(60, 8);
							printf("���� ȹ��");

						}

					}

					gotoxy10(60, 15);
					printf("���� �߰�!");
					gotoxy10(60, 17);
					printf("������ġ :%d,%d", map_x, i);

					gotoxy10(60, 10);
					printf("�������� : %d", score10);
					finsh++;
					goto change;
					if (find == finsh)
					{
						gotoxy10(3, 22);
						printf("������ ��� ã�ҽ��ϴ�.");
						gotoxy10(3, 25);
						system("PAUSE");
						return 0;
					}


				}//����ã�� if�� ��


			}//for ���� ��

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
				printf("��");
			}
			else if (map[x][y] == 3)
			{
				printf("��");
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
