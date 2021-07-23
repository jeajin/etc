#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include "game.h"
#include <time.h>
#pragma warning(disable:4996)
void score();
int js = 0;
int f = 50;
int q = 2;
int g = 0;
void gameover7();
void energy(int w);

void gotoxy7(int x, int y) {

	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetColor(int color) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}

void map7() {

	int i;

	SetColor(7);

	for (i = 1; i<26; i++) {

		gotoxy7(1, i);
		printf("┃");

		gotoxy7(32, i);
		printf("┃");

	}


	SetColor(8);
	gotoxy7(3, 25);
	printf("■■■ ■■■ ■■■ ■■■");
	SetColor(15);



}

void notescore() {


	int a, b, c, d, e, g=0;
	char key, key2;

	srand((signed int)time(NULL));

exit:
	e = (rand() % 9) / 2;


	if (e == 0) {


		for (a = 0; a<25; a++) {
			gotoxy7(5, a);
			printf("◎");
			Sleep(f);
			printf("\b ");
			if (a == 23) {
				key = getch();
				if (key == 100) {
					js += 100;
					printf("\a");
					gotoxy7(50, 3);
					printf("Score : %d", js);
					f -= 1;
					SetColor(14);
					gotoxy7(3, 25);
					printf("■■■");
					SetColor(8);
					printf(" ■■■ ■■■ ■■■");
					SetColor(15);

					if (f<15) {
						f = 15;
						break;
					}


				}
				else {
					energy(q);
					q--;
				}
			}

		}

	}
	else if (e == 1) {


		for (b = 0; b<25; b++) {
			gotoxy7(12, b);
			printf("◎");
			Sleep(f);
			printf("\b ");
			if (b == 23) {
				key = getch();
				if (key == 102) {
					js += 100;
					printf("\a");
					gotoxy7(50, 3);
					printf("Score : %d", js);
					f -= 1;
					SetColor(8);
					gotoxy7(3, 25);
					printf("■■■");
					SetColor(14);
					printf(" ■■■");
					SetColor(8);
					printf(" ■■■ ■■■");
					SetColor(15);
					if (f<15) {
						f = 15;
					}
					break;
				}
				else {
					energy(q);
					q--;
				}
			}
		}
	}
	else if (e == 2) {


		for (c = 0; c<25; c++) {
			gotoxy7(19, c);
			printf("◎");
			Sleep(f);
			printf("\b ");
			if (c == 23) {
				key = getch();
				if (key == 106) {
					js += 100;
					printf("\a");
					gotoxy7(50, 3);
					printf("Score : %d", js);
					f -= 1;
					SetColor(8);
					gotoxy7(3, 25);
					printf("■■■ ■■■");
					SetColor(14);
					printf(" ■■■");
					SetColor(8);
					printf(" ■■■");
					SetColor(15);
					if (f<15) {
						f = 15;

					}
					break;
				}
				else {
					energy(q);
					q--;
				}
			}
		}
	}

	else if (e == 3) {

		for (d = 0; d<25; d++) {
			gotoxy7(26, d);
			printf("◎");
			Sleep(f);
			printf("\b ");
			if (d == 23) {
				key = getch();
				if (key == 107) {
					js += 100;
					printf("\a");
					gotoxy7(50, 3);
					printf("Score : %d", js);
					f -= 1;
					SetColor(8);
					gotoxy7(3, 25);
					printf("■■■ ■■■ ■■■");
					SetColor(14);
					printf(" ■■■");
					SetColor(15);
					if (f<15) {
						f = 15;
					}
					break;
				}
				else {
					energy(q);
					q--;
				}
			}
		}
	}
	else {
	lable:
		if (g == 24) {
			goto exit;
		}
		gotoxy7(12, g);
		printf("◎            ◎");
		Sleep(f);
		gotoxy7(12, g);
		printf("               ");
		g++;
		if (g == 23) {
			key = getch();
			key2 = getch();
			if ((key == 107 || key2 == 102) || (key == 102 || key2 == 107)) {
				js += 100;
				printf("\a");
				gotoxy7(50, 3);
				printf("Score : %d", js);
				f -= 1;
				SetColor(8);
				gotoxy7(3, 25);
				printf("■■■");
				SetColor(14);
				printf(" ■■■");
				SetColor(8);
				printf(" ■■■");
				SetColor(14);
				printf(" ■■■");
				SetColor(15);
				if (f<15) {
					f = 15;
				}

			}
			else {
				energy(q);
				q--;
			}
		}
		if (g<24) {
			goto lable;
		}
	}
}



void energy(int w) {

	if (w == 2) {

		SetColor(12);
		gotoxy7(35, 3);
		printf("♥♥  ");
		SetColor(15);
	}

	if (w == 1) {

		SetColor(12);
		gotoxy7(35, 3);
		printf("♥    ");
		SetColor(15);
	}

	if (w == 0) {
		gotoxy7(35, 3);
		printf("    ");
		gameover7();
	}


}

void gameover7() {

	gotoxy7(13, 10);
	printf("Game over \n\n");
	system("PAUSE");

}

void start7() {

	gotoxy7(33, 11);
	printf("게임 시작 ");
	gotoxy7(28, 13);
	printf("조작키 : D, F, J, K");
	getch();


}


int main7() {

	start7();
	system("CLS");

	gotoxy7(50, 3);
	printf("Score : %d", js);

	SetColor(12);
	gotoxy7(35, 3);
	printf("♥♥♥");
	SetColor(15);

	while (1) {

		map7();
		notescore();
	}

}
