#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include "game.h"

#pragma warning(disable:4996)

void gt(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
ddd()
{
	
	gt(3, 0);
	printf("Enter�� space�� �����ø� ������ �ʴϴ�.");
	gt(3, 2);
	printf(" 1�� ����ã��_____________����� ");
	gt(3, 4);
	printf(" 2�� invader _____________���ΰ� ");
	gt(3, 6);
	printf(" 3�� ���۸�����___________������ ");
	gt(3, 8);
	printf(" 4�� �ϴ�û�Ұ���_________����ȯ");
	gt(3, 10);
	printf(" 5�� �߱�����_____________��ȣ�� ");
	gt(3, 12);
	printf(" 6�� ���� ��ã�� ����___����ȣ");
	gt(3, 14);
	printf(" 7�� ������_______________��¹�");
	gt(3, 16);
	printf(" 8�� ����ã��___________���켺��");
	gt(3, 18);
	printf(" 9�� �����_______________������ ");
	gt(3, 20);
	printf("10�� ���ð���_____________�ȼ���");
	gt(3, 22);
	printf("11�� ����_________________��ȿ�� ");
	gt(3, 24);
	printf("12�� loop slot____________�����");
	gt(3, 26);
	printf("13�� ����ã��_____________������");
	gt(3, 28);
	printf("14�� �Ѿ˷ΰ��ߺ����İ���_�̻�� ");
	gt(3, 30);
	printf("15�� ����_________________���ֻ�");
	gt(3, 32);
	printf("16�� ����_________________�ӱ���");
	gt(3, 34);
	printf("17�� ��ã��_______________�ַ� ");
	gt(3, 36);
	printf("18�� �����ϱ�_____________������ ");
	gt(3, 38);
	printf("19�� ����_________________ȫ����");
}
int main()
{
	int i = 2, kb = 0;
	ddd();
	system("mode con cols=80 lines=41");
	gt(2, 2);
	printf("*");
	while(1)
	{
		
		ddd();
		kb = getch();
			if (kb == 72)
			{
				gt(2, i);
				printf(" ");
				i -= 2;
			}
			else if (kb == 80)
			{
				gt(2, i);
				printf(" ");
				i += 2;
			}
			if (i > 38)
			{
				i = i % 38 ;
			}
			else if (i < 2)
			{
				i += 38;
			}
			
		gt(2, i);
		printf("*");
		if (kb == 32||kb==13)
		{
			system("cls");
			if (i == 2)
			{
				main1();
			}
			else if (i ==4 )
			{
				main2();
			}
			else if (i ==6 )
			{
				main3();
			}
			else if (i ==8 )
			{
				main4();
			}
			else if (i == 10)
			{
				main5();
			}
			else if (i ==12 )
			{
				main6();
			}
			else if (i == 14)
			{
				main7();
			}
			else if (i ==16 )
			{
				main8();
			}
			else if (i == 18)
			{
				main9(); 
			}
			else if (i ==20 )
			{
				main10();
			}
			else if (i == 22)
			{
				main11();
			}
			else if (i == 24)
			{
				main12();
			}
			else if (i == 26)
			{
				main13();
			}
			else if (i == 28)
			{
				main14();
			}
			else if (i == 30)
			{
				main15();
			}
			else if (i == 32)
			{
				main16();
			}
			else if (i == 34)
			{
				main17();
			}
			else if (i ==36 )
			{
				main18();
			}
			else if (i == 38)
			{
				main19();
			}
			system("mode con cols=80 lines=41");
			system("cls");
		}
	}
}
