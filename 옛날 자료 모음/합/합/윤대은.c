#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "game.h"
void gotoxy18(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void ddong(int x, int y, int *life)//ddong 함수 
{
	int static a = 10;
	int static i = 0;
	Sleep(50);
	srand(time(NULL));


	if (x == a&&y == i + 1)//x좌표와 똥 좌표의 값이 충돌하면 
	{
		*life -= 1;//life 주소의 있는 life 값을 -- 
		gotoxy18(a, i);
		printf("  ");
		i = 0;//i값 초기화 
		a = rand() % 18 * 2 + 2;//다시 똥 초기화 

	}
	else if (i == 23)//똥이 맨밑에 도달했을시 
	{
		gotoxy18(a, i);
		printf("  ");
		i = 0;
		Sleep(50);
		a = rand() % 18 * 2 + 2;       //초기화 
	}
	else//그게아니면 그냥 똥이 떨어짐 
	{
		gotoxy18(a, i + 1);
		printf("♨");
		gotoxy18(a, i);
		printf("  ");
		i += 1;
	}
}

void ddong2(int x, int y, int *life)
{
	int static b = 10;
	int static i = 0;
	srand(time(NULL));


	if (x == b&&y == i + 1)
	{
		*life -= 1;
		gotoxy18(b, i);
		printf("  ");
		i = 0;
		b = rand() % 17 * 2 + 2;

	}
	else if (i == 23)
	{
		gotoxy18(b, i);
		printf("  ");
		i = 0;
		Sleep(50);
		b = rand() % 17 * 2 + 2;
	}
	else
	{
		gotoxy18(b, i + 1);
		printf("♨");
		gotoxy18(b, i);
		printf("  ");
		i += 1;
	}
}

void ddong3(int x, int y, int *life)
{
	int static c = 10;
	int static i = 0;
	srand(time(NULL));


	if (x == c&&y == i + 1)
	{
		*life -= 1;
		gotoxy18(c, i);
		printf("  ");
		i = 0;
		c = rand() % 16 * 2 + 2;

	}
	else if (i == 23)
	{
		gotoxy18(c, i);
		printf("  ");
		i = 0;
		Sleep(50);
		c = rand() % 16 * 2 + 2;
	}
	else
	{
		gotoxy18(c, i + 1);
		printf("♨");
		gotoxy18(c, i);
		printf("  ");
		i += 1;
	}
}

void ddong4(int x, int y, int *life)
{
	int static d = 10;
	int static i = 0;
	srand(time(NULL));


	if (x == d&&y == i + 1)
	{
		*life -= 1;
		gotoxy18(d, i);
		printf("  ");
		i = 0;
		d = rand() % 15 * 2 + 2;

	}
	else if (i == 23)
	{
		gotoxy18(d, i);
		printf("  ");
		i = 0;
		Sleep(50);
		d = rand() % 15 * 2 + 2;
	}
	else
	{
		gotoxy18(d, i + 1);
		printf("♨");
		gotoxy18(d, i);
		printf("  ");
		i += 1;
	}
}

void ddong5(int x, int y, int *life)
{
	int static e = 10;
	int static i = 0;
	srand(time(NULL));


	if (x == e&&y == i + 1)
	{
		*life -= 1;
		gotoxy18(e, i);
		printf("  ");
		i = 0;
		e = rand() % 14 * 2 + 2;

	}
	else if (i == 23)
	{
		gotoxy18(e, i);
		printf("  ");
		i = 0;
		Sleep(50);
		e = rand() % 14 * 2 + 2;
	}
	else
	{
		gotoxy18(e, i + 1);
		printf("♨");
		gotoxy18(e, i);
		printf("  ");
		i += 1;
	}
}


int main18()
{

	int map[25][20] = {
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	};
	int i, j, score = 0, life=0;
	int x = 20, y = 23;

	for (i = 0; i<25; i++)
	{
		for (j = 0; j<20; j++)
		{
			if (map[i][j] == 1)
				printf("■");
			else if (map[i][j] == 0)
				printf("  ");
		}
		printf("\n");
	}

	gotoxy18(50, 10);
	printf("목숨 : ", life);
	gotoxy18(50, 12);
	printf("점수 : ", score);
	gotoxy18(50, 8);
	printf("your life ? : ");//목숨 입력받음 
	scanf_s("%d", &life);
	Sleep(1000);//1초 기다린후 
	gotoxy18(50, 8);
	printf("                 ");

	gotoxy18(x, y);
	printf("＠");
	gotoxy18(50, 8);
	printf("현재 상황");

	while (life != 0 && score<200)//점수가 200점 미만일때 
	{
		gotoxy18(50, 10);
		printf("목숨 : %d", life);
		gotoxy18(50, 12);
		printf("점수 : %d", score);
		score++;

		ddong(x, 23, &life);//똥은 하나떨어진다 

		if (GetAsyncKeyState(VK_RIGHT)<0) {

			if (x <= 2)
				x = 4;
			else if (x >= 36)
				x = 34;
			else
				x += 2;
			gotoxy18(x, y);
			printf("＠");
			gotoxy18(x - 2, y);
			printf("  ");
		}
		else if (GetAsyncKeyState(VK_LEFT)<0) {

			if (x <= 2)
				x = 4;
			else if (x >= 36)
				x = 34;
			else
				x -= 2;
			gotoxy18(x, y);
			printf("＠");
			gotoxy18(x + 2, y);
			printf("  ");
		}



	}


	while (life != 0 && score >= 200 && score<500)//200점 이상일땐 똥 2개 떨어지게함 
	{
		gotoxy18(50, 10);
		printf("목숨 : %d", life);
		gotoxy18(50, 12);
		printf("점수 : %d", score);
		score++;

		ddong(x, 23, &life);
		ddong2(x, 23, &life);//똥 함수 두개사용 

		if (GetAsyncKeyState(VK_RIGHT)<0) {

			if (x <= 2)
				x = 4;
			else if (x >= 36)
				x = 34;
			else
				x += 2;
			gotoxy18(x, y);
			printf("＠");
			gotoxy18(x - 2, y);
			printf("  ");
		}
		else if (GetAsyncKeyState(VK_LEFT)<0) {

			if (x <= 2)
				x = 4;
			else if (x >= 36)
				x = 34;
			else
				x -= 2;
			gotoxy18(x, y);
			printf("＠");
			gotoxy18(x + 2, y);
			printf("  ");
		}
	}

	while (life != 0 && score >= 500 && score<700)
	{
		gotoxy18(50, 10);
		printf("목숨 : %d", life);
		gotoxy18(50, 12);
		printf("점수 : %d", score);
		score++;

		ddong(x, 23, &life);
		ddong2(x, 23, &life);
		ddong3(x, 23, &life);

		if (GetAsyncKeyState(VK_RIGHT)<0) {

			if (x <= 2)
				x = 4;
			else if (x >= 36)
				x = 34;
			else
				x += 2;
			gotoxy18(x, y);
			printf("＠");
			gotoxy18(x - 2, y);
			printf("  ");
		}
		else if (GetAsyncKeyState(VK_LEFT)<0) {

			if (x <= 2)
				x = 4;
			else if (x >= 36)
				x = 34;
			else
				x -= 2;
			gotoxy18(x, y);
			printf("＠");
			gotoxy18(x + 2, y);
			printf("  ");
		}
	}

	while (life != 0 && score >= 700 && score<1000)
	{
		gotoxy18(50, 10);
		printf("목숨 : %d", life);
		gotoxy18(50, 12);
		printf("점수 : %d", score);
		score++;

		ddong(x, 23, &life);
		ddong2(x, 23, &life);
		ddong3(x, 23, &life);
		ddong4(x, 23, &life);

		if (GetAsyncKeyState(VK_RIGHT)<0) {

			if (x <= 2)
				x = 4;
			else if (x >= 36)
				x = 34;
			else
				x += 2;
			gotoxy18(x, y);
			printf("＠");
			gotoxy18(x - 2, y);
			printf("  ");
		}
		else if (GetAsyncKeyState(VK_LEFT)<0) {

			if (x <= 2)
				x = 4;
			else if (x >= 36)
				x = 34;
			else
				x -= 2;
			gotoxy18(x, y);
			printf("＠");
			gotoxy18(x + 2, y);
			printf("  ");
		}
	}

	while (life != 0 && score >= 1000)
	{
		gotoxy18(50, 10);
		printf("목숨 : %d", life);
		gotoxy18(50, 12);
		printf("점수 : %d", score);
		score++;

		ddong(x, 23, &life);
		ddong2(x, 23, &life);
		ddong3(x, 23, &life);
		ddong4(x, 23, &life);
		ddong5(x, 23, &life);

		if (GetAsyncKeyState(VK_RIGHT)<0) {

			if (x <= 2)
				x = 4;
			else if (x >= 36)
				x = 34;
			else
				x += 2;
			gotoxy18(x, y);
			printf("＠");
			gotoxy18(x - 2, y);
			printf("  ");
		}
		else if (GetAsyncKeyState(VK_LEFT)<0) {

			if (x <= 2)
				x = 4;
			else if (x >= 36)
				x = 34;
			else
				x -= 2;
			gotoxy18(x, y);
			printf("＠");
			gotoxy18(x + 2, y);
			printf("  ");
		}
	}
	//똥 함수가 모두 끝나면 모든 텍스트 지우고 game over 텍스트 출력 
	for (i = 0; i <= 25; i++)
	{
		for (j = 0; j <= 20; j++)
		{
			printf("  ");
		}
		printf("\n");
	}

	printf("Game Over\n");
	printf("Your Score : %d\n", score);

	Sleep(3000);


}

