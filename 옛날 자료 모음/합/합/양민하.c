/*****************
������ ���ۺ��� ���ư��� �ڵ�.
but,�Ѱ����� ������ �ٽ� ������ü ������ ������ ������ �ȵ��ư��� �� �߻�!!!

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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);	//Ŀ����ġ�� �޾Ƴ��� ���� �Լ�
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
			"���þ��� �Է� �� �ּ���.\n"
			"���þ� : ");
		scanf("%d", &bating);
		puts("");

		printf("%d���� �����߽��ϴ�.\n", bating);
		printf("�����Ϸ��� �ƹ� Ű�� �����ּ���.\n");
		printf("���߷��� ENTERŰ�� �����ּ���.\n");
		getch();	//Ű�� �Է¹��� 
		goroxy12(1, 7);
		printf(" |");
		do {
			Sleep(80);
			random = (rand() % 3);
			slot[0] = random;
			goroxy12(3, 7);// ù��° ���� ��ġ 
			printf(" %d |", slot[0]);

			random = (rand() % 3);
			slot[1] = random;
			goroxy12(7, 7);// �ι�° ���� ��ġ 
			printf(" %d |", slot[1]);

			random = (rand() % 3);
			slot[2] = random;
			goroxy12(11, 7);// ����° ���� ��ġ 
			printf(" %d |", slot[2]);
			if (kbhit())
				key = getch();
		} while (key != ENTER);	//ENTER�� ġ�� �������� ������ ���ѷ����� ���ư� 

		printf("\n\n");


		if (slot[0] == slot[1] && slot[1] == slot[2])
		{
			switch (slot[i])
			{
			case 0:
				bating *= 2;
				printf("�ڡ١�����̡ڡ١�\n");
				printf("���ñ��� 2�踦 ��� %d���� �Ǿ����ϴ�.\n", bating);	//0,0,0���� �¾��� �� ���þ� 2�� 
				break;
			case 1:
				bating *= 3;
				printf("�ڡ١�����̡ڡ١�\n");
				printf("���ñ��� 3�踦 ��� %d���� �Ǿ����ϴ�.\n", bating);	//1,1,1���� �¾��� �� ���þ� 3�� 
				break;
			case 2:
				bating *= 5;
				printf("�ڡ١�����̡ڡ١�\n");
				printf("���ñ��� 5�踦 ��� %d���� �Ǿ����ϴ�.\n", bating);	//2,2,2���� �¾��� �� ���þ� 5�� 
				break;
			}
		}
		else
		{
			printf("��! ���� ��ȸ��..\n");	//���� �ʾ����� ��� 
		}


		printf("�ٽ� �����Ϸ��� �ƹ�Ű��  �����ּ���.\n");
		printf("�������� ESC�� �����ּ���.\n");
		key = getch();
		system("cls");

	} while (key != 27);

	return 0;
}
