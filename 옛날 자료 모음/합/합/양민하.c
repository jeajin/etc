/*****************
슬롯이 빙글빙글 돌아가는 코드.
but,한게임이 끝나고 다시 게임전체 루프를 돌리면 슬롯이 안돌아가는 일 발생!!!

*****************/



#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "game.h"
#pragma warning(disable:4996)

#define ENTER 13

void goroxy12(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);	//커서위치를 받아내기 위한 함수
}

int main12(void) {

	int bating = 0;
	int random = 0;
	int slot[3];
	int key;
	int i=0;

	srand((signed int)time(NULL));


	do {
		printf(
			"배팅액을 입력 해 주세요.\n"
			"배팅액 : ");
		scanf("%d", &bating);
		puts("");

		printf("%d원을 배팅했습니다.\n", bating);
		printf("시작하려면 아무 키나 눌러주세요.\n");
		printf("멈추려면 ENTER키를 눌러주세요.\n");
		getch();	//키값 입력받음 
		goroxy12(1, 7);
		printf(" |");
		do {
			Sleep(80);
			random = (rand() % 3);
			slot[0] = random;
			goroxy12(3, 7);// 첫번째 슬롯 위치 
			printf(" %d |", slot[0]);

			random = (rand() % 3);
			slot[1] = random;
			goroxy12(7, 7);// 두번째 슬롯 위치 
			printf(" %d |", slot[1]);

			random = (rand() % 3);
			slot[2] = random;
			goroxy12(11, 7);// 세번째 슬롯 위치 
			printf(" %d |", slot[2]);
			if (kbhit())
				key = getch();
		} while (key != ENTER);	//ENTER를 치기 전까지는 슬롯은 무한루프로 돌아감 

		printf("\n\n");


		if (slot[0] == slot[1] && slot[1] == slot[2])
		{
			switch (slot[i])
			{
			case 0:
				bating *= 2;
				printf("★☆★잭☆팟★☆★\n");
				printf("배팅금의 2배를 얻어 %d원이 되었습니다.\n", bating);	//0,0,0으로 맞았을 때 배팅액 2배 
				break;
			case 1:
				bating *= 3;
				printf("★☆★잭☆팟★☆★\n");
				printf("배팅금의 3배를 얻어 %d원이 되었습니다.\n", bating);	//1,1,1으로 맞았을 때 배팅액 3배 
				break;
			case 2:
				bating *= 5;
				printf("★☆★잭☆팟★☆★\n");
				printf("배팅금의 5배를 얻어 %d원이 되었습니다.\n", bating);	//2,2,2으로 맞았을 때 배팅액 5배 
				break;
			}
		}
		else
		{
			printf("꽝! 다음 기회에..\n");	//맞지 않았을때 출력 
		}


		printf("다시 시작하려면 아무키나  눌러주세요.\n");
		printf("끝내려면 ESC를 눌러주세요.\n");
		key = getch();
		system("cls");

	} while (key != 27);

	return 0;
}
