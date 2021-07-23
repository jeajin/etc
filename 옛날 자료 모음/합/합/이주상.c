void gotoxy15(int x, int y);
void mainscreen(char key);
void input_dol(int(*map)[45], int *color, int *x, int *y);
void makemap();
void move151(char key, int *x, int *y);
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "game.h" 
#pragma warning(disable:4996)
void move152(char key, int *x, int *y);
void where_dol(int(*map)[45], int *color, int *x, int *y);
void remap(int *x, int *y);
void put_dol(int(*map)[45]);
int five_dol(int(*map)[45]);

void makemap() {
	int i, j;
	printf("��");  		// 1.1
	for (i = 1; i<18; i++)
		printf("��");   // 2.1~18.1
	printf("��\n");     // 19.1				  
	for (i = 1; i<18; i++)
	{
		printf("��");     // 1.2~1.18
		for (j = 1; j<18; j++)
			printf("��");  // 2.2~18.18
		printf("��\n");  // 19.2~19.18
	}
	printf("��");   // 1.19
	for (i = 1; i<18; i++)
		printf("��");   // 2.19~18.19
	printf("��");   // 19.19
}

void remap(int *x, int *y) {
	gotoxy15(*x, *y);
	if (*x == 1 && *y == 1)
		printf("��"); 				// 1.1
	else if (*x == 37 && *y == 1)
		printf("��\n"); 		    // 37.1	
	else if (*x == 1 && *y == 19)
		printf("��");               // 1.37
	else if (*x == 37 && *y == 19)
		printf("��");  			    // 37.37
	else if (*x >= 3 && *x <= 35 && *y == 1)
		printf("��"); 				// 2.1~35.1
	else if (*x >= 3 && *x <= 35 && *y >= 2 && *y <= 18)
		printf("��"); 				// 2.2~35.18
	else if (*x == 1 && *y >= 2 && *y <= 18)
		printf("��");    		    // 1.2~1.35
	else if (*x == 37 && *y >= 2 && *y <= 18)
		printf("��\n"); 		    // 37.2~37.18
	else if (*x >= 3 && *x <= 35 && *y == 19)
		printf("��");   			// 2.19~35.19
}
void mainscreen(char key) {
	int i;
	gotoxy15(27, 7);
	for (i = 0; i<20; i++)
		printf("=");
	for (i = 8; i<11; i++)
	{
		gotoxy15(26, i);
		printf("��");
	}
	gotoxy15(34, 9);
	printf("��   ��");
	gotoxy15(27, 11);
	for (i = 0; i<20; i++)
		printf("=");
	for (i = 8; i<11; i++)
	{
		gotoxy15(46, i);
		printf("��");
	}
	gotoxy15(27, 15);
	printf("�� ���� �����ϱ� ");

	key = getch();
	if (key == 13)
		system("cls");
	else
		mainscreen(key);
}

void gotoxy15(int x, int y)
{
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void where_dol(int(*map)[45], int *color, int *x, int *y) {
	if (map[*y][*x] == 0)
	{
		if (*color % 2 == 1)
		{
			gotoxy15(*x, *y);
			printf("��");
		}
		else {
			gotoxy15(*x, *y);
			printf("��");
		}
	}
}

void move151(char key, int *x, int *y) {

	switch (key) {
	case 72:
		*y = *y - 1;
		if (*y<1) *y = 1;
		break;
	case 75:
		*x = *x - 2;
		if (*x<1) *x = 1;
		break;
	case 77:
		*x = *x + 2;
		if (*x>37) *x = 37;
		break;
	case 80:
		*y = *y + 1;
		if (*y>19) *y = 19;
		break;
	default:
		break;
	}
}

void move152(char key, int *x, int *y) {

	switch (key) {
	case 56:
		*y = *y - 1;
		if (*y<1) *y = 1;
		break;
	case 52:
		*x = *x - 2;
		if (*x<1) *x = 1;
		break;
	case 54:
		*x = *x + 2;
		if (*x>37) *x = 37;
		break;
	case 50:
		*y = *y + 1;
		if (*y>19) *y = 19;
		break;
	default:
		break;
	}
}


void input_dol(int(*map)[45], int *color, int *x, int *y) {
	if (map[*y][*x] == 0)
	{
		if (*color % 2 == 1)
		{
			gotoxy15(*x, *y);
			printf("��");
			map[*y][*x] = 1;
		}
		else if (*color % 2 == 0) {
			gotoxy15(*x, *y);
			printf("��");
			map[*y][*x] = 2;
		}
		(*color)++;
	}
}

void put_dol(int(*map)[45]) {
	int i, j;
	for (i = 1; i<20; i++)
	{
		for (j = 1; j<20; j++)
		{
			if (map[j][(i * 2) - 1] == 1)
			{
				gotoxy15((i * 2) - 1, j);
				printf("��");
			}
			else if (map[j][(i * 2) - 1] == 2)
			{
				gotoxy15((i * 2) - 1, j);
				printf("��");
			}
		}
	}
}

int five_dol(int(*map)[45]) {
	int i, j;
	for (i = 1; i<20; i++)
	{
		for (j = 1; j<20; j++)
		{
			if ((map[i][(j * 2) - 1] == 1 && map[i][(j * 2) + 1] == 1 && map[i][(j * 2) + 3] == 1 && map[i][(j * 2) + 5] == 1 && map[i][(j * 2) + 7] == 1) ||   //���� 
				(map[i][(j * 2) - 1] == 1 && map[i + 1][(j * 2) - 1] == 1 && map[i + 2][(j * 2) - 1] == 1 && map[i + 3][(j * 2) - 1] == 1 && map[i + 4][(j * 2) - 1] == 1) ||  //����
				(map[i][(j * 2) - 1] == 1 && map[i + 1][(j * 2) - 3] == 1 && map[i + 2][(j * 2) - 5] == 1 && map[i + 3][(j * 2) - 7] == 1 && map[i + 4][(j * 2) - 9] == 1) ||  //�»�밢
				(map[i][(j * 2) - 1] == 1 && map[i + 1][(j * 2) + 1] == 1 && map[i + 2][(j * 2) + 3] == 1 && map[i + 3][(j * 2) + 5] == 1 && map[i + 4][(j * 2) + 7] == 1))   //���ϴ밢
			{
				return 1;
			}
			else if ((map[i][(j * 2) - 1] == 2 && map[i][(j * 2) + 1] == 2 && map[i][(j * 2) + 3] == 2 && map[i][(j * 2) + 5] == 2 && map[i][(j * 2) + 7] == 2) ||
				(map[i][(j * 2) - 1] == 2 && map[i + 1][(j * 2) - 1] == 2 && map[i + 2][(j * 2) - 1] == 2 && map[i + 3][(j * 2) - 1] == 2 && map[i + 4][(j * 2) - 1] == 2) ||
				(map[i][(j * 2) - 1] == 2 && map[i + 1][(j * 2) - 3] == 2 && map[i + 2][(j * 2) - 5] == 2 && map[i + 3][(j * 2) - 7] == 2 && map[i + 4][(j * 2) - 9] == 2) ||
				(map[i][(j * 2) - 1] == 2 && map[i + 1][(j * 2) + 1] == 2 && map[i + 2][(j * 2) + 3] == 2 && map[i + 3][(j * 2) + 5] == 2 && map[i + 4][(j * 2) + 7] == 2))
			{
				return 2;
			}
		}
	}
}

int main15() {
	int map[25][45] = { 0 };
	char key = 0;
	int x = 19, y = 10, color = 1;
	int i, j;
	mainscreen(key);  // ����ȭ�� ȣ�� 

	for (; ; )
	{
		if (key == 13)
		{
		}color = 1;
		makemap();  // 1. �ٵ��� ����� 
		gotoxy15(x, y);
		printf("��");//�� �� 
		for (i = 0; i<25; i++)
		{
			for (j = 0; j<45; j++)
				map[i][j] = 0;
		}
		do {
			gotoxy15(1, 21);
			printf("------------����Ű-------------\n");
			printf("�� �÷��̾�� ����Ű �����¿�� ���� �����̰�,�����̽��� ������ ���� �����ϴ�.\n���÷��̾�� Ű��������� 8(��),2(��),4(��),6(��) �� ���� �����̰� ����Ű�� ���� �����ϴ�.");

			key = getch();  //    ��,��,��,��,�����̽��� �Է� 
			remap(&x, &y);      // 2. ������ �ٵ��� �ٽ� �׸��� 
			if (color % 2 == 1)
			{
				if (key == 32)  input_dol(map, &color, &x, &y);  // 3.  �����̽� ������ ��� �Է�_dol �Լ��� �̵� 
				else  move151(key, &x, &y);   //  ����Ű ������ ��� �����Լ��� �̵�  
				where_dol(map, &color, &x, &y);       // 4.  Ŀ���� �� ����� Ÿ���� �Լ� 
				put_dol(map);         // 5.  ���� ���Ҵ� �ڸ��� ǥ���ϴ� �Լ� 
				if (five_dol(map) == 1)  // 6.  ���� �������� 5�� ���Ҵ��� �˻��ϴ� five_dol �Լ��� ���ϰ��� Ȯ��. 
										 //     1�̳� 2�� ����������� do~while�� Ż�� 	
				{
					gotoxy15(2, 25);
					printf("���� �¸� !!!\n");
					Sleep(1000);
					break;
				}
				else if (five_dol(map) == 2)
				{
					gotoxy15(2, 25);
					printf("���� �¸� !!!\n");
					Sleep(1000);
					break;
				}
			}
			else if (color % 2 == 0)
			{
				if (key == 13)  input_dol(map, &color, &x, &y);
				else  move152(key, &x, &y);
				where_dol(map, &color, &x, &y);
				put_dol(map);
				if (five_dol(map) == 1)
				{
					gotoxy15(2, 25);
					printf("���� �¸� !!!\n");
					Sleep(1000);
					break;
				}
				else if (five_dol(map) == 2)
				{
					gotoxy15(2, 25);
					printf("���� �¸� !!!\n");
					Sleep(1000);
					break;
				}
			}
		} while (key != 27);

		system("cls");
		gotoxy15(5, 10);
		printf("�ٽ� �÷��� �Ͻðڽ��ϱ�?\n    (���� : �ٽý���, esc : ����)");
		key = getch();
		for (; ; )
		{
			if (key == 13)
			{
				system("cls");
				mainscreen(key);
				break;
			}
			else if (key == 27)
			{
				return 0;
			}
			else
				key = getch();
		}



	}
	return 0;
}

// ���÷��̾� Ű����� ���÷��̾� Ű���� �и��ؼ� ó���غ��� 
