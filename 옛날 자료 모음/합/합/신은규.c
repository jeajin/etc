#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include "game.h"
#pragma warning(disable:4996)

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

#define MAP_X 1 //x축 시작점
#define MAP_Y 1 //y축 시작점
#define MAX_Y 23 //y축 끝
#define MAX_X 38 //x축 끝

int key;
int length;
int xx[100];
int yy[100];
int way;        //지금움직이고있는 방향 
int speed;
int score;
int best;
int cat_x, cat_y;
int count = 0;

void gotoxy(int xx, int yy, char *s)
{
	COORD pos = { 2 * xx,yy };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}


void cat()  //벽안에 안생기게 만드는거 
{
	int i, j;
	int decide = 0;
	int r = 0;

	gotoxy(MAX_X - 6, MAX_Y / 3, "SCORE : ");
	printf("%d", score);
	gotoxy(MAP_X + 10, MAX_Y, "length= ");
	printf("%d", length);
	gotoxy(MAP_X + 16, MAX_Y, "SPEED= ");
	printf("%d", 100 - speed);
	gotoxy(MAX_X - 6, MAX_Y / 3 - 1, "level : ");
	printf("%d", count + 1);

	while (1) {

	decidea:
		srand((unsigned)time(NULL));
		cat_x = ((rand() % (MAX_X - 10)) + 2);    //벽안에 안생기게  2~29 3~21
		cat_y = ((rand() % (MAX_Y - 3)) + 2);

		for (i = 0; i<length; i++) {    //몸안에 안생기게
			if (xx[i] == cat_x && yy[i] == cat_y)
				goto decidea;
		}

		for (i = 3; i<8; i++) {
			if (cat_x == 5 && cat_y == i)  //x-1번째 벽에 맞았을때  1~6
				goto decidea;
		}

		for (i = 3; i<11; i++) {
			if (cat_x == 8 && cat_y == i)  //x-2번째 벽에 맞았을때  1~10
				goto decidea;
		}

		for (i = 3; i<6; i++) {
			if (cat_x == 15 && cat_y == i)  //x-3번째 벽에 맞았을때  1~5
				goto decidea;
		}

		for (i = 3; i<9; i++) {
			if (cat_x == 20 && cat_y == i)  //x-4번째 벽에 맞았을때  1~9
				goto decidea;
		}

		for (i = 3; i<8; i++) {
			if (cat_x == 25 && cat_y == i)  //x-5번째 벽에 맞았을때  1~7
				goto decidea;
		}

		for (i = 14; i <= 22; i++) {
			if (cat_x == 27 && cat_y == i)  //y-1번째 벽에 맞았을때  14~22
				goto decidea;
		}

		for (i = 16; i <= 22; i++) {
			if (cat_x == 15 && cat_y == i)  //y-2번째 벽에 맞았을때  16~22
				goto decidea;
		}

		for (i = 15; i <= 20; i++) {
			if (cat_x == 7 && cat_y == i)  //y-3번째 벽에 맞았을때  15~20
				goto decidea;
		}

		for (i = 13; i<21; i++) {
			if (cat_x == i && cat_y == 9)  //중간 벽에 맞았을때  X가 13~20 
				goto decidea;
		}

		gotoxy(22, 22, "■");
		gotoxy(5, 5, "■");
		gotoxy(8, 8, "■");
		gotoxy(cat_x, cat_y, "◆");
		gotoxy(MAP_X + 22, MAX_Y, "x=");
		printf("%d", cat_x);
		gotoxy(MAP_X + 25, MAX_Y, "y=");
		printf("%d", cat_y);
		gotoxy(22, 22, "■");
		gotoxy(5, 5, "■");
		gotoxy(8, 8, "■");
		speed -= 3;
		break;
	}
}

void map() //맵
{
	int i;
	system("mode con: cols=80 lines=25"); //콘솔창 크기조정 
	for (i = 0; i<MAX_X; i++) {         	//X축 위 
		gotoxy(MAP_X + i, MAP_Y, "■");
	}
	for (i = MAP_Y + 1; i<MAX_Y; i++) {
		gotoxy(MAP_X, i, "■");  		//Y축 좌 
		gotoxy(MAX_X, i, "■"); 		 //Y축 우 
		gotoxy(MAX_X - 8, i - 1, "■");	 //Y축 우측에서 2번째 
	}
	for (i = 0; i<MAX_X; i++) {
		gotoxy(MAP_X + i, MAX_Y - 1, "■");  //X축 아래 
	}

	for (i = 0; i<7; i++)
	{
		gotoxy(5, MAP_Y + i, "■");  	 //Y축 위 1 
	}

	for (i = 0; i<10; i++)
	{
		gotoxy(8, MAP_Y + i, "■");			//Y축 위 2
	}

	for (i = 0; i<5; i++)
	{
		gotoxy(15, MAP_Y + i, "■");		//Y축 위 3
	}

	for (i = 0; i<9; i++)
	{
		gotoxy(20, MAP_Y + i, "■");		//Y축 위 4 
	}

	for (i = 0; i<7; i++)
	{
		gotoxy(25, MAP_Y + i, "■");		//Y축 위 5 
	}

	for (i = 20; i>12; i--)
	{
		gotoxy(i, 9, "■");   			//X축 중간 
	}

	for (i = 1; i<9; i++)
	{
		gotoxy(27, MAX_Y - i, "■");		//Y축 아래 3 
	}

	for (i = 1; i<7; i++)
	{
		gotoxy(15, MAX_Y - i, "■");		//Y축 아래 2 
	}

	for (i = 3; i<9; i++)
	{
		gotoxy(7, MAX_Y - i, "■");			//Y축 아래 1 
	}


	gotoxy(MAX_X - 6, MAX_Y / 3 + 4, "BEST : ");
	printf("%d", best);
}

void set() //게임 시작설정
{
	int i;
	score = 0;
	length = 5;
	speed = 100;
	way = LEFT;

	if (count == 1)
	{
		speed = 50;
		system("cls");
		map();
	}

	if (count == 0)
	{
		system("cls");
		map();
	}


	for (i = 0; i<length; i++)
	{
		xx[i] = MAX_X / 2 + i;
		yy[i] = MAX_Y / 2;
		gotoxy(xx[i], yy[i], "＊");
	}
	gotoxy(xx[0], yy[0], "★");
	cat();
}

void gameover() //게임오버일시 
{

	system("cls");
	gotoxy(MAP_X, MAP_Y, " ");
	gotoxy(MAP_X + 10, MAP_Y + 3, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 4, "〓          Game Over         〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 5, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 7, "    ▶ 작성자 : 신 은 규       \n");
	gotoxy(MAP_X + 10, MAP_Y + 11, "    ▶ YOUR SCORE = ");
	printf("%d\n", score);
	gotoxy(MAP_X + 10, MAP_Y + 13, "    ▶ ESC : 나 가 기           \n");
	gotoxy(MAP_X + 10, MAP_Y + 15, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	if (best<score)
		best = score;

	while (1)
	{
		gotoxy(MAP_X + 10, MAP_Y + 9, "    <PRESS ANY KEY TO RESTART>   \n");
		Sleep(400);
		gotoxy(MAP_X + 10, MAP_Y + 9, "                                 \n");
		Sleep(400);

		if (kbhit())
		{
			key = getch();

			if (key == ESC)
				exit(0);
			else
				break;
		}
	}

	set();
}


void levelup() //게임오버일시 
{

	system("cls");
	gotoxy(MAP_X, MAP_Y, " ");
	gotoxy(MAP_X + 10, MAP_Y + 3, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 4, "〓          lever up          〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 5, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 7, "    ▶ 작성자 : 신 은 규       \n");
	gotoxy(MAP_X + 10, MAP_Y + 11, "    ▶ YOUR SCORE = ");
	printf("%d\n", score);
	gotoxy(MAP_X + 10, MAP_Y + 13, "    ▶ ESC : 나 가 기           \n");
	gotoxy(MAP_X + 10, MAP_Y + 15, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	if (best<score)
		best = score;

	while (1)
	{
		gotoxy(MAP_X + 10, MAP_Y + 9, "    <PRESS ANY KEY TO RESTART>   \n");
		Sleep(400);
		gotoxy(MAP_X + 10, MAP_Y + 9, "                                 \n");
		Sleep(400);

		if (kbhit())
		{
			key = getch();

			if (key == ESC)
				exit(0);
			else
				break;
		}
	}
	set();
}

void leveldown() //게임오버일시 
{

	system("cls");
	gotoxy(MAP_X, MAP_Y, " ");
	gotoxy(MAP_X + 10, MAP_Y + 3, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 4, "〓          lever down        〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 5, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 7, "    ▶ 작성자 : 신 은 규       \n");
	gotoxy(MAP_X + 10, MAP_Y + 11, "    ▶ YOUR SCORE = ");
	printf("%d\n", score);
	gotoxy(MAP_X + 10, MAP_Y + 13, "    ▶ ESC : 나 가 기           \n");
	gotoxy(MAP_X + 10, MAP_Y + 15, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	if (best<score)
		best = score;

	while (1)
	{
		gotoxy(MAP_X + 10, MAP_Y + 9, "    <PRESS ANY KEY TO RESTART>   \n");
		Sleep(400);
		gotoxy(MAP_X + 10, MAP_Y + 9, "                                 \n");
		Sleep(400);

		if (kbhit())
		{
			key = getch();

			if (key == ESC)
				exit(0);
			else
				break;
		}
	}
	set();
}


void move(int way) //움직임 
{
	int i;

	if (xx[0] == cat_x && yy[0] == cat_y)  //쪼그만거 먹었을때 
	{
		gotoxy(22, 22, "■");
		gotoxy(5, 5, "■");
		gotoxy(8, 8, "■");
		score += 10;
		if (score == 50)
		{
			count = 1;
			levelup();
		}
		cat();
		length += 1;
		xx[length - 1] = xx[length - 2];
		yy[length - 1] = xx[length - 2];
		gotoxy(22, 22, "■");
		gotoxy(5, 5, "■");
		gotoxy(8, 8, "■");
	}

	if (xx[0] == MAP_X || yy[0] == MAP_Y || xx[0] == MAX_X - 8 || yy[0] == MAX_Y - 1) //벽에 충돌할경우
	{
		if (count == 1)
		{
			count = 0;
			leveldown();
		}
		else if (count == 0)
			gameover();
		return;
	}

	for (i = 1; i<8; i++) {
		if (xx[0] == 5 && yy[0] == i)  //x-1번째 벽에 맞았을때 
		{
			if (count == 1)
			{
				count = 0;
				leveldown();
			}
			else if (count == 0)
				gameover();
			return;
		}
	}

	for (i = 1; i<11; i++) {
		if (xx[0] == 8 && yy[0] == i)  //x-2번째 벽에 맞았을때 
		{
			if (count == 1)
			{
				count = 0;
				leveldown();
			}
			else if (count == 0)
				gameover();
			return;
		}
	}

	for (i = 1; i<6; i++) {
		if (xx[0] == 15 && yy[0] == i)  //x-3번째 벽에 맞았을때 
		{
			if (count == 1)
			{
				count = 0;
				leveldown();
			}
			else if (count == 0)
				gameover();
			return;
		}
	}

	for (i = 1; i<9; i++) {
		if (xx[0] == 20 && yy[0] == i)  //x-4번째 벽에 맞았을때 
		{
			if (count == 1)
			{
				count = 0;
				leveldown();
			}
			else if (count == 0)
				gameover();
			return;
		}
	}

	for (i = 1; i<8; i++) {
		if (xx[0] == 25 && yy[0] == i)  //x-5번째 벽에 맞았을때 
		{
			if (count == 1)
			{
				count = 0;
				leveldown();
			}
			else if (count == 0)
				gameover();
			return;
		}
	}

	for (i = 1; i<9; i++) {
		if (xx[0] == 27 && yy[0] == (MAX_Y - i))  //y-1번째 벽에 맞았을때 
		{
			if (count == 1)
			{
				count = 0;
				leveldown();
			}
			else if (count == 0)
				gameover();
			return;
		}
	}

	for (i = 1; i<7; i++) {
		if (xx[0] == 15 && yy[0] == (MAX_Y - i))  //y-2번째 벽에 맞았을때 
		{
			if (count == 1)
			{
				count = 0;
				leveldown();
			}
			else if (count == 0)
				gameover();
			return;
		}
	}

	for (i = 3; i<9; i++) {
		if (xx[0] == 7 && yy[0] == (MAX_Y - i))  //y-3번째 벽에 맞았을때 
		{
			if (count == 1)
			{
				count = 0;
				leveldown();
			}
			else if (count == 0)
				gameover();
			return;
		}
	}

	for (i = 20; i>12; i--) {
		if (xx[0] == i && yy[0] == 9)  //중간 벽에 맞았을때 
		{
			if (count == 1)
			{
				count = 0;
				leveldown();
			}
			else if (count == 0)
				gameover();
			return;
		}
	}


	for (i = 1; i<length; i++) //몸통에 맞았을때 
	{
		if (xx[0] == xx[i] && yy[0] == yy[i])
		{
			if (count == 1)
			{
				count = 0;
				leveldown();
			}
			else if (count == 0)
				gameover();
			return;
		}
	}

	gotoxy(xx[length - 1], yy[length - 1], "  ");
	for (i = length - 1; i>0; i--) //앞몸통의좌표를 뒷몸통에 넣기
	{
		xx[i] = xx[i - 1];
		yy[i] = yy[i - 1];
	}

	for (i = 1; i<length - 1; i++) //몸통 소환
	{
		gotoxy(xx[i], yy[i], "＊");
	}

	if (way == LEFT)
	{
		xx[0]--;
		gotoxy(xx[0], yy[0], "◁");
	}
	else if (way == RIGHT)
	{
		xx[0]++;
		gotoxy(xx[0], yy[0], "▷");
	}
	else if (way == UP)
	{
		yy[0]--;
		gotoxy(xx[0], yy[0], "△");
	}
	else if (way == DOWN)
	{
		yy[0]++;
		gotoxy(xx[0], yy[0], "▽");
	}
}


void title() //처음 시작 화면
{
	gotoxy(MAP_X + 10, MAP_Y + 3, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 4, "〓         GAME START         〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 5, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
	gotoxy(MAP_X + 10, MAP_Y + 7, "    ▶ 작성자 : 신 은 규       \n");
	gotoxy(MAP_X + 10, MAP_Y + 11, "    ▶ key = ↑ → ← ↓      \n");
	gotoxy(MAP_X + 10, MAP_Y + 13, "    ▶ ESC = 나 가 기          \n");
	gotoxy(MAP_X + 10, MAP_Y + 15, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

	while (1)
	{
		gotoxy(MAP_X + 10, MAP_Y + 9, "    <PRESS ANY KEY TO START>   \n");
		Sleep(400);
		gotoxy(MAP_X + 10, MAP_Y + 9, "                               \n");
		Sleep(400);

		if (kbhit())
		{
			key = getch();

			if (key == ESC)
				exit(0);
			else
				break;
		}
	}
	set();
}

int main9()
{


	title();

	while (1)
	{
		if (kbhit()) do { key = getch(); } while (key == 224); //계속 움직이게 해주는거
		Sleep(speed);

		switch (key)
		{
		case LEFT:
		case RIGHT:
		case UP:
		case DOWN:
			if ((way == LEFT&&key != RIGHT) ||
				(way == RIGHT&&key != LEFT) ||
				(way == UP&&key != DOWN) ||
				(way == DOWN&&key != UP))
				way = key;
			break;

		case ESC:
			goto end;
		}
		move(way);
	}
	end:
	
	return 0;
}

