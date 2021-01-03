#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "game.h"
#pragma warning(disable:4996)
void gotoxy4(int x, int y);
void nonc(void);
void roadmap(void);
void roadcloud(void);
void score4(void);
void mymisile(void);
void mypmisile(void);
void rain(void);
void prain(void);
void movement(char key);
void puser(void);
void clean(void);
void start4(void);
void quit(void);
void success(void);
void die(void);
int point = 0;//�ı��� ���� �� 
int cloud[40] = { 1,0,1,0,1,0,1,0,1,0,  1,0,1,0,1,0,1,0,1,0,  1,0,1,0,1,0,1,0,1,0,  1,0,1,0,1,0,1,0,1,0 };//���� ��ġ 
int count4 = 0;//��� ������ üũ 
int px = 31;	//�÷��̾� x ��ǥ
int py = 24;  //�÷��̾� y ��ǥ
int mybx = 0;//�� �Ѿ� x��ǥ 
int myby = 0;//�� �Ѿ� y��ǥ 
int ry = 5;//�� y��ǥ 
int over = 0;//�׾����� ���� 
int speed = 40;//���� ���� �ӵ� 

void gotoxy4(int x, int y) {                         //��ǥ�̵��Լ� 
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void nonc(void) {                                     //Ŀ�� ����� �Լ� 
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);
}

void roadmap(void) {                               //�ʶ��� �Լ� 
	int x, y;
	for (y = 1; y<26; y++) {
		for (x = 1; x<50; x += 2) {
			gotoxy4(1, y);
			printf("��");
			gotoxy4(49, y);
			printf("��");
			gotoxy4(x, 1);
			printf("��");
			gotoxy4(x, 25);
			printf("��");
		}
	}
}

void roadcloud(void) {                             //���� ���� �Լ� 
	int x;
	for (x = 5; x<45; x += 2) {
		gotoxy4(x, 4);
		printf("��");
	}
}

void score4(void) {                                 //���� ���� �Լ� 
	gotoxy4(55, 4);
	printf("���� ���� ����Ʈ : %d", point);
	gotoxy4(55, 7);
	printf("�̻��� �߻� Ƚ�� : %d", count4);
}
void mymisile(void) {            //���� �̻��� ������ �Լ� 
	myby--;
	if (myby == 3 && cloud[mybx - 5] == 1) {//�浹 �˻�
		cloud[mybx - 5] = 0;
		point += 10;
		gotoxy4(mybx, myby + 1);
		printf("  ");
		mybx = 0;
		myby = 0;
		speed--;
	}

	else if (myby<4) {		//�浹 �˻�
		gotoxy4(mybx, myby + 1);
		printf("  ");
		myby = 0;
	}
}

void mypmisile(void) {           //���� �̻��� ��� �Լ� 
	if (myby>3) {
		gotoxy4(mybx, myby);
		printf("��");
		gotoxy4(mybx, myby + 1);
		printf("  ");
	}
}

void rain(void) {             //���� ������ �Լ� 
	int i;
	ry++;

	for (i = 0; i<40; i += 2) {
		if (ry == myby&&mybx == (i + 5)) {
			cloud[i] = 0;
		}
		if (ry == 24) {
			if (cloud[px - 5] == 1) { //��� �÷��̾� �浹�˻�
				over = 1;
			}
			gotoxy4(i + 5, ry);
			printf("  ");
			ry = 6;
		}
	}
}

void prain(void) {            //�� ��� �Լ� 
	int i;
	for (i = 0; i<40; i += 2) {
		if (cloud[i] == 1) {
			{	//���� �迭�� ���� ������ �� ���
				gotoxy4(i + 5, ry);
				printf("��"); }
			gotoxy4(i + 5, ry - 1);
			printf("  ");
		}

		else {				//�� ������ ���� ���
			gotoxy4(i + 5, ry);
			printf("  ");
		}
	}
}

void movement(char key) {//Ű �޾Ƽ� �ൿ  
	gotoxy4(px, py);
	printf("  ");
	switch (key) {
	case 75:		//���� ����Ű               
		px = px - 2;
		if (px<3)	//�浹 �˻�
			px = 3;
		break;
	case 77:		//������ ����Ű
		px = px + 2;
		if (px>47)	//�浹 �˻�
			px = 47;
		break;
	case 32:		//�����̽� ��
		count4++;
		mybx = px;	//�÷��̾��� �ٷ� ��
		myby = py - 1;  //��ǥ���� �̻��� ������ ����
		break;
	default:
		break;
	}
}

void puser(void) {                                     //���� ��ġ ��� 
	gotoxy4(px, py);
	printf("��");
}

void clean(void) {
	int i;
	for (i = 5; i<45; i++) {
		gotoxy4(i, 23);
		printf("  ");
	}
}

void start4(void) {                                     //���� ȭ�� �Լ� 
	roadmap();
	roadcloud();
	gotoxy4(7, 6);
	printf("������ ����Ʈ ��!");
	gotoxy4(7, 8);
	printf("������ ������ �帳�ϴ� ��.��");
	gotoxy4(7, 10);
	printf("�׳డ ����� ����,");
	gotoxy4(7, 12);
	printf("�ϴ��� û���ϼ���!");
	gotoxy4(7, 18);
	printf("�ƹ� Ű�� �Է��ϸ� ������ ���۵˴ϴ�.");
	while (1) {
		if (kbhit())
			break;
	}
	system("cls");
}

void quit(void) {                                     //���� ȭ�� �Լ� 
	system("cls");
	roadmap();
	gotoxy4(10, 13);
	printf("���� ����! ���� ���ھ� : %d\n\n", point - count4);
	gotoxy4(1, 27);
	system("pause");
}

void success(void) {                                   //���� ȭ�� �Լ� 
	system("cls");
	gotoxy4(32, 15);
	printf("�� �� �� !!!!");
	Sleep(1000);
	system("cls");
	roadmap();
	gotoxy4(7, 6);
	printf("�ϴ��� ������!");
	gotoxy4(7, 8);
	printf("�޻��� �����մϴ� ^___^");
	gotoxy4(7, 10);
	printf("�׳డ �Ͼ�� ���� �ϴ��� û���߱���.");
	gotoxy4(7, 12);
	printf("����Ʈ�� �������� ���Դϴ�!");
	gotoxy4(7, 18);
	printf("����� ������ : %d��!", point - count4);
	gotoxy4(1, 27);
	system("pause");
}

void die(void) {                             //���� ȭ�� �Լ� 
	system("cls");
	gotoxy4(32, 15);
	printf("�� �� �� !!!!");
	Sleep(1000);
	system("cls");
	roadmap();
	roadcloud();
	gotoxy4(7, 6);
	printf("��, �̷�!");
	gotoxy4(7, 8);
	printf("�� �¾� ���� ��������...");
	gotoxy4(7, 10);
	printf("�׳ฦ �����⿣ �����Դϴ�.");
	gotoxy4(7, 12);
	printf("����Ʈ�� �����߽��ϴ�.");
	gotoxy4(7, 18);
	printf("����� ������ : %d��!", point - count4);
	gotoxy4(1, 27);
	system("pause");
}

int main4(void) {
	char key; //�Է� Ű 
	system("mode con: cols=80 lines=32");
	nonc();          //Ŀ�� �Ⱥ��̰��ϱ�
	start4();	     //����ȭ�� ����
	roadmap();		 //�� �׸���
	roadcloud();	 //���� �׸���	

	do {
		if (kbhit())		//Ű�� ���ȴ��� �˻�		
		{
			key = getch();
			movement(key);
		} //�Էµ� Ű���� �Լ���

		else {
			puser();	//�÷��̾� ��ġ ���
			if (point >= 30 && point<200) {
				rain();		//�� ��ĭ�� ����
				prain();
			}	//�� ���
			mymisile();		//���� �̻��� ��ĭ����
			mypmisile();	//���� �̻��� ���
			clean();

			score4();
		}		//���� ���� �˻��
		if (point == 200)
			break;
		if (over == 1)
			break;
		Sleep(speed);	//���� ���� �ӵ� ��Ʈ�� 
	} while (key != 27);		//ESCŰ ������ ����

	if (point == 200)
		success();
	if (over == 1)			//���� ����â ����
		die();
	if (key == 27)
		quit();
	return 0;
}
